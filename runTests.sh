#!/bin/bash

cmake CMakeLists.txt
make
cd tests && ./tests_run