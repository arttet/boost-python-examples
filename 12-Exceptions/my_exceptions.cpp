#include "boost/python.hpp"

#include <exception>

namespace py = boost::python;

namespace
{
    struct OutOfSteakException final : std::exception
    {
        char const * what() const noexcept override
        {
            return exception::what();
        }
    };

    void translate_exception(OutOfSteakException const &)
    {
        PyErr_SetString(PyExc_UserWarning, "The meat is gone, go for the cheese....");
    }

    void some_function()
    {
        throw OutOfSteakException();
    }
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
    py::register_exception_translator<OutOfSteakException>(translate_exception);

    py::def("some_function", &some_function);
}
// clang-format on
