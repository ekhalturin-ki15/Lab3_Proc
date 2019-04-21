#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "RingList.h"
#include "Bush.h"
#include "Tree.h"

enum Type { tree, bush };

struct Plant
{
	Type key;
	union
	{
		Bush b;
		Tree t;
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
		}
		return *this;
	}


};

void InAll(std::ifstream& infile, RingList<Plant>& container);
void GetFlower(std::ifstream& infile, int type, Plant& object);
void OutAll(std::ofstream& outfile, RingList<Plant> container);

void MultiOutAll(std::ofstream& outfile, RingList<Plant> container);

void Sort(RingList<Plant>& container);

void QSort(std::vector<ElementRL<Plant>*>& mass, int l, int r);

int cmp(Plant* l, Plant* r);