import pytest
from functions import addition, dict_value

# def test_addition():
#     assert addition(5,4) == 9
#     assert addition(0,0) == 0

# @pytest.fixture
# def addition_data():
#     data = [
#         [5,4,9],
#         [0,0,0],
#         [7,0,7],
#     ]
#     return data

# def test_addition(addition_data):
#     x = addition_data

#     for i in range(len(x)):
#         assert addition(x[i][0],x[i][1]) == x[i][2]


@pytest.mark.parametrize("x,y,z", [(5,4,9), (0,0,0), (7,0,7)])
def test_addition(x, y, z):
    assert addition(x,y) == z


@pytest.mark.skip
def test_dict_value():
    assert dict_value("milk") == "white"
    assert dict_value("sky") == "blue"

    assert dict_value("") == "unknown"
    assert dict_value("wall") == "unknown"



