#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include "input.h"
#include "DynamicArray.h"
#include "Statistical.h"

using namespace std;
DynamicArray<double> dataset;

char menuOption();
int OptionOne();
int OptionTwo();
int OptionThree();

void readFromFile();

void TaskA();
void TaskB();
void TaskC();
void TaskD();
void TaskE();
void TaskF();
void TaskG();
void TaskH();
void TaskI();
void TaskJ();
void TaskK();
void TaskL();
void TaskM();
void TaskN();
void TaskO();
void TaskP();
void TaskQ();

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

		case 'A': TaskA(); break;
		case 'B': TaskB(); break;
		case 'C': TaskC(); break;
		case 'D': TaskD(); break;
		case 'E': TaskE(); break;
		case 'F': TaskF(); break;
		case 'G': TaskG(); break;
		case 'H': TaskH(); break;
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
	cout << "\n\tAddress of Dynamic array:" << dataset.data() << endl;
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
	while (true)
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

		case 'r':
			return 1; // Return to main menu

		case 'a':
		{
			int value = inputInteger("\n\tSpecify an integer value to be inserted to the Dataset: ");
			dataset.append(value);
			cout << "\n\t" << value << " has been inserted";
			system("pause");
			break;
		}

		case 'b':
		{
			int count = inputInteger("\n\tSpecify a number of values to be randomly generated into the Dataset: ", 1, 1000);
			srand(static_cast<unsigned>(time(nullptr)));
			for (int i = 0; i < count; i++)
			{
				int value = rand() % 100 + 1;
				dataset.append(value);
			}

			cout << "\n\tCONFIRMATION: Inserted " << count << " random values into the Dataset.";
			cout << "\n\n";
			system("pause");

		}
			break;
		case 'c': readFromFile(); break;

		default:
			cout << "\n\tInvalid option. Try again.\n";
			break;
		}
	}

}

void readFromFile()
{
	Statistical stats(dataset);
	string filename = inputString("\n\tSpecify a data text file name to read: ", false);

	try
	{
		//stats.loadFromFile(filename);
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
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


void TaskA()
{
	Statistical stats(dataset);

	try
	{
		double Minimum = stats.minimum();
		cout << "\n\tMinimum = " << Minimum;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskB()
{
	Statistical stats(dataset);

	try
	{
		double Maximum = stats.maximum();
		cout << "\n\tMaximum = " << Maximum;
	}
	catch (const std::exception& e)
	{
		cerr << e.what(); 
	}

}

void TaskC()
{
	Statistical stats(dataset);

	try
	{
		double Range = stats.range();
		cout << "\n\tRange = " << Range;
	}
	catch (const std::exception& e)
	{
		cerr << e.what(); 
	}

}

void TaskD()
{
	Statistical stats(dataset);

	double Size = dataset.size();
	cout << "\n\tSize = " << Size;
	

}

void TaskE()
{
	Statistical stats(dataset);

	try
	{
		double Sum = stats.sum();
		cout << "\n\tSum = " << Sum;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}

void TaskF()
{
	Statistical stats(dataset);

	try
	{
		double Mean = stats.mean();
		cout << "\n\tMean = " << fixed << setprecision(2) << Mean << defaultfloat;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskG()
{
	Statistical stats(dataset);

	try
	{
		double Median = stats.median();
		cout << "\n\tMedian = " << fixed << setprecision(2) << Median << defaultfloat;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskH()
{
	Statistical stats(dataset);

	try
	{
		int modeCount = 0;
		double* modes = stats.mode(modeCount);

		cout << "\n\tMode(s) = ";
		for (int i = 0; i < modeCount; i++)
			cout << modes[i] << " ";

		delete[] modes; // free memory
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}

void TaskI()
{
	Statistical stats(dataset);

	try
	{
		double stddev = stats.standardDeviation();
		cout << "Sample standard deviation =  " << stddev;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskJ()
{
	Statistical stats(dataset);

	try
	{
		double vrnce = stats.variance();
		cout << "Variance =  " << vrnce;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}
void TaskK()
{
	Statistical stats(dataset);

	try
	{
		double mdrnge = stats.midRange(); 
		cout << "Midrange =  " << mdrnge; 
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskL()
{
	Statistical stats(dataset);

	try
	{
		double iqr = stats.quartiles();
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}
	
}

void TaskM()
{
	//needs to only reurn IQR
	Statistical stats(dataset);

	try
	{
		double iqr = stats.quartiles();
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskN()
{
	Statistical stats(dataset);

	try
	{
		double out = stats.outliers();
		cout << "Outliers =  " << out;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}

void TaskO()
{
	Statistical stats(dataset);

	try
	{
		double sumsquares = stats.SumOfSquares();
		cout << "Sum of Squares = " << sumsquares;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

}

void TaskP()
{
	Statistical stats(dataset);

	try
	{
		double mnabsdeviation = stats.meanAbsoluteDeviation();
		cout << "Mean Absolute Deviation = " << mnabsdeviation;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}

void TaskQ()
{
	Statistical stats(dataset);

	try
	{
		double rtmeansquare = stats.rootMeanSquare();
		std::cout << "Root Mean Square = " << rtmeansquare;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}


}
