#include "genotipo.h"


genotipo::genotipo()
{
}
genotipo::~genotipo()
{
}
int genotipo::getVolume() { return this->volume; };
int genotipo::getValue() { return this->value; };

void genotipo::setVolume(int wert) { volume = wert; };
void genotipo::setValue(int wert) { value = wert; };

