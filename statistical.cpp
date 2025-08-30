#include "Statistical.h"
#include "DynamicArray.h"

#include <iostream>
#include <algorithm>
#include <cmath> // for floor
#include <vector>

using namespace std;

Statistical::Statistical(const DynamicArray<double>& data) : dataset(data) {}

double Statistical::mean() const
{
    int size = dataset.size();
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += dataset.retrieve(i);

    return sum / size;
}

double Statistical::standarddeviation()
{
    //standarddeviation : mean --
    int n = dataset.size();

    if (n <= 1) {
        std::cout << "\n\tERROR: data set requires at least 2 values.\n";
        return 0.0;
    }

    double m = Statistical::mean();



    double totalSquaredDiff = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = dataset.retrieve(i) - m;
        totalSquaredDiff += diff * diff;
    }

    return std::sqrt(totalSquaredDiff / (n - 1));  // Sample std dev denominator is n-1
}

double Statistical::varianceIn()
{
    int size = dataset.size();
    if (size < 2)
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += dataset.retrieve(i);

    double mean = sum / size;

    double variance = 0.0;
    for (int i = 0; i < size; ++i)
    {
        double diff = dataset.retrieve(i) - mean;
        variance += diff * diff;
    }
    return variance / (size - 1);
}

double Statistical::midrangeIn()
{
    int size = dataset.size();
    if (size == 0)
        return 0.0;

    double minVal = dataset.retrieve(0);
    double maxVal = dataset.retrieve(0);

    for (int i = 1; i < size; ++i)
    {
        double val = dataset.retrieve(i);
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    return (minVal + maxVal) / 2.0;
}

double Statistical::quartilesIn()
{
    int size = dataset.size();
    double q1, q2, q3, iqr;

    if (size == 0) {
        std::cout << "\n\tERROR: Not enough values in dataset.\n";
        return 0.0;
    }

    double* sortedArr = new double[size];
    for (int i = 0; i < size; ++i)
        sortedArr[i] = dataset.retrieve(i);



    if (size == 1) {
        std::cout << "\n\tERROR: At least 2 values required to compute quartiles.\n";

    }
    else if (size == 2) {
        q2 = median(sortedArr, 0, 1);
        std::cout << "\n\tQ1 = empty";
        std::cout << "\n\tQ2 = " << q2;
        std::cout << "\n\tQ3 = empty";

    }
    else {
        q1 = median(sortedArr, 0, (size - 1) / 2);
        q2 = median(sortedArr, 0, size - 1);
        q3 = median(sortedArr, (size + 1) / 2, size - 1);
        iqr = q3 - q1;

        std::cout << "\n\tQ1 = " << q1;
        std::cout << "\n\tQ2 = " << q2;
        std::cout << "\n\tQ3 = " << q3;
        std::cout << "\n\t Interquartile = " << iqr;

    }

    delete[] sortedArr;
    return iqr;
}

double Statistical::outliers()
{
    int size = dataset.size();
    if (size < 4)
        return 0;

    double* sortedArr = new double[size];
    for (int i = 0; i < size; ++i)
        sortedArr[i] = dataset.retrieve(i);

    double q1 = median(sortedArr, 0, (size - 1) / 2);
    double q3 = median(sortedArr, (size + 1) / 2, size - 1);
    double iqr = q3 - q1;

    double lowerBound = q1 - 1.5 * iqr;
    double upperBound = q3 + 1.5 * iqr;

    int count = 0;
    bool foundOutlier = false;
    for (int i = 0; i < size; ++i)
    {
        double val = dataset.retrieve(i);
        if (val < lowerBound || val > upperBound)
        {
            std::cout << val << " ";
            foundOutlier = true;
        }
    }
    if (!foundOutlier)
        std::cout << "No outliers detected.";

    std::cout << std::endl;
    delete[] sortedArr;
    return count;
}

double Statistical::thesumofsquares()
{
    int size = dataset.size();
    if (size == 0)
        return 0.0;

    double mean = 0.0;
    for (int i = 0; i < size; ++i)
        mean += dataset.retrieve(i);

    mean /= size;

    double sumSquares = 0.0;
    for (int i = 0; i < size; ++i)
    {
        double diff = dataset.retrieve(i) - mean;
        sumSquares += diff * diff;
    }

    return sumSquares;
}

double Statistical::median(double arr[], int start, int end)
{
    int length = end - start + 1;
    int mid = start + length / 2;

    if (length % 2 == 0)
        return (arr[mid - 1] + arr[mid]) / 2.0;
    else
        return arr[mid];
}

double Statistical::meanabsolutedeviation() {
    int size = dataset.size();
    if (size == 0) return 0.0;

    //using mean function

    double m = Statistical::mean();


    double sumAbsoluteDiff = 0.0;

    for (int i = 0; i < size; ++i) {
        sumAbsoluteDiff += std::fabs(dataset.retrieve(i) - m);
    }

    return sumAbsoluteDiff / size;
}

double Statistical::rootmeansquare() {
    int n = dataset.size();
    if (n == 0) {
        return 0.0;
    }

    double sumSquares = 0.0;
    for (int i = 0; i < n; ++i) {
        double val = dataset.retrieve(i);
        sumSquares += val * val;
    }

    return std::sqrt(sumSquares / n);
}


double Statistical::findMinimum()
{
    double minVal = dataset.retrieve(0);

    return minVal;
}


double Statistical::findMaximum()
{
    double maxVal = dataset.retrieve(dataset.size() - 1);

    return maxVal;
}

double Statistical::findRange()
{
    double minVal = dataset.retrieve(0);

    double maxVal = dataset.retrieve(dataset.size() - 1);

    double range = maxVal - minVal;

    return range;
    
}

double Statistical::findSum()
{
    int sum = 0;

    for (int i = 0; i < dataset.size(); i++)
    {
        sum += dataset.retrieve(i);
    }

    return sum;
}

double Statistical::findMean()
{
    double sum = 0.0;
    double mean = 0.0;
    for (int i = 0; i < dataset.size(); i++)
    {
        sum += dataset.retrieve(i); 
    }

    return mean = sum/dataset.size();
}

double Statistical::findMedian()
{
    double median = 0.0;
    median = dataset.retrieve(dataset.size() / 2);
    if (dataset.size() % 2 == 0)
    {
        median = (median + dataset.retrieve(dataset.size() / 2 - 1)) / 2;
    }

    return median;
}

double* Statistical::findMode(int& modeCount)
{
    int maxCount = 1;
    int currentCount = 1;

    // First pass: find the highest frequency
    for (int i = 1; i < dataset.size(); i++)
    {
        if (dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
            currentCount = 1;

        if (currentCount > maxCount)
            maxCount = currentCount;
    }

    // Second pass: count how many numbers appear maxCount times
    currentCount = 1;
    modeCount = 0;
    for (int i = 1; i <= dataset.size(); i++)
    {
        if (i < dataset.size() && dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
        {
            if (currentCount == maxCount)
                modeCount++;

            currentCount = 1;
        }
    }

    // Allocate dynamic array to hold the modes
    double* modes = new double[modeCount];

    // Third pass: fill the array
    currentCount = 1;
    int index = 0;
    for (int i = 1; i <= dataset.size(); i++)
    {
        if (i < dataset.size() && dataset.retrieve(i) == dataset.retrieve(i - 1))
            currentCount++;
        else
        {
            if (currentCount == maxCount)
                modes[index++] = dataset.retrieve(i - 1);

            currentCount = 1;
        }
    }

    return modes; // caller must delete[]
}



