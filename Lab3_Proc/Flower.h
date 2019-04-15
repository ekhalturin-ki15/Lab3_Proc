#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

const std::vector<std::string> watIsType = { "��������", "�������", "�����", "������", "������" };
const std::vector<std::string> FwhereItGrows = { "������", "�������", "�����", "�������" };

struct Flower
{
public:
	int type;
	int WIG;
};

void InFlower(std::ifstream& infile, Flower& f);
void OutFlower(std::ofstream& outfile, Flower f);
