#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

const std::vector<std::string> watIsType = { "домашние", "садовые", "дикие", "редкие", "горные" };

struct Flower
{
public:
	int type;
};

void InFlower(std::ifstream& infile, Flower& f);
void OutFlower(std::ofstream& outfile, Flower f);
