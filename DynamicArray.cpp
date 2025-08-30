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
    if (size == 0) throw std::exception("Exception ERROR: Dataset is empty. ");

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += dataset.retrieve(i);

    return sum / size;
}

double Statistical::standardDeviation()
{

    if (dataset.size() <= 1)
        throw std::exception("\n\tERROR: data set requires at least 2 values.\n");

    //standarddeviation : mean --
    int n = dataset.size();


   
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
        throw std::exception("\n\tException ERROR: Dataset must contain at least two elements. \n");

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

double Statistical::midRange()
{
    int size = dataset.size();
    if (size == 0)
        throw std::exception("\n\tException ERROR: Dataset is empty. \n");

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

double Statistical::quartiles()
{
    
    int size = dataset.size();
    double q1 = 0.0, q2 = 0.0, q3 = 0.0, iqr = 0.0;

    if (size == 0) 
        throw std::exception("\n\tERROR: Not enough values in dataset.\n");
    else if (size == 1) {
        throw std::exception("\n\tERROR: At least 2 values required to compute quartiles.\n");
    }

    double* sortedArr = new double[size];
    for (int i = 0; i < size; ++i)
        sortedArr[i] = dataset.retrieve(i);



    
    if (size == 2) {
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
        throw std::exception("\n\tException ERROR: Dataset must contain more values. \n");

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

double Statistical::SumOfSquares()
{
    int size = dataset.size();
    if (size == 0)
        throw std::exception("\n\tException ERROR: INVALID DATASET SIZE. \n");

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

double Statistical::meanAbsoluteDeviation() {
    int size = dataset.size();
    if (size == 0) throw std::exception("\n\tEXCEPTION ERROR:  Dataset must contain more values. \n");

    //using mean function

    double m = Statistical::mean();


    double sumAbsoluteDiff = 0.0;

    for (int i = 0; i < size; ++i) {
        sumAbsoluteDiff += std::fabs(dataset.retrieve(i) - m);
    }

    return sumAbsoluteDiff / size;
}

double Statistical::rootMeanSquare() {
    int n = dataset.size();
    if (n == 0) throw std::exception("\n\tException Error: Dataset must contain more values. \n");

    double sumSquares = 0.0;
    for (int i = 0; i < n; ++i) {
        double val = dataset.retrieve(i);
        sumSquares += val * val;
    }

    return std::sqrt(sumSquares / n);
}


double Statistical::minimum()
{
    double minVal = dataset.retrieve(0);

    return minVal;
}


double Statistical::maximum()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
   }

   return dataset.retrieve(dataset.size() - 1);
}

double Statistical::range()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double minVal = dataset.retrieve(0);

    double maxVal = dataset.retrieve(dataset.size() - 1);

    double range = maxVal - minVal;

    return range;

}

double Statistical::sum()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double sum = 0.0;

    for (int i = 0; i < dataset.size(); i++)
    {
        sum += dataset.retrieve(i);
    }

    return sum;
}


double Statistical::median()
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

    double median = 0.0;
    median = dataset.retrieve(dataset.size() / 2);
    if (dataset.size() % 2 == 0)
    {
        median = (median + dataset.retrieve(dataset.size() / 2 - 1)) / 2;
    }

    return median;
}

double* Statistical::mode(int& modeCount)
{
    if (dataset.size() == 0) {
        throw std::exception("\n\tEXCEPTION ERROR: Dataset must contain more values. \n");
    }

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


