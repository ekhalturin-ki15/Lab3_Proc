#include "CppUnitTest.h"
#include "../Lab3_Proc/Plant.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace RingListTest
{
	const int MORE = 100;

	void GeneratePlant(RingList<Plant>& MorePlant)
	{
		Plant object;
		//GetPlant("1 100 Деревко 4", object);
		for (int i = 1; i < MORE; i++)
			MorePlant.PushBack(object);
		//GetPlant("3 5 Цветочек 4", object);
		MorePlant.PushBack(object);
	}

	TEST_CLASS(PB)
	{
	public:
		TEST_METHOD(TestP)
		{		
			RingList<Plant> forPlant;
			//GetPlant("1 100 Деревко 4", object);
			forPlant.PushBack(object);
			Assert::AreEqual(string("Деревко"),string(forPlant.begin()->data.name));
		}

		TEST_METHOD(TestPMore)
		{		
			RingList<Plant> forPlant;
			GeneratePlant(forPlant);
			Assert::AreEqual(MORE, forPlant.WatAmount());
		}

		TEST_METHOD(TestPMore2)
		{
			RingList<Plant> forPlant;
			GeneratePlant(forPlant);
			Assert::AreEqual(string("Цветочек"),string(forPlant.begin()->prev->data.name));
		}

		TEST_METHOD(TestPIsTrueRing)
		{
			RingList<Plant> forPlant;
			strcpy_s(object.name, string("Кустик").c_str());
			forPlant.PushBack(object);
			Assert::AreEqual(string("Кустик"),string(forPlant.begin()->next->prev->data.name));
		}

		TEST_METHOD(TestI)
		{
			RingList<int>	forInt;
			int random = rand();
			num = random;
			forInt.PushBack(num);
			Assert::AreEqual(random,forInt.begin()->data);
		}
		TEST_METHOD(TestIIsTrueRing)
		{
			RingList<int>	forInt;
			int random = rand();
			num = random;
			forInt.PushBack(num);
			Assert::AreEqual(random,forInt.begin()->prev->next->data);
		}

	private:
		Plant object;
		int num;
	};

	TEST_CLASS(Empty)
	{
	public:

		TEST_METHOD(Test1)
		{
			ElementRL<Plant>* it = 0;
			Assert::AreEqual(int(it), int(forPlant.begin() ));
		}

		TEST_METHOD(Test1_)
		{
			Assert::AreEqual(0, forPlant.WatAmount());
		}

		TEST_METHOD(Test2)
		{
			ElementRL<int>* it = 0;
			Assert::AreEqual(int(it), int(forPlant.begin()));
		}

	private:
		RingList<Plant> forPlant;
		RingList<int>	forInt;
	};

	TEST_CLASS(Clear)
	{
	public:

		TEST_METHOD(Test)
		{
			RingList<Plant> forPlant;
			GeneratePlant(forPlant);
			forPlant.Clear();
			Assert::AreEqual(0, forPlant.WatAmount());
		}

		TEST_METHOD(Test2)
		{
			RingList<int>	forInt;
			int num = MORE;
			forInt.PushBack(num);
			forInt.Clear();
			Assert::AreEqual(0, forInt.WatAmount());
		}

		TEST_METHOD(Test3)
		{
			RingList<int>	forInt;
			ElementRL<int>* it = 0;
			int num = MORE;
			forInt.PushBack(num);
			forInt.Clear();
			Assert::AreEqual(int(it),int(forInt.begin()));
		}
			
	};

	TEST_CLASS(WhatAmount)
	{
	public:

		TEST_METHOD(Test)
		{
			RingList<Plant> forPlant;
			Plant p; 
			const int All = 5;
			for (int i = 0; i < All; i++) forPlant.PushBack(p);
			Assert::AreEqual(All, forPlant.WatAmount());
		}
	};

	TEST_CLASS(Begin)
	{
	public:

		TEST_METHOD(Test)
		{
			RingList<Plant> forPlant;
			Plant p;
			const int All = 3;
			int random = rand();
			for (int i = 0; i < All; i++) forPlant.PushBack(p);
			forPlant.begin()->data.WIG = random;

			ElementRL<Plant>* it = forPlant.begin();
			for (int i = 0; i < All; i++)
			{
				it = it->prev;
			}
			
			Assert::AreEqual(random, it->data.WIG);
		}
	};

	
}

