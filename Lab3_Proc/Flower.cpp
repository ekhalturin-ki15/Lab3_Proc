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

	if (1 <= f.type && f.type <= watIsType.size())
	{
		outfile << "тип цветка - " << watIsType[f.type - 1];
	}
	else
	{
		outfile << "тип считался некорректно";
	}
}


