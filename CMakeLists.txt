cmake_minimum_required(VERSION 3.3)
project(hexapawn CXX)
include(.ipd/cmake/CMakeLists.txt)

add_cxx_test(model_test
        test/model_test.cxx
        src/Model.cxx)

add_cxx_test(userinterface_test
        test/userinterface_test.cxx
        src/UserInterface.cxx
        src/Model.cxx)

add_cxx_program(hexapawn
        src/hexapawn.cxx
        src/Model.cxx
        src/UserInterface.cxx)
