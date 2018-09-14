#include <exception>
#include <numeric>
#include <vector>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void runtime_error()
{
    throw std::runtime_error("C++ failure");
}

void range_error()
{
    throw std::range_error("C++ range error");
}

int add(int i, int j)
{
    return i + j;
}

double ndarray_sum(py::array_t<double> ndarray)
{
    // double ndarray_sum(std::vector<double> &ndarray) {
    // return std::accumulate(ndarray.begin(), ndarray.end(), 0.0);
    auto buf1 = ndarray.request();
    double sum = 0;
    int n = buf1.size;
    for (int i = 0; i < n; i++)
    {
        sum += ((double *)buf1.ptr)[i];
    }
    return sum;
}

py::array_t<double> get_ndarray(int n, double value)
{
    auto result = std::vector<double>(n, value);
    return py::array(result.size(), result.data());
}

PYBIND11_MODULE(python_example, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: python_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("ndarray_sum", &ndarray_sum, R"pbdoc(
        Return the sum of a numpy ndarray.

        Tests functions that accept a numpy array and
        autoconvert to std::vector.
    )pbdoc");

    m.def("runtime_error", &runtime_error);
    m.def("range_error", &range_error);
    m.def("get_ndarray", &get_ndarray);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
