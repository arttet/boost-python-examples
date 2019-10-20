#include "my_extension.hpp"

#include <boost/python/class.hpp>
#include <boost/python/module.hpp>

namespace py = boost::python;

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<base_t>("Base", py::init<std::string>())
      .def("__str__", &base_t::name)
      ;
}
// clang-format on
