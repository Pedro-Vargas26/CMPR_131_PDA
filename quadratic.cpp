
#include <iostream>
#include <cmath>
#include "Quadratic.h"

using namespace std;

Quadratic::Quadratic() : a(0), b(0), c(0) {}

//get a, b , c 
// Setters
void  Quadratic::setA(int aVal) {
    a = aVal;
}

void  Quadratic::setB(int bVal) {
    b = bVal;
}

void  Quadratic::setC(int cVal) {
    c = cVal;
   
}

// Getters
int Quadratic::getA() const {
    return a;
}

int Quadratic::getB() const {
    return b;
}

int Quadratic::getC() const {
    return c;
}


// display quadratic if values are empty display letter
//used void because we are only printing
//aslo validates if all
void Quadratic::display( ) const {
    if (a == 0) {
        cout << 'a';
    }
    else {
        cout << a;
        cout <<  "x^2 + ";
    }
    if (b == 0) {
        cout << 'b';
    }
    else {
        cout << b;
        cout << "x + ";
    }
    if (c == 0) {
        cout << 'c';
    }
    else {
        cout << c;
    }
    if (a == 0, b == 0, c == 0) {
        cout << "  inputs are empty ";
    }
    cout << endl;
    system("pause");
  
}


int Quadratic::evaluate(int x) const {
    return a * x * x + b * x + c;
    //multiplying x * x represnting x squared
}

int Quadratic::numberOfRealRoots() const {
    // b^2  - 4ac 
    double discriminant = b * b - 4 * a * c;

    if (a == 0) return (b != 0) ? 1 : 0;
    if (discriminant > 0) return 2;
    if (discriminant == 0) return 1;
    return 0;
}

int Quadratic::realRoots(int& root1, int& root2) const {
    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        if (b != 0) {
            root1 = -c / b;
            root2 = root1;
        }
    }
    else if (discriminant >= 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    return 0;
}
