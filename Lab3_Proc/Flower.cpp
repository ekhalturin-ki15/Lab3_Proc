#include "Flower.h"
#include <set>

void InFlower(std::ifstream& infile, Flower& f)
{
	infile >> f.type;

}



void OutFlower(std::ofstream& outfile, Flower f)
{
	outfile << "��� ������, ";

	if (1 <= f.type && f.type <= watIsType.size())
	{
		outfile << "��� ������ - " << watIsType[f.type - 1];
	}
	else
	{
		outfile << "��� �������� �����������";
	}
}


