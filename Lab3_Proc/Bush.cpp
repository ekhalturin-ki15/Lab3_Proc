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

	outfile << "Ёто кустарник, ";

	if (1 <= b.month && b.month <= watIsMonth.size())
	{
		outfile << "мес€ц цветени€ - " << watIsMonth[b.month - 1];

	}
	else
	{
		outfile << "мес€ц цветени€ считалс€ некорректно";
	}

	outfile << ", ≈го название: " << b.name << "\n";

}