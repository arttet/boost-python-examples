import inheritance

b = inheritance.Base()
d = inheritance.Derived()

inheritance.fb(b)
inheritance.fb(d)

# not possible, fd is only for Derived objects
#inheritance.fd(b)
inheritance.fd(d)

x = inheritance.factory()
inheritance.fb(x)

#  Base called.
#  Derived called.
#  Traceback (most recent call last):
#    File "py_inheritance.py", line 10, in <module>
#      inheritance.fd(b)
#  Boost.Python.ArgumentError: Python argument types in
#      inheritance.fd(Base)
#  did not match C++ signature:
#      fd(struct `anonymous namespace'::derived_t const * __ptr64)
