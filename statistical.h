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
    double variance(bool sample = true) const;               // <-- new
    double standardDeviation(bool sample = true) const;      // <-- new
    double midRange();
    double quartiles();
    double outliers();
    double SumOfSquares();
    double meanAbsoluteDeviation();
    double rootMeanSquare();

    /*Pedro's Portion*/
    double standardErrorOfMean(bool sample = true) const;    // <-- new
    double skewness(bool sample = true) const;               // <-- adjust later
    double kurtosis(bool sample = true) const;               // <-- adjust later
    double kurtosisExcess(bool sample = true) const;
    double coefficientVariation(bool sample = true) const;
    double relativeStandardDeviation(bool sample = true) const;
    //DynamicArray<pair<double, int>> frequencyTable()const;
};


#endif

