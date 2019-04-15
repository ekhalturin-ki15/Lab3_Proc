#include "Tree.h"
#include <set>

void InTree(std::ifstream& infile, Tree& t)
{
	infile >> t.year;

}


void OutTree(std::ofstream& outfile, Tree t)
{
	outfile << "Это дерево, ";

	outfile << "ему " << t.year << " лет, ";

}
