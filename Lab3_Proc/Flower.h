#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

const std::vector<std::string> watIsType = { "домашние", "садовые", "дикие", "редкие", "горные" };
const std::vector<std::string> FwhereItGrows = { "тундре", "пустыни", "степи", "арктике" };

struct Flower
{
public:
	char name[20];
	int type;
	int WIG;
};

void InFlower(std::ifstream& infile, Flower& f);
void OutFlower(std::ofstream& outfile, Flower f);

int FlowerAmount(Flower f);