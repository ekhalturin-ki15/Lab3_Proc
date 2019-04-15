#include "Flower.h"
#include <set>

void InFlower(std::ifstream& infile, Flower& f)
{
	infile >> f.type;

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


