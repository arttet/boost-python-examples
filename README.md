# boost-python-examples

[![Build Status](https://travis-ci.org/arttet/boost-python-examples.svg?branch=master)](https://travis-ci.org/arttet/boost-python-examples)
[![Build status](https://ci.appveyor.com/api/projects/status/p9kv4kq0obj1x87q?svg=true)](https://ci.appveyor.com/project/arttet/boost-python-examples)

Some examples for the use of boost::python

## Installation

You can build and run this examples directly on your system.

You need the following libraries:
<a href="https://www.boost.org/" target="_blank">Boost</a>,
<a href="https://www.python.org/" target="_blank">Python</a> (v3 minimum).

* Install dependencies, e.g. on Ubuntu:
```sh
sudo apt-get install build-essential cmake libboost-dev libboost-python-dev python3
```

* Download the source from GitHub with:

```sh
git clone --recursive https://github.com/arttet/boost-python-examples
```

Alternatively, if you already have the existing source tree use:
```sh
git clone https://github.com/arttet/boost-python-examples
git submodule update --init
```

* Run the following commands:

```sh
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ../
cmake --build .
ctest
```
