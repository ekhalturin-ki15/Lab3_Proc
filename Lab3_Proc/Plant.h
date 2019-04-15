#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "RingList.h"
#include "Bush.h"
#include "Tree.h"
#include "Flower.h"

enum Type { tree, bush, flower };
const std::vector<std::string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };

struct Plant
{
	Type KEY;
	char name[20];
	int WIG;
	union
	{
		Bush b;
		Tree t;
		Flower f;
	};
	Plant() {};
	~Plant() {};
	Plant(const Plant& f) {};
	Plant& operator= (const Plant& object)
	{
		WIG = object.WIG;
		KEY = object.KEY;
		strcpy_s(name,object.name);
		switch (object.KEY)
		{
		case Type::tree:
			t = object.t;
			break;
		case Type::bush:
			b = object.b;
			break;
		case Type::flower:
			f = object.f;
			break;
		}
		return *this;
	}


};

void InAll(std::ifstream& infile, RingList<Plant>& container);
void GetFlower(std::ifstream& infile, int type, Plant& object);
void OutAll(std::ofstream& outfile, RingList<Plant> container, bool filter = false);

void Sort(RingList<Plant>& container);

void QSort(std::vector<ElementRL<Plant>*>& mass, int l, int r);

bool Cmp(Plant* l, Plant* r);

int Amount(Plant& object);

void OutName(std::ofstream& outfile, Plant& plant);