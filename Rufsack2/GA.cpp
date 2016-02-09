#include "GA.h"
GA::GA()
{

}
GA::~GA()
{

}

double GA::zufallNummer(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
double GA::zufallNummer(double min, double max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}

chromosom GA::auswahl(vector<chromosom>& r_cromBevolke)
{
	double wahrscheinlichkeit4;
	double total;
	chromosom gewahltAus;
	vector<chromosom>::iterator i_crombevolkerung;
	for (i_crombevolkerung = r_cromBevolke.begin(); i_crombevolkerung != r_cromBevolke.end();i_crombevolkerung++){
		i_crombevolkerung->Wahrscheinlichkeit = i_crombevolkerung->fitness / totalFitness;
	}
	wahrscheinlichkeit4 = zufallNummer(0.0,1.00);
	total = 0;
	for (i_crombevolkerung = r_cromBevolke.begin(); i_crombevolkerung != r_cromBevolke.end();i_crombevolkerung++) {
		total += i_crombevolkerung->Wahrscheinlichkeit;
		if (total > wahrscheinlichkeit4)
		{gewahltAus = *i_crombevolkerung;}
	}
	return gewahltAus;
}

chromosom GA::kreuzung(vector<chromosom>& r_cromBevolke2, chromosom& vatter, chromosom& mutter)
{
	double wahrscheinlichkeit5;
	chromosom neuesKind;
	wahrscheinlichkeit5 = zufallNummer(0.0, 1.0);
	if (wahrscheinlichkeit5 <= .75)
	{
		
	}


}








