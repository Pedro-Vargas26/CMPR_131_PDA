#pragma once
#include "DynamicArray.h"
#include <vector>

class statistical
{
public:
    double varianceIn(const double data[], int size);
    double midrangeIn(const double data[], int size);
    double quartilesIn(const double data[], int size, int q); // fixed typo
    double quartilesIn(const double data[], int size);
    double sumOfSquares(const double data[], int size);       // renamed for clarity
    double outliers(const double data[], int size);
    double findMinimum(const double data[], int size);
    double findMaximum(const double data[], int size);
    double findRange(const double data[], int size);
    double findSum(const double data[], int size);
    double findMean(const double data[], int size);
    double findMedian(const double data[], int size);
    std::vector<double> findMode(const double data[], int size);
};

// TO DO: bool validateDataSet(const DynamicArray<double>& data);
