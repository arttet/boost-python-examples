#include <boost/python/def.hpp>
#include <boost/python/module.hpp>

namespace py = boost::python;

namespace
{
    char const * greet()
    {
        return "Hello, world!";
    }
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
    py::def("greet", greet);
}
// clang-format on
