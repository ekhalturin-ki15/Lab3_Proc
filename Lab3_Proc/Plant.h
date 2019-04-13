#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "RingList.h"
#include "Bush.h"
#include "Tree.h"
#include "Flower.h"

enum Type { tree, bush, flower };

struct Plant
{
	Type key;
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
		key = object.key;
		switch (object.key)
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
void OutAll(std::ofstream& outfile, RingList<Plant> container);

