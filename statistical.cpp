#include "statistical.h"
#include "DynamicArray.h"
#include <cmath>   
#include <algorithm>
#include <iostream> 



using namespace std;

Statistical::Statistical(const DynamicArray<double>& data) : dataset(data) {}

double Statistical::mean(const DynamicArray<double>& dataset)
{
    int size = dataset.size();
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
        sum += dataset.retrieve(i);

    return sum / size;
}

double Statistical::standarddeviation(const DynamicArray<double>& dataset)
{
    //standarddeviation : mean --
    int n = dataset.size();

    if (n <= 1) {
        std::cout << "\n\tERROR: data set requires at least 2 values.\n";
        return 0.0;
    }
    
    double m = Statistical::mean(dataset);



    double totalSquaredDiff = 0.0;
    for (int i = 0; i < n; ++i) {
        double diff = dataset.retrieve(i) - m;
        totalSquaredDiff += diff * diff;
    }

    return std::sqrt(totalSquaredDiff / (n - 1));  // Sample std dev denominator is n-1
}

double Statistical::varianceIn(const DynamicArray<double>& dataset)
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

double Statistical::midrangeIn(const DynamicArray<double>& dataset)
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

double Statistical::quartilesIn(const DynamicArray<double>& dataset)
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


double Statistical::outliers(const DynamicArray<double>& dataset)
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

double Statistical::thesumofsquares(const DynamicArray<double>& dataset)
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

double Statistical::meanabsolutedeviation(const DynamicArray<double>& dataset) {
    int size = dataset.size();
    if (size == 0) return 0.0;
   
    //using mean function

    double m = Statistical::mean(dataset);
  

    double sumAbsoluteDiff = 0.0;

    for (int i = 0; i < size; ++i) {
        sumAbsoluteDiff += std::fabs(dataset.retrieve(i) - m);
    }

    return sumAbsoluteDiff / size;
}



double Statistical::rootmeansquare(const DynamicArray<double>& dataset) {
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
