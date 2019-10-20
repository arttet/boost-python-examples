#include <boost/python/class.hpp>
#include <boost/python/manage_new_object.hpp>
#include <boost/python/module.hpp>
#include <boost/python/return_value_policy.hpp>

namespace py = boost::python;

namespace
{
    struct example_t final
    {
        std::string name() const
        {
            return name_;
        }

        static example_t * factory()
        {
            return new example_t("factory");
        }

        static example_t * singleton()
        {
            static example_t instance = example_t("singleton");
            return &instance;
        }

    private:
        explicit example_t(std::string n)
            : name_(std::move(n))
        {
        }

        std::string name_;
    };
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<example_t>("Example", py::no_init)
      .def("__str__", &example_t::name)

      .def("factory", &example_t::factory, py::return_value_policy<py::manage_new_object>()).staticmethod("factory")

      .def("singleton", &example_t::singleton, py::return_value_policy<py::reference_existing_object>()).staticmethod("singleton")
      ;
}
// clang-format on
