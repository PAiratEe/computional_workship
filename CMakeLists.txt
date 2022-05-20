cmake_minimum_required(VERSION 3.17)
project(computional_workship)

set(CMAKE_CXX_STANDARD 20)

add_executable(computional_workship main.cpp tasks.h nonlinear_equation.h algebraic_interpolation.h tasks.cpp nonlinear_equation.cpp algebraic_interpolation.cpp reverse_interpolation.cpp reverse_interpolation.h lib.h numerical_differentiation.h numerical_differentiation.cpp approximate_calculation.h approximate_calculation.cpp quadrature_formulas.cpp quadrature_formulas.h)