#include "Flower.h"

void InFlower(std::ifstream& infile, Flower& f)
{
	std::string s;
	infile >> f.type >> s;
	if (s.length() < 20)
		strcpy_s(f.name, s.c_str());
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

	outfile << ", Его название: " << f.name << "\n";

}