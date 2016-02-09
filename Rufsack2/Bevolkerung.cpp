#include "Bevolkerung.h"
Bevolkerung::Bevolkerung()
{
}
Bevolkerung::~Bevolkerung()
{
}

int Bevolkerung::getCompleteBevolkFitness() //revisa que los objetos no rompan la mochila y saca el fitness de toda la población
{ 
	GA::totalFitness = 0;
	int jetztVolume;
	int jetztValue;
	int position;
	bool vertig;
	vector<chromosom>::iterator i_crombevolkerung;
	vector<bool>::iterator i_crombevolk;
		for (i_crombevolkerung = cromoBevolkerung.begin(); i_crombevolkerung != cromoBevolkerung.end();i_crombevolkerung++) {
			position = 0;
			jetztValue = 0;
			jetztVolume = 0;
			vertig = false;
			i_crombevolkerung->fitness = 0;
			while (vertig == false){
				for (i_crombevolk = i_crombevolkerung->v_chrom.begin(); i_crombevolk != i_crombevolkerung->v_chrom.end();i_crombevolk++) {
					if (*i_crombevolk == true){
						jetztValue += bevolkerung.at(position).getValue();
						jetztVolume += bevolkerung.at(position).getVolume();
					}
					position++;
				}
				if (jetztVolume <= GA::rufsackG)
				{
					vertig = true;
					i_crombevolkerung->fitness = 0;
				}
				else{
					vertig = false;
					position = 0;
					jetztValue = 0;
					jetztVolume = 0;
					i_crombevolkerung->fitness = 0;
					int zpos = GA::zufallNummer(0, i_crombevolkerung->v_chrom.size() - 1);
					i_crombevolkerung->v_chrom.at(zpos) = !i_crombevolkerung->v_chrom.at(zpos);
				}
			}
			GA::totalFitness += jetztValue;
		}
		return totalFitness;
};

void Bevolkerung::printIT() {
	//cout << "quibo que esta pasando aqui?" << endl;
	vector<chromosom>::iterator i_crombevolkerung;
	vector<bool>::iterator i_crombevolk;
	int valCrom;
	//cout << "1";
	for (i_crombevolkerung = cromoBevolkerung.begin();i_crombevolkerung != cromoBevolkerung.end();i_crombevolkerung++) {
		for (i_crombevolk = i_crombevolkerung->v_chrom.begin();i_crombevolk != i_crombevolkerung->v_chrom.end();i_crombevolk++) {
			valCrom = *i_crombevolk;
			cout << valCrom <<" ";
			//cout << "sup hommie" << endl;
		}
		cout << endl;
	}
};

void Bevolkerung::bevolkerungGenerieren(int grosse, bool zufall) 
{
	//vector<bool> crombevolk;
	chromosom crombevolk;
	int crom = 0;
	int gen = 0;

	if (!zufall ) {//genera población inicial
		for (gen = 0; gen < GA::bevolkerungGrosse;gen++) {
			crombevolk.v_chrom.clear();
			crombevolk.fitness = 0;
			for (crom = 0; crom < genotipo::size;crom++) {
				crombevolk.v_chrom.push_back(GA::zufallNummer(0,1));
			}
			cromoBevolkerung.push_back(crombevolk);
		}
	}
	else
	{
		//cout << "somethingwentwronghere ->" << endl;
	}

}

void Bevolkerung::aufnehemen()//obtiene los objetos a escoger y capacidad de mochila
{
	bool accept = true;
	genotipo gen;
	int wert;
	cout << endl << "ingresa la capacidad de la mochila ";
	cin >> wert;
	GA::rufsackG = wert;
	while (accept) {
		cout << "ingresa valor ";
		cin >> wert;
		gen.setValue(wert);

		cout << endl << "ingresa volumen ";
		cin >> wert;
		gen.setVolume(wert);

		bevolkerung.push_back(gen);
		cout << "weiter? 1/0 ";
		cin >> accept;
	}
	genotipo::size = bevolkerung.size();
}
