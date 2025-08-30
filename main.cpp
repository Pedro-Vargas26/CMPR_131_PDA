#include "input.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "Statistical.h"
#include "DynamicArray.h"
#include <vector>

using namespace std;
DynamicArray<double> dataset;  

char menuOption();
int getMin();
int getMax();
int getSum();
int getRange();
int getSize();
int getMean();
int getMedian();
int getMode();
double TaskI();
double TaskJ();
double TaskK();
double TaskL();
double TaskM();
double TaskN();
double TaskO();
double TaskP();
double TaskQ();
int Task1();
char Task2();  

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
    char option = 0;
    do
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
        option = toupper(inputChar("\n\tOption: ", "ABCR"));

        switch (option)
        {

        case 'A':
        {
            double value;
            value = inputDouble("\n\tSpecify an integer value to be inserted to the Dataset: ");
            dataset.append(value);

            cout << "\n\t" << value << " has been inserted...";
            cout << "\n\n";
            system("pause");
            break;
        }

        case 'B':
        {
            int count = inputDouble("\n\tSpecify a number of values to be randomly generated into the Dataset: ", 1, 1000);
            srand(static_cast<unsigned>(time(nullptr)));
            for (int i = 0; i < count; i++)
            {
                double value = rand() % 100 + 1;
                dataset.append(value);
            }

            cout << "\n\tCONFIRMATION: Inserted " << count << " random values into the Dataset.";
            cout << "\n\n";
            system("pause");

            break;
        }


        case 'R':
        {
            return 0;
        }
        }
    } while (option != 0);
    //return 0;
}

int getMin()
{
    Statistical stats(dataset);

    double Minimum = stats.findMinimum();

    cout << "\n\tMinimum = " << Minimum;
   
    return Minimum;
}

int getMax()
{
    Statistical stats(dataset);

    double Maximum = stats.findMaximum();

    cout << "\n\tMaximum = " << Maximum;

    return Maximum;
}

int getRange()
{
    Statistical stats(dataset);

    double Range = stats.findRange();

    cout << "\n\tRange = " << Range;

    return Range;
}

int getSize()
{
    Statistical stats(dataset);

    double Size = dataset.size();

    cout << "\n\tSize = " << Size;

    return Size;
}

int getSum()
{
    Statistical stats(dataset);

    double Sum = stats.findSum();

    cout << "\n\tSum = " << Sum;

    return Sum;
}

int getMean()
{
    Statistical stats(dataset);

    double Mean = stats.findMean();

    cout << "\n\tMean = " << fixed << setprecision(2) << Mean << defaultfloat;

    return Mean;
}

int getMedian()
{
    Statistical stats(dataset);

    double Median = stats.findMedian();

    cout << "\n\tMedian = " << fixed << setprecision(2) << Median << defaultfloat;

    return Median;
}

int getMode()
{
    Statistical stats(dataset);

    int modeCount = 0;
    double* modes = stats.findMode(modeCount);

    cout << "\n\tMode(s) = ";
    for (int i = 0; i < modeCount; i++)
        cout << modes[i] << " ";

    delete[] modes; // free memory
    return 0;
}

double TaskI()
{

    Statistical stats(dataset);
    double stddev = stats.standarddeviation();
    std::cout << "Sample standard deviation =  " << stddev;
    return stddev;
}

double TaskJ()
{
    Statistical stats(dataset);
    double vrnce = stats.varianceIn();
    std::cout << "Variance =  " << vrnce;
    return vrnce;

}
double TaskK()
{
    Statistical stats(dataset);
    double mdrnge = stats.midrangeIn();
    std::cout << "Midrange =  " << mdrnge;
    return mdrnge;

}

double TaskL()
{
    Statistical stats(dataset);
    double iqr = stats.quartilesIn();
    return iqr;
}

double TaskM()
{
    //needs to only reurn IQR
    Statistical stats(dataset);
    double iqr = stats.quartilesIn();
    return iqr;
}

double TaskN()
{
    Statistical stats(dataset);
    double out = stats.outliers();
    std::cout << "Outliers =  " << out;
    return out;
}

double TaskO()
{
    Statistical stats(dataset);
    double sumsquares = stats.thesumofsquares();
    std::cout << "Sum of Squares = " << sumsquares;
    return sumsquares;
}

double TaskP()
{
    Statistical stats(dataset);
    double mnabsdeviation = stats.meanabsolutedeviation();
    std::cout << "Mean Absoulte Deviation = " << mnabsdeviation;
    return mnabsdeviation;
}

double TaskQ()
{
    Statistical stats(dataset);
    double rtmeansquare = stats.rootmeansquare();
    std::cout << "Root Mean Square = " << rtmeansquare;
    return rtmeansquare;
}
