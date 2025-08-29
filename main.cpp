#include "input.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "statistical.h"
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <vector>
using namespace std;

DynamicArray<double> dataset;  

char menuOption();
int TaskJ();
int Task1();
char Task2();  
int getMin();
int getMax();
int getSum();
int getRange(); 
int getSize();
int getMean();
int getMedian();
int getMode();
int TaskK();
//int TaskL();

int main()
{
    cout << "\n\tWhat are Descriptive Statistics?";
    cout << "\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population) using numeric calculations.";
    cout << "\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php.";
    cout << "\n\n\tPress any key to continue...";

    system("pause");
    system("cls");

    do
    {
        switch (menuOption())
        {
        case '0': exit(1); break;
        case '2': Task2(); break;
        case 'A': getMin(); break;
        case 'B': getMax(); break;
        case 'C': getRange(); break;
        case 'D': getSize(); break;
        case 'E': getSum(); break;
        case 'F': getMean(); break;
        case 'G': getMedian(); break;
        case 'H': getMode(); break;
        case 'J': TaskJ(); break;
        case 'K': TaskK(); break;
        //case 'L': TaskL(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }

        cout << "\n";
        system("pause");
    } while (true);

    return EXIT_SUCCESS;
}

char menuOption()
{
    system("cls");
    cout << "\n\tAddress of Dynamic array: "; //#
    cout << "\n\tDataset: "; //sample
    if (dataset.size() == 0)
    {
        cout << "(sample)";
    }
    else
    {
        for (int i = 0; i < dataset.size(); i++)
        {
            cout << dataset.retrieve(i) << " ";
        }
    }
    cout << "\n\n\tERROR: Data set requires at least 2 values.";
    cout << "\n\tDescriptive Statistics Calculator Main Menu";
    cout << "\n\t================================================================================";
    cout << "\n\t0.Exit";
    cout << "\n\t1. Configure Dataset to Sample or Population";
    cout << "\n\t2. Insert sort value(s) to the Dataset";
    cout << "\n\t3. Delete value(s) from the Dataset";
    cout << "\n\t----------------------------------------------------------------------------------";
    cout << "\n\tA. Find Minimum";
    cout << "\n\tB. Find Maximum";
    cout << "\n\tC. Find Range";
    cout << "\n\tD. Find Size";
    cout << "\n\tE. Find Sum";
    cout << "\n\tF. Find Mean";
    cout << "\n\tG. Find Median";
    cout << "\n\tH. Find Mode";
    cout << "\n\tJ. Find Variance";
    cout << "\n\tK. Find Midrange";
    cout << "\n\tL. Find Quartiles";
    cout << "\n\t================================================================================";

    return toupper(inputChar("\n\tOption: "));
}

int Task1()
{
    cout << "\n\t In statistics, Population refers to the entire group of data";
    cout << "\n\tpoints that a study is interested in, while a Sample is a";
    cout << "\n\tsubset of that population that is actually used in the study.";
    cout << "\n\t\nConfigure Dataset Menu";
    cout << "\n\t================================================================================";
    cout << "\n\tA. sample";
    cout << "\n\tB. population";
    cout << "\n\t--------------------------------------------------------------------------------";
    cout << "\n\tR. return";
    cout << "\n\t================================================================================";

    char option = inputChar("\n\tOption: ", "ABR");

    switch (option) {
    case 'A': {
        double value;
        char again;
        do {
            value = inputDouble("\n\tEnter a value to insert: ");
            dataset.append(value);   // use DynamicArray
            again = inputChar("\n\tAdd another? (Y/N): ", "YN");
        } while (again == 'Y');
        break;
    }
    case 'B':
        return 0;
    case 'R':
        return 0;
    }
    return 0;
}

char Task2()
{
    system("cls");
    cout << "\n\t Insert (sort) Dataset Menu";
    cout << "\n\t================================================================================";
    cout << "\n\tA. insert a value";
    cout << "\n\tB. insert a specified number of random values";
    cout << "\n\tC. read data from file and insert values";
    cout << "\n\t================================================================================";
    cout << "\n\tR. return";
    cout << "\n\t================================================================================";
    char option = toupper(inputChar("\n\tOption: ", "ABCR"));

    switch (option)
    {

    case 'A':
    {
        double value;
        value = inputDouble("\n\tSpecify an integer value to be inserted to the Dataset: ");
        dataset.append(value);
        break;
    }

    case 'B':
    {
        int count = inputDouble("\n\tSpecify a number of values to be randomly generated into the Dataset: ",1,1000);
        srand(static_cast<unsigned>(time(nullptr)));
        for (int i = 0; i < count; i++)
        {
            double value = rand() % 100 + 1;
            dataset.append(value);
        }

        break;
    }


    case 'R':
    {
        return 1;
    }
    }
    //return 0;
}

int getMin()
{
    statistical stats;
    int size = dataset.size();
    
    if (size < 2) 
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }

    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    double minVal = stats.findMinimum(data, size);
    cout << "\n\tMinimum = " << minVal;

    delete[] data;
    return 0;
}

