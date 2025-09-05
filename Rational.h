#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <exception>
#include <iostream>
#include <list>
#include <cmath>
#include <string>
using std::to_string;
using std::exception;
using std::ostream;
using namespace std;

/*


class for a rational number.

side note, to normalize a value, first change the
desired value, such as the numerator, then call the
normalize function to update the GCF.

When changing the denominator, if zero if entered,
an exception will be thrown!
*/
class Rational {
private:
	short numerator;
	short denominator;


	/*
@brief uses the euclidian method of obtaining the gcf between two
numbers.
@param short - the higher value between the two.
@param short - the lower value between the two.
@return short - gcf of the interval. */
	short getGcf(short higherVal, short lowerVal) {
		if (lowerVal == 0)return higherVal;
		short x = higherVal;
		short y = lowerVal;
		short result = x % y;

		x = y;
		y = result;

		return getGcf(x, y);
		while (y != 0) {
			short result = x % y;
			x = y;
			y = result;
		}


		return x;
	}

public:


	/*
	@brief exception class to be thrown if division by zero is
	attempted. */
	class divisionByZero :public exception {
	private:
		const char* msg;
	public:
		divisionByZero(const char* msg) : msg(msg) {};

		const char* what() const noexcept override {
			return msg;
		}
	};



	Rational() {
		numerator = 1;
		denominator = 1;
	}
	//copy constructor
	Rational(const Rational& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	Rational(Rational&& other)noexcept {
		denominator = other.denominator;
		numerator = other.numerator;
		other.denominator = 1;
		other.numerator = 1;
	}
	//@param short - numerator to set.
	void setNumerator(short numer) {
		numerator = numer;

	};

	//@param short - denominator to set.
	//@brief throws an exception in denominator is 0. 
	void setDenominator(short denom) {
		if (denom == 0) {
			throw divisionByZero("\tERROR: DIVISION BY ZERO ATTEMPTED. ");
		}
		else {
			denominator = denom;
		}
	}
	//@return short - numerator of current Rational instance. 
	short getNumerator()const {
		return numerator;
	}

	//@return short - denominator of current Rational instance. 
	short getDenominator()const {
		return denominator;
	}

	/*
	@brief simplifies the instance. */
	void normalize() {
		bool denomIsNeg = false;
		bool numeIsNeg = false;

		short newNumerator = getNumerator();
		short newDenominator = getDenominator();

		if (newNumerator < 0 && newDenominator < 0) {
			newNumerator *= -1;
			newDenominator *= -1;
		}
		else if (newNumerator < 0) {
			numeIsNeg = true;
			newNumerator *= -1;
		}
		else if (newDenominator < 0) {
			denomIsNeg = true;
			newDenominator *= -1;
		}

		short lowerValue = ((newNumerator <= newDenominator) ? newNumerator : newDenominator);
		short biggerValue = ((newNumerator >= newDenominator) ? newNumerator : newDenominator);

		short gcf = getGcf(lowerValue, biggerValue);

		newNumerator /= gcf;
		newDenominator /= gcf;


		if (numeIsNeg || denomIsNeg) {
			newNumerator *= -1;
		}

		numerator = newNumerator;
		denominator = newDenominator;
	}


	//@return float - numerator divided by the denominator (denominator is non-zero).
	decltype(numerator / (float)denominator) getResult()const {
		return numerator / (float)denominator;
	}


	/*
	@param const Rational& - other instance to compare if less than.
	@return bool - true if current object is less than. */
	bool operator<(const Rational& other) {
		return (other.getResult() < this->getResult());
	}
	bool operator<(const Rational& other)const {
		return (other.getResult() < this->getResult());
	}
	/*
	@param const Rational& - the Rational instance to compare.
	@return bool - true if current object is greater than the other. */
	bool operator>(const Rational& other) {
		return (other.getResult() > this->getResult());
	}
	bool operator>(const Rational& other) const {
		return (other.getResult() > this->getResult());
	}



	/*
	@param const Rational& - the other to copy from. no move sematics involved.
	@return Rational& - address of the current object returned. */
	Rational& operator=(const Rational& other) {
		if (this != &other) {
			this->numerator = other.numerator;
			this->denominator = other.denominator;
		}
		return *this;
	}

	/*
	@param const pair <short, short>& - the numerator and denominator pair.
	@return Rational& - the address of the Rational object mutated. */
	Rational& operator=(const std::pair<short, short>& pair) {
		setNumerator(pair.first);
		setDenominator(pair.second);
	}
	/*
	@param Rational&& - RValue of a Rational instance to move data from.
	@return Rational& - the address from current mutated object. */
	Rational& operator= (Rational&& other)noexcept {
		if (this != &other) {
			this->numerator = other.numerator;
			other.numerator = 1;
			this->denominator = other.denominator;
			other.denominator = 1;
		}
		return *this;
	}

	// Addition
	Rational operator+(const Rational& other) const {
		Rational result;
		result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		result.denominator = this->denominator * other.denominator;
		result.normalize();
		return result;
	}

	// Subtraction
	Rational operator-(const Rational& other) const {
		Rational result;
		result.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		result.denominator = this->denominator * other.denominator;
		result.normalize();
		return result;
	}

	// Multiplication
	Rational operator*(const Rational& other) const {
		Rational result;
		result.numerator = this->numerator * other.numerator;
		result.denominator = this->denominator * other.denominator;
		result.normalize();
		return result;
	}

	// Division
	Rational operator/(const Rational& other) const {
		if (other.numerator == 0) {
			throw divisionByZero("\tERROR: Division by zero Rational attempted.");
		}
		Rational result; 
		result.numerator = this->numerator * other.denominator;
		result.denominator = this->denominator * other.numerator;
		result.normalize(); 
		return result;
	}

	/*
	@param const Rational& - other instance to compare if not equal.
	@return bool - true if they're equal. */
	bool operator!=(const Rational& other) {
		if (this->denominator != other.denominator && this->numerator != other.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	/*
	@param const Rational& - other instance to compare.
	@return bool - true if they're equal. */
	bool operator==(const Rational& other) {
		if (this->denominator == other.denominator && this->numerator == other.numerator) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(const Rational& other) const {
		if (this->denominator == other.denominator && this->numerator == other.numerator)
			return true;
		return false;
	}
	/*
	#param ostream& - output stream buffer to insert data into.
	@param const Rational& - Rational instance to display.
	@return ostream& - output stream with data stored. */

	friend ostream& operator<<(ostream& os, const Rational& obj) {
		os << obj.numerator << "/" << obj.denominator;
		return os;

	}

	operator std::string() const {
		return (to_string(numerator) + "/" + to_string(denominator));
	}
	operator double() const {
		return getResult();
	}

};

#endif