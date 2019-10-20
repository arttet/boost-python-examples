#include <boost/python/class.hpp>
#include <boost/python/module.hpp>

#include <boost/math/constants/constants.hpp>

#include <string>
#include <utility>

namespace py = boost::python;

namespace
{
    auto constexpr pi = boost::math::constants::pi<double>();

    struct some_class_t final
    {
        explicit some_class_t(std::string n)
            : name(std::move(n))
            , number_(0.0)
        {
        }

        void set_number(double const n)
        {
            number_ = n > pi ? -1 : n;
        }

        double get_number() const
        {
            return number_;
        }

        std::string name;

    private:
        double number_;
    };
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<some_class_t>("SomeClass", py::init<std::string>())
      .def_readwrite("name", &some_class_t::name)
      .add_property("number", &some_class_t::get_number, &some_class_t::set_number)
      ;
}
// clang-format on
