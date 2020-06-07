#include <CppUTest/CommandLineTestRunner.h>
#include "canvas.cpp"
#include "intersection.cpp"
#include "matrix.cpp"
#include "pointlight.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "transformation.cpp"
#include "tuple.cpp"

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}