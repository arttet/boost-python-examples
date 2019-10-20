#include <boost/python/class.hpp>
#include <boost/python/module.hpp>

#include <sstream>
#include <string>
#include <utility>

namespace py = boost::python;

namespace
{
    struct ctor_t final
    {
        explicit ctor_t(std::string msg)
            : message(std::move(msg))
        {
        }

        explicit ctor_t(double const x, double const y)
        {
            std::stringstream os;
            os << x << ':' << y << std::ends;
            set(os.str());
        }

        void set(std::string msg)
        {
            message = std::move(msg);
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
    py::class_<ctor_t>("Ctor", py::init<std::string>())
        .def(py::init<double, double>())
        .def("greet", &ctor_t::greet)
        .def("set", &ctor_t::set)
    ;
}
// clang-format on
