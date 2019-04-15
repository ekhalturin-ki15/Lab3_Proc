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
	outfile << "��� ������, ";

	if (1 <= f.type && f.type <= watIsType.size())
	{
		outfile << "��� ������ - " << watIsType[f.type - 1];
	}
	else
	{
		outfile << "��� �������� �����������";
	}

	if ((1 <= f.WIG) && (f.WIG <= FwhereItGrows.size()))
	{
		outfile << "; ����� � " << FwhereItGrows[f.WIG - 1];
	}
	else
	{
		outfile << "; ��������� �������� �����������";
	}
}


