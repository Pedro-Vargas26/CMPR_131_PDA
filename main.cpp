#pragma once
#include "input.h"
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <cstdlib>
#include <iomanip>
#include <conio.h >
#include <iostream>

using namespace std;
char menuOption();

int main()
{

	cout << "\n\tWhat are Descriptive Statistics?";
	cout << "\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population) using numeric calculations.";
	cout << "\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php.";
	cout << "\n\n\tPress any key to continue...";

	_getch();
	system("cls");

	do
	{
		switch (menuOption())
		{
		case 0: exit(1); break;
			//case 'A': TaskA(); break;
				// case 'B': TaskB(); break;
				// case 'C': TaskC(); break;
				// case 'D': TaskD(); break;
				// case 'E': TaskE(); break;
				// case 'F': TaskF(); break;
				// case 'G': TaskG(); break;
				// case 'H': TaskH(); break;
				// case 'I': TaskI(); break;
				// case 'J': TaskJ(); break;
				// case 'K': TaskK(); break;
				// case 'L': TaskL(); break;
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
	cout << "\n\tA. Find Minimum N. Find Outliers ";
	cout << "\n\tB. Find Maximum O. Find Sum of Squares";
	cout << "\n\tC. Find Range P. Find Mean Absolute Deviation";
	cout << "\n\tD. Find Size Q. Find Root Mean Square";
	cout << "\n\tE. Find Sum R. Find Standard Error of Mean";
	cout << "\n\tF. Find Mean S. Find Skewness";
	cout << "\n\tG. Find Median T. Find Kurtosis";
	cout << "\n\tH. Find Mode(s) U. Find Kurtosis Excess";
	cout << "\n\tI. Find Standard Deviation V. Find Coefficient of Variation";
	cout << "\n\tJ. Find Variance W. Find Relative Standard Deviation";
	cout << "\n\tK. Find Midrange X. Display Frequency Table";
	cout << "\n\tL. Find Quartiles Y. Display ALL statical results";
	cout << "\n\tM. Find Interquartile Range Z. Output ALL statical results to text file";
	cout << "\n\t================================================================================";

	return inputChar("\n\tOption: ", "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
// TODO Statistic class, use dynamicArray copy constructor
