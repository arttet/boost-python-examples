from my_exceptions import some_function

try:
    some_function()
except UserWarning as ex:
    print('Exception {} caught: {}'.format(type(ex), ex))
