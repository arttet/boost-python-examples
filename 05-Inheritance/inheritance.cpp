#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
#include <boost/python/manage_new_object.hpp>
#include <boost/python/module.hpp>

#include <iostream>
#include <string>

namespace py = boost::python;

namespace
{
    struct base_t
    {
        virtual std::string name() const
        {
            return "Base";
        }

        virtual ~base_t() = default;
    };

    struct derived_t final : base_t
    {
        std::string name() const override
        {
            return "Derived";
        }

        ~derived_t() override = default;
    };

    void fb(base_t const * const b)
    {
        std::cout << b->name() << " called." << std::endl;
    }

    void fd(derived_t const * const d)
    {
        std::cout << "Derived " << d->name() << " called." << std::endl;
    }

    base_t * factory()
    {
        return new derived_t;
    }
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<base_t, boost::noncopyable>("Base")
      .def("name", &base_t::name)
      ;

   py::class_<derived_t, py::bases<base_t>>("Derived")
      ;

   py::def("fb", fb);
   py::def("fd", fd);
   py::def("factory", factory, py::return_value_policy<py::manage_new_object>());
}
// clang-format on
