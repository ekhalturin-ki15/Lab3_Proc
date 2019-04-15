#include "Plant.h"
#include "Tree.h"
#include "Bush.h"
#include <set>

using namespace std;

void InAll(ifstream& infile, RingList<Plant>& container)
{
	int type;

	while (true)
	{
		type = 0;
		infile >> type;
		if (!type) break;
		Plant object;
		GetFlower(infile, type, object);
		container.PushBack(object);
	}
}

void GetFlower(ifstream& infile, int type, Plant& object)
{
	object.key = static_cast<Type> (type - 1);
	string s;
	infile >> s;
	if (s.length() < 20)
		strcpy_s(object.name, s.c_str());

	switch (object.key)
	{
	case Type::tree:
		InTree(infile, object.t);
		break;
	case Type::bush:
		InBush(infile, object.b);
		break;
	case Type::flower:
		InFlower(infile, object.f);
		break;
	}

}

void OutAll(std::ofstream& outfile, RingList<Plant> container, bool filter)
{
	ElementRL<Plant>* it = container.begin();
	
	for (int i = 0; i < container.WatAmount(); i++)
	{
		switch (it->data.key)
		{
		case Type::tree:
			OutTree(outfile, it->data.t);
			break;
		case Type::bush:
			if (filter) break;
			OutBush(outfile, it->data.b);
			break;
		case Type::flower:
			if (filter) break;
			OutFlower(outfile, it->data.f);
			break;
		}

		OutName(outfile, it->data);

		it = it->next;
	}
}

void Sort(RingList<Plant>& container)
{
	vector<ElementRL<Plant>*> mass;
	ElementRL<Plant>* it = container.begin();
	for (int i = 0; i < container.WatAmount(); i++)
	{
		mass.push_back(it);
		it = it->next;
	}

	QSort(mass, 0, mass.size() - 1);
}

void QSort(vector<ElementRL<Plant>*>& mass, int l, int r)
{
	int i = l, j = r;
	Plant* p = &(mass[(l + r) / 2]->data);
	while (true)
	{

		while (cmp(p, &(mass[i]->data)) == 1) i++;

		while (cmp(p, &(mass[j]->data)) == -1) j--;

		if (i <= j)
		{
			Plant c;
			c = mass[i]->data;
			mass[i]->data = mass[j]->data;
			mass[j]->data = c;

			i++;
			j--;
		}
		if (i > j) break;
	}

	if (l < j) QSort(mass, l, j); //then QuickSort(l, j);
	if (i < r) QSort(mass, i, r); //then QuickSort(i, r);
}

int cmp(Plant* l, Plant* r)
{
	vector<Plant*> v; v.push_back(l); v.push_back(r);
	vector<int> value;
	for (int i = 0; i < 2; i++)
	{
		value.push_back(Amount(*v[i]));
	}

	if (value[0] > value[1]) return 1;
	if (value[0] < value[1]) return -1;
	return 0;
}


int Amount(Plant& object)
{
	int all = 0;
	std::set<char> gl = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' };
	std::string name = object.name;

	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}

void OutName(std::ofstream& outfile, Plant& plant)
{
	outfile << " Его название = " << plant.name << " ; ";
	outfile << "Кол-во согласных в названии = " << Amount(plant);
	outfile << std::endl;
}