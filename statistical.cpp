#include "statistical.h"
#include "DynamicArray.h"

#include <iostream>
#include <algorithm>

using namespace std;

//TO DO validate array has input 




double statistical::varianceIn(const double data[], int size)
{
	if (size < 2 )
		return 0.0;

	double sum = 0.0;

	for (int i = 0; i < size; ++i)
	{
		sum += data[i];
	}

	double mean = sum / size;

	double variance = 0.0;
	for (int i = 0; i < size; ++i)
	{
		variance += (data[i] - mean)* (data[i]-mean);

	}
	return variance / (size-1);
}


double statistical::midrangeIn(const double data[], int size)
{
	if (size == 0)

		return 0.0;

	double min = data[0];
	double max = data[0];

	for (int i = 1; i < size; ++i)
	{
		if (data[i] < min) min = data[i];
		if (data[i] > max) max = data[i];
	}
	return(min + max) / 2.0;

}
/**


double statistical::quratilesIn(const double data[], int size, int q)
{
	// Q1 : 1/4(n+1)^thterm Q2:  3/4(n+1)^thterm Q2 : Q3 - Q1

	if (size == 0)

		return 0.0;

	double pos = (q * (size + 1)) / 4.0;

	if (floor(pos) == pos)
	{
		int idx = static_cast<int>(pos) - 1;
		if (idx < 0) idx = 0;
		if (idx >= size) idx = size - 1;
		return data[idx];


	}
	else
	{
		int lower = static_cast<int>(floor(pos)) - 1;
		int upper = lower + 1;

		if (lower < 0) lower = 0;
		if (upper >= size) upper = size - 1;

		double fraction = pos - floor(pos);
		return data[lower] + fraction * (data[upper] - data[lower]);


	}
}



double statistical::quartilesIn(const double data[], int size)
//IQR = Q3 -Q1
{
	if (size < 4) 
		return 0.0;

	double* sorted = new double[size];
	for (int i = 0; i < size; i++)
		sorted[i] = data[i];

	std::sort(sorted, sorted + size);

auto median = [](double arr[], int start, int end) -> double {
	int length = end - start + 1;
	int mid = start + length / 2;
	if (length % 2 == 0)
		return (arr[mid - 1] + arr[mid]) / 2.0;
	else
		return arr[mid];
	};

double q1 = median(sorted, 0, (size - 1) / 2);

double q3 = median(sorted, 0, (size - 1) / 2);

double result = q3 - q1;
return result;
}


double statistical::outliers(const double data[], int size)
{

	if (size < 4)
		return 0.0;

	double* sorted = new double[size];
	for (int i = 0; i < size; i++)
		sorted[i] = data[i];

	std::sort(sorted, sorted + size);

	auto median = [](double arr[], int start, int end) -> double {
		int length = end - start + 1;
		int mid = start + length / 2;
		if (length % 2 == 0)
			return (arr[mid - 1] + arr[mid]) / 2.0;
		else
			return arr[mid];
		};

	double q1 = median(sorted, 0, (size - 1) / 2);

	double q3 = median(sorted, (size + 1) / 2, size - 1);

	double iqr = q3 - q1;

	double lowerBound = q1 - 1.5 * iqr;

	double upperBound = q3 + 1.5 * iqr;

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] < lowerBound || data[i] > upperBound)
			count++;
	}

	delete[] sorted;
	return count;

}


double statistical::thesumofsquares(const double data[], int size)
	{
	return 0.0;
	}
	*/