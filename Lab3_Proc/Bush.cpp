#include "Bush.h"
#include <set>
#include <sstream>

void InBush(std::stringstream& stream, Bush& b)
{
	b.month = 0;
	stream >> b.month;
}



void OutBush(std::ofstream& outfile, Bush b)
{
	outfile << "Это кустарник, ";
	outfile << "месяц цветения - " << watIsMonth[b.month - 1];
}