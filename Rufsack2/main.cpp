#include <stdio.h>
#include <iostream>
#include <chrono>
#include "Bevolkerung.h"
#include "GA.h"

using namespace std;
int GA::rufsackG = 0;
int genotipo::size = 0;
int GA::bevolkerungGrosse = 10;
int GA::totalFitness = 0;

int main()
{
	Bevolkerung bevel;
	
	bevel.aufnehemen();
	bevel.bevolkerungGenerieren(20,false);
	bevel.printIT();
	cout << bevel.getCompleteBevolkFitness()<<endl;
	bevel.printIT();

	system("pause");
	return 0;
}