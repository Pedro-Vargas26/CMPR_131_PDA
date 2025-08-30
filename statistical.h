#include "DynamicArray.h"
#include "DynamicArray.cpp"

#pragma once

#ifndef STATSTICAL_H
#define STATISTICAL_H
class Statistical {
private:
	DynamicArray<double> dataset;
    double median(double arr[], int start, int end);
public:

    Statistical(const DynamicArray<double>& dataset);

    /*Anthony's Portion*/
        
    double minimum();
    double maximum();
    double range();
    double sum();
    double mean() const;
    double median();
    double* mode(int& modeCount);


    /*Daisy's Portion*/
    double varianceIn();
    double standardDeviation();
    double midRange();
    double quartiles();
    double outliers();
    double SumOfSquares();
    double meanAbsoluteDeviation();
    double rootMeanSquare();




    /*Pedros Portion*/


};

#endif

