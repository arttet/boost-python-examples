#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/operators.hpp>

#include <sstream>
#include <string>

namespace py = boost::python;

namespace
{
    struct number_like_t final
    {
        explicit number_like_t(int const n = 0)
            : n_(n)
        {
        }

        number_like_t & operator+=(int const i)
        {
            n_ += i;
            return *this;
        }

        std::string str() const
        {
            std::stringstream s;
            s << n_;
            return s.str();
        }

        std::string repr() const
        {
            std::stringstream s;
            s << "NumberLike(" << n_ << ")";
            return s.str();
        }

    private:
        int n_;
    };

    number_like_t operator+(number_like_t n, int const i)
    {
        n += i;
        return n;
    }
}

// clang-format off
BOOST_PYTHON_MODULE(MODULE_NAME) // NOLINT
{
   py::class_<number_like_t>("NumberLike")
      .def(py::init<py::optional<int>>())
      .def(py::self + int())

      .def("__str__", &number_like_t::str)
      .def("__repr__", &number_like_t::repr)
      ;
}
// clang-format on
