#include "statistical.h"
#include "DynamicArray.h"

#include <iostream>
#include <algorithm>
#include <cmath> // for floor
#include <vector>

using namespace std;

double statistical::findMinimum(const double data[], int size)
{
    double minVal = data[0];

    return minVal;
}


double statistical::findMaximum(const double data[], int size)
{
    double maxVal = data [size - 1];

    return maxVal;
}

double statistical::findRange(const double data[], int size)
{
    double minVal = data[0];

    double maxVal = data[size - 1];

    double range = maxVal - minVal;

    return range;
    
}

double statistical::findSum(const double data[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }

    return sum;
}

double statistical::findMean(const double data[], int size)
{
    int sum = 0.0;
    double mean = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i]; 
    }

    return mean = sum/size;
}

double statistical::findMedian(const double data[], int size)
{
    double median = 0.0;
    median = data[size / 2];
    if (size % 2 == 0)
    {
        median = (median + data[size / 2 - 1]) / 2;
    }

    return median;
}

vector<double> statistical::findMode(const double data[], int size)
{
    vector<double> modes;
    int maxCount = 1;
    int currentCount = 1;

    for(int i = 1; i < size; i++)
    {
        if (data[i] == data[i - 1])
        {
            currentCount++;
        }
        else
        {
            currentCount = 1;
        }

        if (currentCount > maxCount)
        {
            maxCount = currentCount;
        }
       
    }

    currentCount = 1;
    for (int i = 1; i <= size; i++)
    {
        if (i < size && data[i] == data[i - 1])
        {
            currentCount++;
        }
        else
        {
            if (currentCount == maxCount)
            {
                modes.push_back(data[i - 1]);
            }

            currentCount = 1;
        }
    }
    return modes;
}



double statistical::varianceIn(const double data[], int size)
{
    if (size < 2)
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    double mean = sum / size;

    double variance = 0.0;
    for (int i = 0; i < size; ++i) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    return variance / (size - 1);
}

double statistical::midrangeIn(const double data[], int size)
{
    if (size == 0)
        return 0.0;

    double minVal = data[0];
    double maxVal = data[0];

    for (int i = 1; i < size; ++i) {
        if (data[i] < minVal) minVal = data[i];
        if (data[i] > maxVal) maxVal = data[i];
    }
    return (minVal + maxVal) / 2.0;
}

double statistical::quartilesIn(const double data[], int size, int q)
{
    if (size == 0)
        return 0.0;

    double* sorted = new double[size];
    for (int i = 0; i < size; i++) sorted[i] = data[i];
    std::sort(sorted, sorted + size);

    double pos = (q * (size + 1)) / 4.0;

    double result;
    if (floor(pos) == pos) {
        int idx = static_cast<int>(pos) - 1;
        if (idx < 0) idx = 0;
        if (idx >= size) idx = size - 1;
        result = sorted[idx];
    }
    else {
        int lower = static_cast<int>(floor(pos)) - 1;
        int upper = lower + 1;

        if (lower < 0) lower = 0;
        if (upper >= size) upper = size - 1;

        double fraction = pos - floor(pos);
        result = sorted[lower] + fraction * (sorted[upper] - sorted[lower]);
    }

    delete[] sorted;
    return result;
}

double statistical::quartilesIn(const double data[], int size)
{
    if (size < 4)
        return 0.0;

    double* sorted = new double[size];
    for (int i = 0; i < size; i++) sorted[i] = data[i];
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

    double result = q3 - q1;
    delete[] sorted;
    return result;
}

double statistical::outliers(const double data[], int size)
{
    if (size < 4)
        return 0.0;

    double* sorted = new double[size];
    for (int i = 0; i < size; i++) sorted[i] = data[i];
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

double statistical::sumOfSquares(const double data[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i] * data[i];
    }
    return sum;
}

