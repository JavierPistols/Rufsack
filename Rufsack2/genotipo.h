#pragma once


class genotipo
{
public:
	genotipo();
	~genotipo();
	int getVolume();
	int getValue();
	void setVolume(int wert);
	void setValue(int wert);
	static int size;

private:
	int volume;
	int value;
	
	
};

