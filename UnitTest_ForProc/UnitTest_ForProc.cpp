//#include "pch.h" не используем
#include "CppUnitTest.h"
#include "../Lab3_Proc/Plant.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlantTest
{

	string GetMaxName()
	{
		string s;
		for (int i = 0; i < MLEN; i++) s.push_back('п');
		return s;
	}

	string GetMinName()
	{
		string s;
		for (int i = 0; i < MLEN; i++) s.push_back('ь');
		return s;
	}

	TEST_CLASS(TestAmount)
	{
	public:
		TEST_METHOD(TestAmountMintest)
		{
			Assert::AreEqual(0, Amount(""));
		}

		TEST_METHOD(TestAmountRandtest)
		{
			Assert::AreEqual(3, Amount("МалИнъы"));
		}

		TEST_METHOD(TestAmountMaxtest1)
		{
			Assert::AreEqual(0, Amount(GetMinName()));
		}

		TEST_METHOD(TestAmountMaxtest2)
		{
			Assert::AreEqual(MLEN, Amount(GetMaxName()));
		}

	};

	TEST_CLASS(TestMyTolower)
	{
	public:

		TEST_METHOD(TestMyTolower1)
		{
			Assert::AreEqual('ё', MyTolower('Ё'));
		}

		TEST_METHOD(TestMyTolower2)
		{
			Assert::AreEqual('п', MyTolower('П'));
		}

		TEST_METHOD(TestMyTolower3)
		{
			Assert::AreEqual('р', MyTolower('Р'));
		}

		TEST_METHOD(TestNoMyTolower1)
		{
			Assert::AreEqual('A', MyTolower('A'));
		}

		TEST_METHOD(TestNoMyTolower2)
		{
			Assert::AreEqual('я', MyTolower('я'));
		}
	};

	TEST_CLASS(TestInAll)
	{
	public:

		TestInAll()
		{
			ofstream outfile;
			outfile.open("input test.txt");
			outfile << "1 100 Деревко 4" << endl << "2 5 Кустик 3" << endl << "3 4 Цветок 5";
			outfile.close();
			infile.open("input test.txt");
			InAll(infile, container);
		}
		TEST_METHOD(WatAmount)
		{
			Assert::AreEqual(MUST_A, container.WatAmount());
		}
		TEST_METHOD(WatType)
		{
			ElementRL<Plant>* it = container.begin();
			bool condition = true;
			int i = 0;
			if (container.WatAmount() < MUST_A) Assert::IsTrue(false);
			vector<Type> type;
			for (; i < MUST_A; i++)
			{
				type.push_back(it->data.KEY);
				it = it->next;
			}
			i = 0;
			condition = condition && (type[i++] == Type::tree);
			condition = condition && (type[i++] == Type::bush);
			condition = condition && (type[i++] == Type::flower);
			Assert::IsTrue(condition);
		}

	private:
		const int MUST_A = 3;
		ifstream infile;
		RingList<Plant> container;


	};
	
	TEST_CLASS(TestGetPlant)
	{
	public:
		TEST_METHOD(CrushTest)
		{
			Plant object;
			Assert::IsFalse(GetPlant("800 100 НеСуществуетКласс 10", object));
		}

		TEST_METHOD(CrushTest2)
		{
			Plant object;
			Assert::IsFalse(GetPlant("-800 100 НеСуществуетКласс 10", object));
		}

		TEST_METHOD(EmptyTest)
		{
			Plant object;
			Assert::IsFalse(GetPlant("", object));
		}

		TEST_METHOD(EmptyTestTree)
		{
			Plant object;
			GetPlant("1 ", object);
			Assert::AreEqual(0 , int(object.t.year));
		}

		TEST_METHOD(EmptyTestBush)
		{
			Plant object;
			GetPlant("2 ", object);
			Assert::AreEqual(0, object.b.month);
		}

		TEST_METHOD(EmptyTestFlower)
		{
			Plant object;
			GetPlant("3 ", object);
			Assert::AreEqual(0, object.f.type);
		}

		TEST_METHOD(EmptyTest2)
		{
			Plant object;
			GetPlant("2 ", object);
			Assert::AreEqual(string(""), string(object.name));
		}
	};
	
	TEST_CLASS(TestOutAll)
	{
	public:

		TestOutAll()
		{
			outfile.open("output test.txt");
			infile.open("output test.txt");
		}

		TEST_METHOD(EmptyTest)
		{
			RingList<Plant> container;
			OutAll(outfile, container);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string(""),line);
		}

		TEST_METHOD(EmptyTest2)
		{
			RingList<Plant> container;
			OutAll(outfile, container, true);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string(""), line);
		}

		TEST_METHOD(TestWithoutFilter)
		{
			RingList<Plant> container;
			Plant object;
			GetPlant("2 100 НеДревко 5", object);
			container.PushBack(object);
			OutAll(outfile, container);
			outfile.close();
			getline(infile, line);
			string answer;
			answer = "Это кустарник, месяц цветения считался некорректно; ";
			answer += "Местность введенна некорректно Его название = НеДревко ; ";
			answer += "Кол-во согласных в названии = 5";
			Assert::AreEqual(answer, line);
		}

		TEST_METHOD(TestWithInFilter)
		{
			RingList<Plant> container;
			Plant object;
			GetPlant("2 100 НеДревко 5", object);
			container.PushBack(object);
			OutAll(outfile, container, true);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string(""), line);
		}

	private:
		ofstream outfile;
		ifstream infile;
		string line;
	};
	
	TEST_CLASS(TestSort)
	{
	public:

		TestSort()
		{
			infile.open("input test.txt");
			InAll(infile, container);
			Plant object;
			strcpy_s(object.name, GetMaxName().c_str());
			object.WIG = MAX;
			container.PushBack(object);
			strcpy_s(object.name, GetMinName().c_str());
			object.WIG = MIN;
			container.PushBack(object);
		}

		TEST_METHOD(Min)
		{
			Sort(container);
			Assert::AreEqual(MIN, container.begin()->data.WIG);
		}

		TEST_METHOD(Max)
		{
			Sort(container);
			Assert::AreEqual(MAX, container.begin()->prev->data.WIG);
		}

	private:
		const int MAX = 100;
		const int MIN = -100;
		ifstream infile;
		RingList<Plant> container;

	};

	TEST_CLASS(TestQSort)
	{
	public:
		TEST_METHOD(Min)
		{
			Assert::IsTrue(QSort(mass, 0, mass.size() - 1));
		}
	private:
		vector<ElementRL<Plant>*> mass;
	};
	

	TEST_CLASS(TestCmp)
	{
	public:
		TestCmp()
		{
			first = GetMinName();
			last = GetMaxName();
			second = GetMaxName();
			second[0] = ' ';
		}

		TEST_METHOD(Left1)
		{
			Assert::IsFalse(Cmp(first, second));
		}

		TEST_METHOD(Left2)
		{
			Assert::IsFalse(Cmp(second, last));
		}

		TEST_METHOD(Left3)
		{
			Assert::IsFalse(Cmp(first, last));
		}

		TEST_METHOD(Right1)
		{
			Assert::IsTrue(Cmp(second, first));
		}

		TEST_METHOD(Right2)
		{
			Assert::IsTrue(Cmp(last, second));
		}

		TEST_METHOD(Right3)
		{
			Assert::IsTrue(Cmp(last, first));
		}

		TEST_METHOD(Equal_)
		{
			Assert::IsFalse(Cmp(first, first));
		}

	private:
		string first, second, last;

	};
	

	TEST_CLASS(TestOutName)
	{
	public:

		TestOutName()
		{
			outfile.open("output test.txt");
			infile.open("output test.txt");
		}
		TEST_METHOD(EmptyTestTree)
		{
			string line;	
			OutName(outfile, plant);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(answer, line);
		}
		
	private:
		ofstream outfile;
		ifstream infile;
		Plant plant;
		const string answer = "; Местность введенна некорректно Его название =  ; Кол-во согласных в названии = 0";
	};
	
}


