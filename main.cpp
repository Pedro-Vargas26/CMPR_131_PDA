
#pragma once
#include "input.h"
#include <iomanip >
#include <iostream >
#include <cstdlib >
#include "DynamicArray.h"
#include "statistical.h"

using namespace std;
DynamicArray<double> dataset;

char menuOption();
int OptionOne();
int OptionTwo();
int OptionThree();

double TaskI();
double TaskJ();
double TaskK();
double TaskL();
double TaskM();
double TaskN();
double TaskO();
double TaskP();
double TaskQ();

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
		case '0': exit(0); break;
		case '1': OptionOne(); break;
		case '2': OptionTwo(); break;
			//case 3: Task3(); break;

			 //case 'A': TaskA(); break;
			// case 'B': TaskB(); break;
			// case 'C': TaskC(); break;
			// case 'D': TaskD(); break;
			// case 'E': TaskE(); break;
			// case 'F': TaskF(); break;
			// case 'G': TaskG(); break;
			// case 'H': TaskH(); break;
	  case 'I': TaskI(); break;
	  case 'J': TaskJ(); break;
	  case 'K': TaskK(); break;
	  case 'L': TaskL(); break;
	  case 'M': TaskM(); break;
	  case 'N': TaskN(); break;
	  case 'O': TaskO(); break;
	  case 'P': TaskP(); break;
	  case 'Q': TaskQ(); break;
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
	system("cls");
	cout << "\n\tAddress of Dynamic array:"; //#
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

	return toupper(inputChar("\n\tOption: "));
	
}

int OptionOne()

{
	system("cls");
	cout << "\n\t In statistics, Population refers to the entire group of data";
	cout << "\n\tpoints that a study is interested in, while a Sample is a";
	cout << "\n\tsubset of that population that is actually used in the study.";

	cout << "\n\tConfigure Dataset Menu";
	cout << "\n\t ============================================================";
	cout << "\n\tA. sample";
	cout << "\n\tB. population";
	cout << "\n\t ============================================================";
	cout << "\n\tR. Return";
	cout << "\n\t ============================================================";

	return 0;
}

int OptionTwo()

{
  while(true)
	 {
	system("cls");
	cout << "\n\tInsert (sort) Dataset Menu";
	cout << "\n\t ============================================================";
	cout << "\n\tA. insert a value";
	cout << "\n\tB. insert a specified number of random values";
	cout << "\n\tC. read data from file and insert values";
	cout << "\n\t ============================================================";
	cout << "\n\tR. Return";
	cout << "\n\t ============================================================";


	char option2 = inputChar("\n\tOption: ", "ABCR");

	switch (option2)

	{
	case 'a':
	{
		int value = inputInteger("\n\tSpecify an integer value to be inserted to the Dataset: ");
		dataset.append(value); 
		cout << "\n\t" << value << " has been inserted";
		system("pause");
		break;
	}

	case 'r':
		return 1; // Return to main menu

	case 'b': 
		break;
	case 'c':
		break;

	default:
		cout << "\n\tInvalid option. Try again.\n";
		break;
	}
	} 

} 

int OptionThree()

{
	system("cls");
	cout << "\n\tDelete Dataset Menu";
	cout << "\n\tA. delete a value";
	cout << "\n\t B. delete a range of values";
	cout << "\n\tC. delete all values";
	cout << "\n\t ============================================================";
	cout << "\n\tR. Return";
	cout << "\n\t ============================================================";

	return 0;
}


double TaskI() 
{

	Statistical stats(dataset);
	double stddev = Statistical::standarddeviation(dataset); 
	std::cout << "Sample standard deviation =  "<< stddev ;
	return stddev;
}

double TaskJ()
{
	Statistical sats(dataset);
	double vrnce = Statistical::varianceIn(dataset);
	std::cout << "Variance =  " << vrnce;
	return vrnce;

}
double TaskK()
{
	Statistical sats(dataset);
	double mdrnge = Statistical::midrangeIn(dataset);
	std::cout << "Midrange =  " << mdrnge;
	return mdrnge;

}

double TaskL()
{
	Statistical stats(dataset);
	double iqr = stats.quartilesIn(dataset);
	return iqr;
}

double TaskM()
{
	//needs to only reurn IQR
	Statistical stats(dataset);
	double iqr = stats.quartilesIn(dataset);
	return iqr;
}

double TaskN()
{
		Statistical stats(dataset);
		double out = stats.outliers(dataset);
		std::cout << "Outliers =  " << out;
		return out;
}

double TaskO()
{
	Statistical stats(dataset);
	double sumsquares = stats.thesumofsquares(dataset); 
	std::cout << "Sum of Squares = " <<sumsquares;
	return sumsquares;
}

double TaskP()
{
	Statistical stats(dataset);
	double mnabsdeviation = stats.meanabsolutedeviation(dataset);
	std::cout << "Mean Absoulte Deviation = " << mnabsdeviation;
	return mnabsdeviation;
}

double TaskQ()
{
	Statistical stats(dataset);
	double rtmeansquare = stats.rootmeansquare(dataset);
	std::cout << "Root Mean Square = " << rtmeansquare;
	return rtmeansquare;
}


