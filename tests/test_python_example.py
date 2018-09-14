import numpy as np
import python_example as m
import pytest


def test_version():
    assert m.__version__ == "0.0.1"


def test_add_1_2():
    assert m.add(1, 2) == 3


def test_subtract_1_2():
    assert m.subtract(1, 2) == -1


def test_ndarray_args():
    data = np.array([range(10)])
    assert m.ndarray_sum(data) == sum(range(10))


def test_runtime_error():
    with pytest.raises(RuntimeError):
        m.runtime_error()


def test_range_error():
    with pytest.raises(ValueError):
        m.range_error()


def test_return_ndarray():
    a = m.get_ndarray(10, 5.0)
    assert isinstance(a, np.ndarray)
    np.testing.assert_allclose(a, 5.0)
    assert len(a) == 10


def test_get_class_with_vector_results():
    n = 10
    t = 4.3
    h = 88.3
    results = m.get_vector_results(n, t, h)
    assert len(results.temperature) == n
    np.testing.assert_allclose(results.temperature, t)
    assert len(results.humidity) == n
    np.testing.assert_allclose(results.humidity, h)
