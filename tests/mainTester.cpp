#include <CppUTest/CommandLineTestRunner.h>
#include "tuple.cpp"
#include "matrix.cpp"
#include "canvas.cpp"
#include "intersection.cpp"
#include "material.cpp"
#include "pointlight.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "transformation.cpp"
#include "world.cpp"

#define EPSILON 0.0001

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}