namespace TreeTest
{
	TEST_CLASS(TestInTree)
	{
	public:

		TEST_METHOD(EmptyTree)
		{
			stringstream stream;
			stream.str("");
			InTree(stream, tree);
			Assert::AreEqual(0, int(tree.year));
		}

		TEST_METHOD(Test)
		{
			stringstream stream;
			stream.str("100 Привет 4");
			InTree(stream, tree);
		    Assert::AreEqual(100, int(tree.year));
		}

	private:	
		Tree tree;
	};
	

	TEST_CLASS(TestOutTree)
	{
	public:
		TestOutTree()
		{
			outfile.open("output test.txt");
			infile.open("output test.txt");
		}
		TEST_METHOD(EmptyTree)
		{
			OutTree(outfile, tree);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это дерево, ему 0 лет, "),line);
		}

		TEST_METHOD(Test)
		{
			tree.year = 1e18;
			OutTree(outfile, tree);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это дерево, ему 1000000000000000000 лет, "),line);
		}

	private:
		ofstream outfile;
		ifstream infile;
		Tree tree;
		string line;
	};
	
}


namespace BushTest
{
	TEST_CLASS(TestInBush)
	{
	public:

		TEST_METHOD(EmptyBush)
		{
			stringstream stream;
			stream.str("");
			InBush(stream, bush);
			Assert::AreEqual(0 , bush.month);
		}

		TEST_METHOD(Test)
		{
			stringstream stream;
			stream.str("12 Январь -900");
			InBush(stream, bush);
			Assert::AreEqual(12, bush.month);
		}

	private:
		Bush bush;
	};


	TEST_CLASS(TestOutBush)
	{
	public:
		TestOutBush()
		{
			outfile.open("output test.txt");
			infile.open("output test.txt");
		}
		TEST_METHOD(EmptyBush)
		{
			OutBush(outfile, bush);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это кустарник, месяц цветения считался некорректно"), line);
		}

		TEST_METHOD(Test)
		{
			bush.month = 8;
			OutBush(outfile, bush);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это кустарник, месяц цветения - август"),line);
		}

	private:
		ofstream outfile;
		ifstream infile;
		Bush bush;
		string line;
	};
	
}


namespace FlowerTest
{
	TEST_CLASS(TestInFlower)
	{
	public:

		TEST_METHOD(EmptyFlower)
		{
			stringstream stream;
			stream.str("");
			InFlower(stream, flower);
			Assert::AreEqual(0, flower.type);
		}

		TEST_METHOD(Test)
		{
			stringstream stream;
			stream.str("5 горные -100");
			InFlower(stream, flower);
			Assert::AreEqual(5 , flower.type);
		}

	private:		
		Flower flower;
	};
	

	TEST_CLASS(TestOutFlower)
	{
	public:
		TestOutFlower()
		{
			outfile.open("output test.txt");
			infile.open("output test.txt");
		}
		TEST_METHOD(EmptyFlower)
		{
			OutFlower(outfile, flower);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это цветок, тип считался некорректно"),line);
		}

		TEST_METHOD(Test)
		{
			flower.type = 2;
			OutFlower(outfile, flower);
			outfile.close();
			getline(infile, line);
			Assert::AreEqual(string("Это цветок, тип цветка - садовые"),line);
		}

	private:
		ofstream outfile;
		ifstream infile;
		Flower flower;
		string line;
	};

}