//
// Created by mp on 11/9/20.
//

#include "shapes.h"
#include <math.h>


Rectangle::Rectangle(double height, double width) {
    this->_height = height;
    this->_width = width;
}

double Rectangle::area() {
    return this->_height * this->_width;
}

double Rectangle::perimeter() {
    return 2 * this->_height + 2 * this->_width;
}

double Rectangle::height() {
    return this->_height;
}

double Rectangle::width() {
    return this->_width;
}

void Rectangle::rotate() {
    double t = this->_width;
    this->_width = this->_height;
    this->_height = t;
}

Square::Square(double size) : Rectangle(size, size) {}

double Circle::area() {
    return pow(this->_radius, 2) * M_PI;
}

double Circle::perimeter() {
    return 2 * this->_radius * M_PI;
}

double Circle::height() {
    return 2 * this->_radius;
}

double Circle::width() {
    return 2 * this->_radius;
}

void Circle::rotate() {
}

Circle::Circle(double radius) {
    this->_radius = radius;
}
