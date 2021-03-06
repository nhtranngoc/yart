
#include <CppUTest/CommandLineTestRunner.h>
#include "canvas.cpp"
#include "tuple.cpp"
#include "matrix.cpp"
#include "intersection.cpp"
#include "material.cpp"
#include "pointlight.cpp"
#include "ray.cpp"
#include "sphere.cpp"
#include "transformation.cpp"
#include "world.cpp"
#include "camera.cpp"
#include "shape.cpp"
#include "plane.cpp"
#include "pattern.cpp"
#include "stripe.cpp"
#include "gradient.cpp"
#include "ring.cpp"
#include "checkers.cpp"

int main(int argc, char **argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}