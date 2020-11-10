//
// Created by mp on 11/9/20.
//

// Shape,Rectangle,Square Circle

#ifndef CPP_02393E_SHAPES_H
#define CPP_02393E_SHAPES_H


class Shape {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual double height() = 0;
    virtual double width() = 0;
    virtual void rotate() = 0;

};

class Rectangle : public Shape {
public:
    Rectangle(double height, double width);

    double area() override;

    double perimeter() override;

    double height() override;

    double width() override;

    void rotate() override;

private:
    double _height;
    double _width;
};

class Square : public Rectangle{
public:
    explicit Square(double size);

};

class Circle : public Shape {
public:
    Circle(double radius);

private:
public:
    double area() override;

    double perimeter() override;

    double height() override;

    double width() override;

    void rotate() override;

private:
    double _radius;
};


#endif //CPP_02393E_SHAPES_H
