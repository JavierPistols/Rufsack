#pragma once
#include <vector>
using namespace std;
class chromosom
{
public:
	chromosom();
	~chromosom();
	int fitness;
	double Wahrscheinlichkeit;//probabilidad
	vector<bool> v_chrom;
};

