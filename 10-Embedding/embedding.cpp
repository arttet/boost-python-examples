#include "my_module.hpp"

#include <boost/python/dict.hpp>
#include <boost/python/exec.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/import.hpp>

#include <iostream>

namespace py = boost::python;

int main()
{
    try {
        Py_Initialize();
        py::object const main_module = py::import("__main__");
        py::dict global = py::extract<py::dict>(main_module.attr("__dict__"));
        py::object const my_module = py::import(MODULE_NAME);

        py::exec("print('Hello, world')", global);
        py::exec("print('.'.join(['1','2','3']))", global);

        py::exec("import random", global);
        py::object const rand = py::eval("random.random()", global);
        std::cout << py::extract<double>(rand) << std::endl;

        global["precreated_object"] = base_t("created on C++ side");
        py::object const none = py::exec_file(PY_FILE, global, global);
    } catch (py::error_already_set const &) {
        PyErr_PrintEx(0);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
