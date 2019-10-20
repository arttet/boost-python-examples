#include <boost/python/class.hpp>
#include <boost/python/def.hpp>
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

    struct base_wrap_t final
        : base_t
        , py::wrapper<base_t>
    {
        std::string name() const override
        {
            if (py::override const name = get_override("name"))
                return name();

            return base_t::name();
        }

        std::string default_name() const
        {
            return base_t::name();
        }

        ~base_wrap_t() override = default;
    };

    void identify(base_t const * const b)
    {
        std::cout << b->name() << " called." << std::endl;
    }
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<base_wrap_t, boost::noncopyable>("Base")
      .def("name", &base_t::name, &base_wrap_t::default_name)
      ;

   py::def("identify", identify);
}
// clang-format off
