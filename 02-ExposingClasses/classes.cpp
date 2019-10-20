#include <boost/python/class.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/list.hpp>
#include <boost/python/module.hpp>

#include <sstream>
#include <string>

namespace py = boost::python;

namespace
{
    struct world_t final
    {
        void set(std::string const & msg)
        {
            message = msg;
        }

        void many(py::list const & messages)
        {
            std::stringstream ss;
            for (py::ssize_t i = 0, len = py::len(messages); i < len; ++i) {
                if (i > 0)
                    ss << ", ";

                std::string const s = py::extract<std::string>(messages[i]);
                ss << s;
            }

            message = ss.str();
        }

        std::string greet() const
        {
            return message;
        }

        std::string message;
    };
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<world_t>("World")
      .def("greet", &world_t::greet)
      .def("set", &world_t::set)
      .def("many", &world_t::many)
      ;
};
// clang-format on
