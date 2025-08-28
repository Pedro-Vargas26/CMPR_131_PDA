#pragma once
#include "DynamicArray.h"

class statistical
{
public:
	double varianceIn(const double data[], int);

	double midrangeIn(const double data[], int size);

	double quratilesIn(const double data[], int size, int q);

	double quartilesIn(const double data[], int size);

	double thesumofsquares(const double data[], int size);

	double outliers(const double data[], int size);
}

 //TO DO bool validateDataSet(const DynamicArray<double>& data);