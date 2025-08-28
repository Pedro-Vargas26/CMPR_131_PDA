
#pragma once
#include "input.h"
#include <iomanip >
#include <iostream >
#include <cstdlib >
#include "statistical.h"
#include "DynamicArray.h"

using namespace std;


double  dataset;

char menuOption();
int TaskJ();
int Task1();
int Task2();
int TaskK();
int TaskL();


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
				case 0: exit(1); break;
				//case 1: Task1(); break;
				case 2: Task2(); break;
				//case 3: Task3(); break;

			     //case 'A': TaskA(); break;
				// case 'B': TaskB(); break;
				// case 'C': TaskC(); break;
				// case 'D': TaskD(); break;
				// case 'E': TaskE(); break;
				// case 'F': TaskF(); break;
				// case 'G': TaskG(); break;
				// case 'H': TaskH(); break;
				// case 'I': TaskI(); break;
				case 'J': TaskJ(); break;
				case 'K': TaskK(); break;
				case 'L': TaskL(); break;
				// case 'M': TaskM(); break;
				// case 'N': TaskN(); break;
				// case 'O': TaskO(); break;
				// case 'P': TaskP(); break;
				// case 'Q': TaskQ(); break;
				// case 'R': TaskR(); break;
				// case 'S': TaskS(); break;
				// case 'T': TaskT(); break;
				// case 'U': TaskU(); break;
				// case 'V': TaskV(); break;
				// case 'W': TaskW(); break;
				// case 'X': TaskX(); break;
				// case 'Y': TaskY(); break;
				// case 'Z': TaskZ(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}

//TODO 	case 'J': if (!validateDataSet(dataset)) break; TaskJ(); break; validate there is a data set prior to allowing A-Z

char menuOption()
{

	cout << "\n\tAddress of Dynamic array:"; //#
	cout << "\n\tDataset:"; //sample
	cout << "\n\n\tERROR: Data set requires at least 2 values.";
	cout << "\n\tDescriptive Statistics Calculator Main Menu";
	cout << "\n\t================================================================================";
	cout << "\n\t0.Exit";
	cout << "\n\t1. Configure Dataset to Sample or Polulation";
	cout << "\n\t2. Insert sort value(s) to the Dataset";
	cout << "\n\t3. Delete value(s) from the Dataset";
	cout << "\n\t----------------------------------------------------------------------------------";
	cout << "\n\tA. Find Minimum                                N. Find Outliers ";
	cout << "\n\tB. Find Maximum                                O. Find Sum of Squares";
	cout << "\n\tC. Find Range                                  P. Find Mean Absolute Deviation";
	cout << "\n\tD. Find Size                                   Q. Find Root Mean Square";
	cout << "\n\tE. Find Sum                                    R. Find Standard Error of Mean";
	cout << "\n\tF. Find Mean                                   S. Find Skewness";
	cout << "\n\tG. Find Median                                 T. Find Kurtosis";
	cout << "\n\tH. Find Mode(s)                                U. Find Kurtosis Excess";
	cout << "\n\tI. Find Standard Deviation                     V. Find Coefficient of Variation";
	cout << "\n\tJ. Find Variance                               W. Find Relative Standard Deviation";
	cout << "\n\tK. Find Midrange                               X. Display Frequency Table";
	cout << "\n\tL. Find Quartiles                              Y. Display ALL statical results";
	cout << "\n\tM. Find Interquartile Range                    Z. Output ALL statical results to text file";
	cout << "\n\t================================================================================";

	char option = 'A';

	option = inputChar("\n\tOption: ");
	if (option <= 0x30 && option >= 0x33) {
		switch (option) {
		case '0':
			break;
		case '1':
			break;
		default:
		}
	}
	else return option;
}

//To DO allow char to pass numbers and letters 

//DynamicArray<double> dataset;
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

	case'A': {
		double value;
		char again;
		do {

			value = inputDouble("\n\tEnter a value to insert: ");
		//	dataset.append(value);
			again = inputChar("\n\tAdd another? (Y/N): ", 'Y', 'N');
		} while (again == 'Y');

		break;

	}
	case 'B':
	{
		return 0;
	}
	case 'R':
		return 0;
	}
}

int Task2() {

	cout << "\n\t Insert (sort) Dataset Menu";
	cout << "\n\t================================================================================";
	cout << "\n\tA.insert a vlaue";
	cout << "\n\B. insert a specified number of random values";
	cout << "\n\t\nc.  read data from file and insert values";
	cout << "\n\t================================================================================";
	cout << "\n\tR. return";
	cout << "\n\t================================================================================";
	return inputChar("\n\tOption: ", "ABR");


}


// all of my examples are hard coded to see if formula is corrrect 
// TO DO HARD CODE TO USER INPUT 
//SHOULD USE DYNAMIC ARRAY CLASS TO CONVERT INPUT 
int TaskJ()

{
	statistical stats;

	//user input 
	/*
	int size = dataset.size();
	double* data = new double[size];

	for (int i = 0; i < size; ++i)
	{
		data[i] = dataset.retrieve(i);
	}

	*/
	//hardcoded  
	double data[] = { 3,4 };

	int size = sizeof(data) / sizeof(data[0]);

	double variance = stats.varianceIn(data, size);

	std::cout << "\n\t Variance : " << variance;
	return 0;
}

int TaskK() {
	statistical stats;
	//finding midrange : mean of max and min 
	double data[] = { 3, 4};
	int size = sizeof(data) / sizeof(data[0]);
	double midrange = stats.midrangeIn(data, size);

	std::cout << "Midrange:" << midrange;
	return 0;

}
/*
int TaskL() 
{
	statistical stats;

	double data[] = { 3,4 };
	int size = sizeof(data) / sizeof(data[0]);
	std::sort(data, data + size);

	double q1 = stats.quratilesIn(data, size, 1);
	double q2 = stats.quratilesIn(data, size, 2); // median
	double q3 = stats.quratilesIn(data, size, 3);
	std::cout << "Quartile:" << q1;
	std::cout << "Quartile:" << q2;
	std::cout << "Quartile:" << q3;

	return 0;
}
*/
