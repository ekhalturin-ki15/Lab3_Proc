#include "Tree.h"
#include <set>
#include <sstream>

void InTree(std::stringstream& stream, Tree& t)
{
	t.year = 0;
	stream >> t.year;

}


bool OutTree(std::ofstream& outfile, Tree t)
{
	outfile << "Это дерево, ";

	outfile << "ему " << t.year << " лет, ";

	return true;

}
