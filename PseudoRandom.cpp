#include "PseudoRandom.h"
#include <unordered_map>
PseudoRandom::PseudoRandom() {
	//default values taken from example in book. 
	seed = 1;
	modulo = 729;
	multiplier = 40;
	increment = 725;
}
PseudoRandom::PseudoRandom(int nModulo, int nMultiplier, int nIncrement) {
	seed = 50;
	modulo = nModulo;
	multiplier = nMultiplier;
	increment = nIncrement;
}

int PseudoRandom::getInt(){
	return intLinearCongruence();
}

double PseudoRandom::getIndirectNext() {
	intLinearCongruence();
	return static_cast<double>(seed) / static_cast<double>(modulo);
}

unordered_map<int, double> PseudoRandom::uniformDistribution(int revs, int intervals) {

	unordered_map<int, double> distribution;

	for (int i = 0; i < revs;i++) {
		distribution[(int)(getIndirectNext()*intervals)]++;
	}
	
	for (int i = 0; i < intervals;i++) {
		distribution[i] /= revs;
		distribution[i] *= 100.0;
	}

	return distribution;

}

double PseudoRandom::gaussianApproximation(double median, double sd,int distributions) {
	if (median < 0 || sd < 0 || distributions < 0) throw std::exception("ERROR: INVALID CALCULATION VALUE. ");
	double sum = 0.0;
	for (int i = 0; i < distributions;i++)
		sum += getIndirectNext();

	double expected_summation = sum - (median * .5);
	return median + expected_summation * sd;
}


bool PseudoRandom::setMultiplier(int nMultiplier) noexcept {
	if (nMultiplier < 0)return false;

	multiplier = nMultiplier;
	return true;
}
int PseudoRandom::getMultiplier() const noexcept{
	return multiplier;
}
bool PseudoRandom::setModulo(int nmodulo) noexcept {
	if (nmodulo <= 0)return false;

	modulo = nmodulo;
	return true;
}
int PseudoRandom::getModulo()const noexcept{
	return modulo;
}
bool PseudoRandom::setSeed(int nSeed) noexcept {
	if (nSeed < 0)return false;

	seed = nSeed;
	return true;
}
int PseudoRandom::getSeed()const noexcept{
	return seed;
}

int PseudoRandom::intLinearCongruence() {
	seed = (multiplier * seed + increment) % modulo;
	return seed;
}
