#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "input.h"
#include <unordered_map>
#include <fstream>
#include "DynamicArray.h"
#include "Statistical.h"

using namespace std;
DynamicArray<int> dataset;

char menuOption();
void OptionOne();
void OptionTwo();
void OptionThree();
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
void TaskR();
void TaskS();
void TaskT();
void TaskU();
void TaskV();
void TaskW();
void TaskX();
void TaskY(); 
void TaskZ();
int main()
{

	cout << "\n\tWhat are Descriptive Statistics?";
	cout << "\n\n\tDescriptive statistics summarize certain aspects of a data set (Sample or Population) using numeric calculations.";
	cout << "\n\thttps://www.calculatorsoup.com/calculators/statistics/descriptivestatistics.php.";

	system("pause");
	system("cls");

	do
	{
		switch (menuOption())
		{
		case '0': exit(0); break;
		case '1': OptionOne(); break;
		case '2': OptionTwo(); break;
		case '3': OptionThree(); break;

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
			 case 'R': TaskR(); break;
			 case 'S': TaskS(); break;
			 case 'T': TaskT(); break;
			 case 'U': TaskU(); break;
			 case 'V': TaskV(); break;
			 case 'W': TaskW(); break;
			 case 'X': TaskX(); break;
			 case 'Y': TaskY(); break;
			 case 'Z': TaskZ(); break;
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
	cout << "\n\tDescriptive Statistics Calculator Main Menu";
	cout << "\n\t================================================================================";
	cout << "\n\t0.Exit";
	cout << "\n\t1. Configure Dataset to Sample or Population";
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

void OptionOne()

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

	return;
}


void OptionTwo()

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
			return; // Return to main menu

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
	std::string filename;
	std::cout << "\n\tEnter filename to read from: ";
	std::cin >> filename;

	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "\n\tERROR: Could not open file " << filename << std::endl;
		system("pause");
		return;
	}

	int value;
	int count = 0;
	while (inFile >> value) {
		dataset.append(value);
		count++;
	}

	inFile.close();
	std::cout << "\n\tCONFIRMATION: Inserted " << count << " values from file into the Dataset.\n";
	system("pause");
}


