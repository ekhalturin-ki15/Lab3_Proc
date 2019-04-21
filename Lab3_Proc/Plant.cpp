#include "Plant.h"
#include "Tree.h"
#include "Bush.h"
#include "Multi.h"

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



void MultiOutAll(ofstream& outfile, RingList<Plant> container)
{
	ElementRL<Plant>* it = container.begin();
	ElementRL<Plant>* ittoo = container.begin();
	for (int i = 0; i < container.WatAmount(); i++)
	{
		ittoo = it->next;
		for (int j = i+1; j < container.WatAmount(); j++)
		{
			switch (it->data.key)
			{
			case Type::tree:
				switch (ittoo->data.key)
				{
				case Type::tree:
					OutTreeTree(outfile, it->data.t, ittoo->data.t);
					break;
				}
				break;

			case Type::bush:

				OutBush(outfile, it->data.b);
				break;
			
			}
			ittoo = ittoo->next;
		}
		it = it->next;
	}
}