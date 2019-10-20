#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/overloads.hpp>

#include <sstream>
#include <utility>

namespace py = boost::python;

namespace
{
    struct example_t final
    {
        explicit example_t() = default;

        std::string str() const
        {
            return str_;
        }

        void do_it()
        {
            str_ = "void";
        }

        std::string do_it(size_t const i)
        {
            std::stringstream s;
            s << i;
            str_ = s.str();
            return str_;
        }

        void do_it(std::string s)
        {
            str_ = std::move(s);
        }

        size_t make_it(std::string const & s, size_t const n = 1, std::string const & t = "")
        {
            std::stringstream u;
            for (size_t i = 0; i < n; ++i)
                u << s;

            str_ = u.str() + t;
            return n + (!t.empty() ? 1 : 0);
        }

    private:
        std::string str_;
    };
}

namespace
{
    BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(make_it_overloads, make_it, 1, 3)
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   void        (example_t::*d1)()            = &example_t::do_it;
   std::string (example_t::*d2)(size_t)      = &example_t::do_it;
   void        (example_t::*d3)(std::string) = &example_t::do_it;

   py::class_<example_t>("Example")
      .def("__str__", &example_t::str)
      .def("do_it", d1)
      .def("do_it", d2)
      .def("do_it", d3)
      .def("make_it", &example_t::make_it, make_it_overloads())
      ;
}
// clang-format on