void OptionThree()
{
	int f_value = 0;
	char i_choice = 'A';
	bool oneOrAll = false;
	char choice = 'A';
	int starting_index = 0;
	int ending_index = 0;

	system("cls");
	cout << "\n\tDelete Dataset Menu";
	cout << "\n\tA. delete a value";
	cout << "\n\t B. delete a range of values";
	cout << "\n\tC. delete all values";
	cout << "\n\t ============================================================";
	cout << "\n\tR. Return";
	cout << "\n\t ============================================================";
	choice = inputChar("\tOption:","ABCR");

	switch (choice) {
	case 'A':
		
		f_value = inputInteger("\n\tSpecify an integer value to find and be deleted from the Dataset:", true);

		i_choice = inputChar("Delete *-all elements or 1-one element found with value 1?", "1*");
		if (i_choice == '*') { oneOrAll = true; }
		else { oneOrAll = false; };

		dataset.erase(f_value, oneOrAll);
		break;
	case 'B':
		

		starting_index = inputInteger("\n\tSpecify a starting integer value to be deleted from the dataset: ", 0, dataset.size()-1);
		ending_index = inputInteger("\n\tSpecify an ending integer value to be deleted from the Dataset: ", 0, dataset.size()-1);
		cout << "\n";
		for (int i = starting_index; i <= ending_index;i++)
			dataset.remove(i);

		cout << "CONFIRMATION: ELEMENT(s): " << ((ending_index - starting_index) + 1) << "have been deleted. " << endl;

		system("pause");

		break;
	case 'C':

		for (int i = 0; i < dataset.size();i++)
			dataset.remove(i);

		cout << "\n\tDataset has been purged of all elements. " << endl;
		system("pause");

		break;
	case 'R':
		return;
	}

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

void TaskI()
{

	Statistical stats(dataset);
	double stddev = stats.standardDeviation();
	std::cout << "Sample standard deviation =  " << stddev;

}

void TaskJ()
{
	Statistical stats(dataset);
	double vrnce = stats.variance();
	std::cout << "Variance =  " << vrnce;


}
void TaskK()
{
	Statistical stats(dataset);
	double mdrnge = stats.midRange();
	std::cout << "Midrange =  " << mdrnge;


}

void TaskL()
{
	Statistical stats(dataset);
	double iqr = stats.quartiles();

}

void TaskM()
{
	//needs to only reurn IQR
	Statistical stats(dataset);
	double iqr = stats.quartiles();

}

void TaskN()
{
	Statistical stats(dataset);
	double out = stats.outliers();
	std::cout << "Outliers =  " << out;

}

void TaskO()
{
	Statistical stats(dataset);
	double sumsquares = stats.SumOfSquares();
	std::cout << "Sum of Squares = " << sumsquares;

}

void TaskP()
{
	Statistical stats(dataset);
	double mnabsdeviation = stats.meanAbsoluteDeviation();
	std::cout << "Mean Absolute Deviation = " << mnabsdeviation;

}

void TaskQ()
{
	Statistical stats(dataset);
	double rtmeansquare = stats.rootMeanSquare();
	std::cout << "Root Mean Square = " << rtmeansquare;

}


void TaskR() {
	try {
		Statistical stats(dataset);
		cout << "\n\n" << "Standard Error Of the Mean: " << stats.standardErrorOfMean() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskS() {
	try {
		Statistical stats(dataset);
		cout << "\n\n\t" << "Skewness: \t" << stats.skewness() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskT() {
	try {
		Statistical stats(dataset);
		cout << "\n\n\t" << "Kurtosis:\t" << stats.kurtosis() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskU() {
	try {
		Statistical stats(dataset);
		cout << "\n\n\t" << "Kurtosis Excess:\t" << stats.kurtosisExcess() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskV() {
	try {
		Statistical stats(dataset);
		cout << "\n\n\t" << "Coefficient of Variation:\t" << stats.coefficientVariation() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskW() {
	try {
		Statistical stats(dataset);
		cout << "\n\n\t" << "Relative Standard Deviation:\t" << stats.relativeStandardDeviation() << "\n\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n\n";
	}
}
void TaskX() {
	if (dataset.size() == 0) {
		cerr << "\n\tERROR: EMPTY DATASET ENTERED. " << endl;
	}
	else {
		Statistical stats(dataset);

		unordered_map<int, int> frequency_table = stats.getFrequency();

		// Loop through and print
		for (const std::pair<const int, int>& display : frequency_table) {
			cout << "\n\tValue: " << display.first
				<< " -> Frequency: " << display.second << '\n';
		}
	}
}

void TaskY() {

	bool populationOrSample = true; // placeholder (true = sample, false = population)

	Statistical stats(dataset);

	const int labelWidth = 30;

	cout << left; 
	cout << setw(labelWidth) << "\tMinimum:" << stats.minimum() << endl;
	cout << setw(labelWidth) << "\tMaximum:" << stats.maximum() << endl;
	cout << setw(labelWidth) << "\tRange:" << stats.range() << endl;
	cout << setw(labelWidth) << "\tSum:" << stats.sum() << endl;
	cout << setw(labelWidth) << "\tMean:" << stats.mean() << endl;
	cout << setw(labelWidth) << "\tMedian:" << stats.median() << endl;

	int modeCount = 0;
	double* modes = stats.mode(modeCount);
	cout << setw(labelWidth) << "\tMode(s):";
	for (int i = 0; i < modeCount; i++) {
		cout << modes[i] << " ";
	}
	cout << endl;
	delete[] modes;

	cout << setw(labelWidth) << "\tVariance:" << stats.variance(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tStandard Deviation:" << stats.standardDeviation(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tMid-Range:" << stats.midRange() << endl;
	cout << setw(labelWidth) << "\tQuartiles:" << stats.quartiles() << endl;
	cout << setw(labelWidth) << "\tOutliers:" << stats.outliers() << endl;
	cout << setw(labelWidth) << "\tSum of Squares:" << stats.SumOfSquares() << endl;
	cout << setw(labelWidth) << "\tMean Abs Deviation:" << stats.meanAbsoluteDeviation() << endl;
	cout << setw(labelWidth) << "\tRoot Mean Square:" << stats.rootMeanSquare() << endl;

	cout << setw(labelWidth) << "\tStd Error of Mean:" << stats.standardErrorOfMean(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tSkewness:" << stats.skewness(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tKurtosis:" << stats.kurtosis(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tKurtosis Excess:" << stats.kurtosisExcess(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tCoeff. Variation:" << stats.coefficientVariation(populationOrSample) << endl;
	cout << setw(labelWidth) << "\tRel. Std Deviation:" << stats.relativeStandardDeviation(populationOrSample) << endl;

	unordered_map<int, int> freqTable = stats.getFrequency();
	cout << "\n\tFrequencies:\n";
	for (const pair<const int, int>& kv : freqTable) {
		cout << setw(labelWidth) << ("\tValue: " + to_string(kv.first))
			<< kv.second << endl;
	}
}

void TaskZ() {
	string filename;
	bool populationOrSample = false;
	Statistical stats(dataset);

	const int labelWidth = 30;

	filename = inputString("\n\tEnter the filename to save results: ", false);

	ofstream outFile(filename);
	if (!outFile) {
		cerr << "Error: could not open file " << filename << endl;
		return;
	}

	const int labelWidth = 30;
	outFile << left;

	// Anthony's Portion
	outFile << setw(labelWidth) << "\tMinimum:" << stats.minimum() << endl;
	outFile << setw(labelWidth) << "\tMaximum:" << stats.maximum() << endl;
	outFile << setw(labelWidth) << "\tRange:" << stats.range() << endl;
	outFile << setw(labelWidth) << "\tSum:" << stats.sum() << endl;
	outFile << setw(labelWidth) << "\tMean:" << stats.mean() << endl;
	outFile << setw(labelWidth) << "\tMedian:" << stats.median() << endl;

	int modeCount = 0;
	double* modes = stats.mode(modeCount);
	outFile << setw(labelWidth) << "\tMode(s):";
	for (int i = 0; i < modeCount; i++) {
		outFile << modes[i] << " ";
	}
	outFile << endl;
	delete[] modes;

	// Daisy's Portion
	outFile << setw(labelWidth) << "\tVariance:" << stats.variance(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tStandard Deviation:" << stats.standardDeviation(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tMid-Range:" << stats.midRange() << endl;
	outFile << setw(labelWidth) << "\tQuartiles:" << stats.quartiles() << endl;
	outFile << setw(labelWidth) << "\tOutliers:" << stats.outliers() << endl;
	outFile << setw(labelWidth) << "\tSum of Squares:" << stats.SumOfSquares() << endl;
	outFile << setw(labelWidth) << "\tMean Abs Deviation:" << stats.meanAbsoluteDeviation() << endl;
	outFile << setw(labelWidth) << "\tRoot Mean Square:" << stats.rootMeanSquare() << endl;

	// Pedro's Portion
	outFile << setw(labelWidth) << "\tStd Error of Mean:" << stats.standardErrorOfMean(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tSkewness:" << stats.skewness(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tKurtosis:" << stats.kurtosis(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tKurtosis Excess:" << stats.kurtosisExcess(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tCoeff. Variation:" << stats.coefficientVariation(populationOrSample) << endl;
	outFile << setw(labelWidth) << "\tRel. Std Deviation:" << stats.relativeStandardDeviation(populationOrSample) << endl;

	// Frequency Table
	unordered_map<int, int> freqTable = stats.getFrequency();
	outFile << "\n\tFrequencies:\n";
	for (const pair<const int, int>& kv : freqTable) {
		outFile << setw(labelWidth) << ("\tValue: " + to_string(kv.first))
			<< kv.second << endl;
	}

	outFile.close();
	cout << "Statistics saved to " << filename << endl;
}
