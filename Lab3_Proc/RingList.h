#pragma once

//Элемент контейнера кольцевой двусвязанный список
template <typename Data>
class ElementRL
{
public:
	Data data;
	ElementRL<Data>* next;
	ElementRL<Data>* prev;
};



//Объявление двусвязанного списка
template <typename DataRL>
class RingList
{
public:

	RingList();

	~RingList();

	// Положить в конец
	void PushBack(DataRL& object);

	//void In(ifstream &infile);

	ElementRL<DataRL>* begin();

	////Удалить
	void Clear();

	int WatAmount();


private:

	ElementRL<DataRL>* start;
	int amountEl;

};



//При использовании шаблонов, реализацию нельзя разделять, так как она требуется на этапе компановки


template <typename  DataRL>
RingList<DataRL>::RingList()
{

	start = 0;
	amountEl = 0;
}

template <typename  DataRL>
RingList<DataRL>::~RingList()
{
	Clear();
}

template <typename  DataRL>
ElementRL<DataRL>* RingList<DataRL>::begin()
{
	return start;
}


template <typename  DataRL>
void RingList<DataRL>::PushBack(DataRL& object)
{


	ElementRL<DataRL>* newEl;
	newEl = new ElementRL<DataRL>;


	if (start)
	{
		start->prev->next = newEl;
		newEl->prev = start->prev;
		newEl->next = start;
		newEl->data = object;
		start->prev = newEl;
		start->prev = start->prev;
	}
	else
	{
		start = newEl;
		start->next = start;
		start->prev = start;
		start->data = object;
	}
	this->amountEl++;
}



//Общий код для конструктора и для очищения контейнера
template <typename  DataRL>
void RingList<DataRL>::Clear()
{
	ElementRL<DataRL>* it = this->begin();
	ElementRL<DataRL>* nextit = 0;
	if (it != 0) nextit = it->next;
	for (int i = 0; i < this->WatAmount(); i++)
	{
		delete it;
		it = nextit;
		nextit = nextit->next;
	}

	amountEl = 0;
	start = 0;
}

template <typename  DataRL>
int RingList<DataRL>::WatAmount()
{
	return this->amountEl;
}