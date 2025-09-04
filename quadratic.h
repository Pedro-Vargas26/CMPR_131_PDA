#pragma once
#ifndef QUADRATIC_H
#define QUADRATIC_H

class Quadratic {
private:
    int a, b, c;

public:
    Quadratic(); 

  //precondition : none 
  //post condition : returns aval 
    void  setA(int aVal);

  //precondition : none 
  //post condition : returns baval 
    void  setB(int bVal);

  //precondition : none 
  //post condition : returns cVal 
    void  setC(int cVal);


  //precondition : none 
  //post condition : returns a as an integer  
    int getA() const;

  //precondition : none 
  //post condition : returns b as an integer  
    int getB() const;

  //precondition : none 
  //post condition : returns c as an integer  
    int getC() const;

  //precondition : none 
  //post condition : outputs quadratic equation with a, b and c as its inputs  
    void display() const;

  //precondition : x is an integer 
 //post condition : returns x as the answer of the quadratic expression    
    int evaluate(int x) const;

  //precondition : a, b and c must be initialized   
 //post condition : returns if the equation has 1, 2 or no real roots  
    int numberOfRealRoots() const;

  //precondition : a, b and c must be initialized  
 //post condition : returns  number of real roots
    int realRoots(int& root1, int& root2) const;
};

#endif
