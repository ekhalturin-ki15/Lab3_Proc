#include "Bush.h"

void InBush(std::ifstream& infile, Bush& b)
{
	std::string s;
	infile >> b.month >> s;
	if (s.length() < 20)
		strcpy_s(b.name, s.c_str());
}



void OutBush(std::ofstream& outfile, Bush b)
{

	outfile << "Это кустарник, ";

	if (1 <= b.month && b.month <= watIsMonth.size())
	{
		outfile << "месяц цветения - " << watIsMonth[b.month - 1];

	}
	else
	{
		outfile << "месяц цветения считался некорректно";
	}

	outfile << ", Его название: " << b.name << "\n";

}