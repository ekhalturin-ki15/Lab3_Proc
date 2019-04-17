#pragma once

#include <string>
#include <vector>
#include <fstream>

const std::vector<std::string> watIsMonth = { "январь", "февраль", "март", "апрель", "май","июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };

struct Bush
{
	int month;
};

void InBush(std::stringstream& stream, Bush& b);
void OutBush(std::ofstream& outfile, Bush b);
