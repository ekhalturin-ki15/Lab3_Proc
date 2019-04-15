#pragma once

#include <string>
#include <vector>
#include <fstream>

const std::vector<std::string> BwhereItGrows = { "тундре", "пустыни", "степи", "арктике" };
const std::vector<std::string> watIsMonth = { "январь", "февраль", "март", "апрель", "май","июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };

struct Bush
{
	int month;
	int WIG;
};

void InBush(std::ifstream& infile, Bush& b);
void OutBush(std::ofstream& outfile, Bush b);
