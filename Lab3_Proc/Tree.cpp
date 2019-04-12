#include "Tree.h"

void InTree(std::ifstream& infile, Tree& t)
{
	std::string s;
	infile >> t.year >> s;
	if (s.length() < 20)
		strcpy_s(t.name, s.c_str());
}


void OutTree(std::ofstream& outfile, Tree t)
{
	outfile << "��� ������, ";

	outfile << "��� " << t.year << " ���, ";

	outfile << "��� ��������: " << t.name << "\n";
}