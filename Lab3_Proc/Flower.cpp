#include "Flower.h"
#include <set>

void InFlower(std::ifstream& infile, Flower& f)
{
	std::string s;
	infile >> f.type >> s >> f.WIG;
	if (s.length() < 20)
		strcpy_s(f.name, s.c_str());
}



void OutFlower(std::ofstream& outfile, Flower f)
{
	outfile << "Кол-во согласных в названии = " << FlowerAmount(f) << " ; ";

	outfile << "Это цветок, ";

	if (1 <= f.type && f.type <= watIsType.size())
	{
		outfile << "тип цветка - " << watIsType[f.type - 1];
	}
	else
	{
		outfile << "тип считался некорректно";
	}

	outfile << ", Его название: " << f.name;

	if ((1 <= f.WIG) && (f.WIG <= FwhereItGrows.size()))
	{
		outfile << "; Растёт в " << FwhereItGrows[f.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}
	outfile << std::endl;
}


int FlowerAmount(Flower f)
{
	int all = 0;
	std::set<char> gl = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' };
	std::string name = f.name;

	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}