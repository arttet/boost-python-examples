from my_extension import Base


class PythonDerivedOne(Base):
    def __init__(self):
        Base.__init__(self, "PythonDerivedOne")


class PythonDerivedTwo(Base):
    def __init__(self):
        Base.__init__(self, "PythonDerivedTwo")
