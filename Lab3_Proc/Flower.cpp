#include "Flower.h"
#include <set>
#include <sstream>

void InFlower(std::stringstream& stream, Flower& f)
{
	f.type = 0;
	stream >> f.type;
}



void OutFlower(std::ofstream& outfile, Flower f)
{
	outfile << "Это цветок, ";
	outfile << "тип цветка - " << watIsType[f.type - 1];
}


