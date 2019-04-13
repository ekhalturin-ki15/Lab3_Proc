#include "Plant.h"

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
	switch (object.key)
	{
	case Type::tree:
		InTree(infile, object.t);
		break;
	case Type::bush:
		InBush(infile, object.b);
		break;
	}

}

void OutAll(ofstream& outfile, RingList<Plant> container)
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
			OutBush(outfile, it->data.b);
			break;
		}
		it = it->next;
	}
}

void Sort(RingList<Plant>& container)
{
	vector<Plant*> mass;
	ElementRL<Plant>* it = container.begin();
	for (int i = 0; i < container.WatAmount(); i++)
	{
		mass.push_back(&(it->data));
		it = it->next;
	}

	QSort(mass, 0, mass.size() - 1);
}

void QSort(vector<Plant*> & mass, int l, int r)
{
	int i = l, j = r;
	Plant* p = mass[(l + r) / 2];
	while (true)
	{

		while (cmp(p, mass[i]) == 1) i++;

		while (cmp(p, mass[j]) == -1) j--;

		if (i <= j)
		{
			std::swap(mass[i], mass[j]);

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
		switch (v[i]->key)
		{
		case Type::tree:
			value.push_back(TreeAmount(v[i]->t));

			break;
		case Type::bush:
			value.push_back(BushAmount(v[i]->b));

			break;
		}
	}

	if (value[0] > value[1]) return 1;
	if (value[0] < value[1]) return -1;
	return 0;
}