int getMax()
{
    statistical stats; 
    int size = dataset.size(); 
    
    if (size < 2) 
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }

    double* data = new double[size]; 
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    double maxVal = stats.findMaximum(data, size);
    cout << "\n\tMaximum = " << maxVal;

    delete[] data;
    return 0;
}

int getRange()
{
    statistical stats;
    int size = dataset.size();
    
    if (size < 2) 
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }
    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    double range = stats.findRange(data, size);
    cout << "\n\tRange = " << range;

    delete[] data;
    return 0;
}

int getSize()
{
    statistical stats;
    int size = dataset.size();

    if (size < 2)
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }
    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    cout << "\n\tSize = " << size;

    delete[] data;
    return 0;
}

int getSum()
{
    statistical stats; 
    int size = dataset.size(); 

    if (size < 2) 
    {
        cout << "\n\tERROR: Dataset must have at least 2 values."; 
        return 0; 
    }
    double* data = new double[size]; 
    for (int i = 0; i < size; i++) 
    {
        data[i] = dataset.retrieve(i); 
    } 
    
    int sum = stats.findSum(data, size);
    cout << "\n\tSum = " << sum;

    delete[] data;
    return 0;
}

int getMean()
{
    statistical stats;
    int size = dataset.size();

    if (size < 2)
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }
    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    double mean = stats.findMean(data, size);

    cout << "\n\tMean = " << fixed << setprecision(2) << mean;

    delete[] data;
    return 0;
}

int getMedian()
{
    statistical stats; 
    int size = dataset.size(); 

    if (size < 2)
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }
    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    double median = stats.findMedian(data, size);

    cout << "\n\tMedian = " << fixed << setprecision(2) << median;

    delete[] data;
    return 0;
}

int getMode()
{
    statistical stats;
    int size = dataset.size();

    if (size < 2)
    {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }
    double* data = new double[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = dataset.retrieve(i);
    }

    vector<double> modes = stats.findMode(data, size);
    cout << "\n\tMode(s) =  ";
    for (double m : modes)
    {
        cout << m << " ";
    }
    
    delete[] data;
    return 0;
}

int TaskJ()
{
    statistical stats;

    // pull data from dataset
    int size = dataset.size();
    if (size < 2) {
        cout << "\n\tERROR: Dataset must have at least 2 values.";
        return 0;
    }

    double* data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = dataset.retrieve(i);
    }

    double variance = stats.varianceIn(data, size);
    cout << "\n\t Variance : " << variance;

    delete[] data;
    return 0;
}

int TaskK()
{
    statistical stats;

    int size = dataset.size();
    if (size == 0) {
        cout << "\n\tERROR: Dataset is empty.";
        return 0;
    }

    double* data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = dataset.retrieve(i);
    }

    double midrange = stats.midrangeIn(data, size);
    cout << "\n\t Midrange : " << midrange;

    delete[] data;
    return 0;
}

//int TaskL()
//{
//    statistical stats;
//
//    int size = dataset.size();
//    if (size < 4) {
//        cout << "\n\tERROR: Dataset requires at least 4 values for quartiles.";
//        return 0;
//    }
//
//    double* data = new double[size];
//    for (int i = 0; i < size; ++i) {
//        data[i] = dataset.retrieve(i);
//    }
//
//    double q1 = stats.quratilesIn(data, size, 1);
//    double q2 = stats.quratilesIn(data, size, 2);
//    double q3 = stats.quratilesIn(data, size, 3);
//
//    cout << "\n\t Q1: " << q1;
//    cout << "\n\t Q2 (median): " << q2;
//    cout << "\n\t Q3: " << q3;
//
//    delete[] data;
//    return 0;
//}
