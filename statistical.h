#pragma once
#include "DynamicArray.h"
#include <vector>

class Statistical
{
private:
    DynamicArray<double> dataset;
public:

    Statistical(const DynamicArray<double>& dataset);
    double mean() const;
    double varianceIn();
    double standarddeviation();
    double midrangeIn();
    double quartilesIn();
    double outliers();
    double thesumofsquares();
    double median(double arr[], int start, int end);
    double meanabsolutedeviation();
    double rootmeansquare();

    double findMinimum();
    double findMaximum();
    double findRange();
    double findSum();
    double findMean();
    double findMedian();
    double* findMode(int& modeCount);
};

// TO DO: bool validateDataSet(const DynamicArray<double>& data);
