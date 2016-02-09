#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
#include "genotipo.h"
#include "chromosom.h"
using namespace std;

class GA
{
public:
	GA();
	~GA();
	
	static int rufsackG;
	static int bevolkerungGrosse;
	static int totalFitness;
	static double zufallNummer(int min, int max);
	static double zufallNummer(double min, double max);
	static chromosom auswahl(vector<chromosom>& r_cromBevolke);
	static chromosom kreuzung(vector<chromosom>& r_cromBevolke2,chromosom& vater,chromosom& mutter);
};