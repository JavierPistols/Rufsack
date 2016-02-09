#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include "genotipo.h"
#include "GA.h"
#include "chromosom.h"
using namespace std;
class Bevolkerung
{
public:
	Bevolkerung();
	~Bevolkerung();
	void bevolkerungGenerieren(int grosse,bool zufall = true);
	int getCompleteBevolkFitness();
	void aufnehemen();
	void printIT();
private:
	int totalFitness;

	vector<chromosom> cromoBevolkerung;
	vector<chromosom> cromoBevolkerung1;

	//vector<vector<bool>> cromoBevolkerung1;
	vector<genotipo> bevolkerung;
	genotipo gen;
};



