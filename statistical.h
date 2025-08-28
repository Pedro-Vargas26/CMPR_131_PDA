#pragma once
#include "DynamicArray.h"

class statistical
{
public:
    double varianceIn(const double data[], int size);
    double midrangeIn(const double data[], int size);
    double quartilesIn(const double data[], int size, int q); // fixed typo
    double quartilesIn(const double data[], int size);
    double sumOfSquares(const double data[], int size);       // renamed for clarity
    double outliers(const double data[], int size);
};

// TO DO: bool validateDataSet(const DynamicArray<double>& data);