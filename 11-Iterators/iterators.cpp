#include <boost/python/class.hpp>
#include <boost/python/iterator.hpp>
#include <boost/python/module.hpp>

#include <vector>

namespace py = boost::python;

namespace
{
    struct example_t final
    {
        explicit example_t() = default;

        void add(std::string const & s)
        {
            strings_.push_back(s);
        }

        std::vector<std::string>::iterator begin()
        {
            return strings_.begin();
        }

        std::vector<std::string>::iterator end()
        {
            return strings_.end();
        }

    private:
        std::vector<std::string> strings_;
    };
}

BOOST_PYTHON_MODULE(iterators) // NOLINT
{
    py::class_<example_t>("Example")
        .def("strings", py::range(&example_t::begin, &example_t::end))
        .def("add", &example_t::add);
}
