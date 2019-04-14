#include "Tree.h"
#include <set>

void InTree(std::ifstream& infile, Tree& t)
{
	std::string s;
	infile >> t.year >> s;
	if (s.length() < 20)
		strcpy_s(t.name, s.c_str());
}


void OutTree(std::ofstream& outfile, Tree t)
{
	outfile << "Кол-во согласных в названии = " << TreeAmount(t) << " ; ";

	outfile << "Это дерево, ";

	outfile << "ему " << t.year << " лет, ";

	outfile << "Его название: " << t.name << "\n";
}

int TreeAmount(Tree t)
{
	int all = 0;
	std::set<char> gl = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' };
	std::string name = t.name;

	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}