import python_example as m

def test_version():
    assert m.__version__ == '0.0.1'

def test_add_1_2():
    assert m.add(1, 2) == 3

def test_subtract_1_2():
    assert m.subtract(1, 2) == -1
