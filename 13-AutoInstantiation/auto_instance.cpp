#include "my_extension.hpp"

#include <boost/python/dict.hpp>    // NOLINT
#include <boost/python/exec.hpp>    // NOLINT
#include <boost/python/extract.hpp> // NOLINT
#include <boost/python/import.hpp>  // NOLINT

#include <iostream>

namespace py = boost::python;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file.py\n", argv[0]);
        return EXIT_FAILURE;
    }

    char const * const py_file = argv[1];

    try {
        Py_Initialize();

        py::object const main_module = py::import("__main__");
        py::dict const main_namespace = py::extract<py::dict>(main_module.attr("__dict__"));
        py::object const my_extension = py::import(MODULE_NAME); // NOLINT
        py::dict const my_extension_namespace = py::extract<py::dict>(my_extension.attr("__dict__"));

        exec_file(py::str(py_file), main_namespace, main_namespace); // NOLINT
        py::object const py_base_class = my_extension_namespace["Base"];
        auto const base_class = reinterpret_cast<PyTypeObject *>(py_base_class.ptr());

        py::list keys = main_namespace.keys();
        for (py::ssize_t i = 0, len = py::len(keys); i < len; ++i) {
            py::object k = keys[i];
            py::object item = main_namespace[k];
            PyObject * item_ptr = item.ptr();

            if (PyType_Check(item_ptr)) {
                auto const type_obj = reinterpret_cast<PyTypeObject *>(item_ptr);
                if (type_obj != base_class && PyType_IsSubtype(type_obj, base_class) > 0) {
                    py::object obj = item();
                    base_t const & base_obj = py::extract<base_t>(obj);
                    std::cout << base_obj.name() << std::endl;
                }
            }
        }
    } catch (py::error_already_set const &) {
        PyErr_PrintEx(0);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
