#include "Flower.h"
#include <set>

void InFlower(std::ifstream& infile, Flower& f)
{
	infile >> f.type >> f.WIG;
	//if (s.length() < 20)
	//	strcpy_s(f.name, s.c_str());
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

	if ((1 <= f.WIG) && (f.WIG <= FwhereItGrows.size()))
	{
		outfile << "; Растёт в " << FwhereItGrows[f.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}
}


