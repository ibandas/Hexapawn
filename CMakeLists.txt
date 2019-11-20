cmake_minimum_required(VERSION 3.3)
project(hexapawn CXX)
include(.ipd/cmake/CMakeLists.txt)

add_cxx_test(model_test
        test/model_test.cxx
        src/Model.cxx
        src/Model.hxx
        src/UserInterface.cxx
        src/UserInterface.hxx)

add_cxx_program(hexapawn
        src/hexapawn.cxx
        src/Model.cxx
        src/UserInterface.cxx)
