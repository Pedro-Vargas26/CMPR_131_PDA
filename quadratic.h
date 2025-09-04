#pragma once
#ifndef QUADRATIC_H
#define QUADRATIC_H

class Quadratic {
private:
    int a, b, c;

public:
    Quadratic(); 

    void  setA(int aVal);
    void  setB(int bVal);
    void  setC(int cVal);

    int getA() const;
    int getB() const;
    int getC() const;

    void display() const;
    int evaluate(int x) const;

    int numberOfRealRoots() const;
    int realRoots(int& root1, int& root2) const;
};

#endif
