#include "Tree.h"
#include <set>

void InTree(std::ifstream& infile, Tree& t)
{
	infile >> t.year >> t.WIG;

}


void OutTree(std::ofstream& outfile, Tree t)
{
	outfile << "Это дерево, ";

	outfile << "ему " << t.year << " лет, ";

	if ((1 <= t.WIG) && (t.WIG <= TwhereItGrows.size()))
	{
		outfile << "; Растёт в " << TwhereItGrows[t.WIG - 1];
	}
	else
	{
		outfile << "; Местность введенна некорректно";
	}

}
