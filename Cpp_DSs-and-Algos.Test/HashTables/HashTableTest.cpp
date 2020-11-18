#include "pch.h"
#include "CppUnitTest.h"
#include "../../Cpp_DSs-and-Algos.proj/HashTables/HashTable.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:

		TEST_METHOD(TestHashTableIsNotNull)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			Assert::IsNotNull(table);
		}

		TEST_METHOD(TestHashAlwaysReturnsSameHash)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			int test1 = table->Hash(1);
			Assert::IsTrue(test1 == 1);
			int test2 = table->Hash(2);
			Assert::IsTrue(test2 == 2);
			int test3 = table->Hash(35);
			Assert::IsTrue(test3 == 5);
			int test4 = table->Hash(105);
			Assert::IsTrue(test4 == 5);

			HashTable<string, string>* table2 = new HashTable<string, string>();
			int test5 = table2->Hash("KeyOne");
			Assert::IsTrue(test5 == 7);
			int test6 = table2->Hash("KeyTwo");
			Assert::IsTrue(test6 == 1);
			int test7 = table2->Hash("KeyThree");
			Assert::IsTrue(test7 == 1);
			int test8 = table2->Hash("KeyFour");
			Assert::IsTrue(test8 == 9);
		}

		TEST_METHOD(TestGet_GetsCorrectValue) 
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			SetUpTestHashTable(table);

			string expectedTestOne = "TestOne";
			string actualTestOne = table->GetValue(1);
			string expectedTestTwo = "TestTwo";
			string actualTestTwo = table->GetValue(2);
			string expectedTestThree = "TestThree";
			string actualTestThree = table->GetValue(3);
			string expectedTestFour = "TestFour";
			string actualTestFour = table->GetValue(4);
			string expectedTestFive = "TestFive";
			string actualTestFive = table->GetValue(88);
			string expectedTestSix = "TestSix";
			string actualTestSix = table->GetValue(37);
			string expectedTestSeven = "TestSeven";
			string actualTestSeven = table->GetValue(38);
			string expectedTestEight = "TestEight";
			string actualTestEight = table->GetValue(111);
			string expectedTestNine = "TestNine";
			string actualTestNine = table->GetValue(234);
			string expectedTestTen = "TestTen";
			string actualTestTen = table->GetValue(9);
			string expectedTestEleven = "TestEleven";
			string actualTestEleven = table->GetValue(23);
			string expectedTestTwelve = "TestTwelve";
			string actualTestTwelve = table->GetValue(14);

			Assert::AreEqual(expectedTestOne, actualTestOne);
			Assert::AreEqual(expectedTestTwo, actualTestTwo);
			Assert::AreEqual(expectedTestThree, actualTestThree);
			Assert::AreEqual(expectedTestFour, actualTestFour);
			Assert::AreEqual(expectedTestFive, actualTestFive);
			Assert::AreEqual(expectedTestSix, actualTestSix);
			Assert::AreEqual(expectedTestSeven, actualTestSeven);
			Assert::AreEqual(expectedTestEight, actualTestEight);
			Assert::AreEqual(expectedTestNine, actualTestNine);
			Assert::AreEqual(expectedTestTen, actualTestTen);
			Assert::AreEqual(expectedTestEleven, actualTestEleven);
			Assert::AreEqual(expectedTestTwelve, actualTestTwelve);
		}

		TEST_METHOD(TestExists)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			SetUpTestHashTable(table);

			Assert::IsTrue(table->Exists(1));
			Assert::IsTrue(table->Exists(2));
			Assert::IsTrue(table->Exists(3));
			Assert::IsTrue(table->Exists(4));
			Assert::IsTrue(table->Exists(88));
			Assert::IsTrue(table->Exists(37));
			Assert::IsTrue(table->Exists(38));
			Assert::IsTrue(table->Exists(111));
			Assert::IsTrue(table->Exists(234));
			Assert::IsTrue(table->Exists(9));
			Assert::IsTrue(table->Exists(23));
			Assert::IsTrue(table->Exists(14));
			Assert::IsFalse(table->Exists(666));
			Assert::IsFalse(table->Exists(0));
			Assert::IsFalse(table->Exists(-5));
		}

		TEST_METHOD(TestRemoveActuallyRemoves)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			SetUpTestHashTable(table);

			table->Remove(1);
			table->Remove(14);
			table->Remove(38);
			table->Remove(234);
			
			Assert::IsFalse(table->Exists(1));
			Assert::IsFalse(table->Exists(14));
			Assert::IsFalse(table->Exists(38));
			Assert::IsFalse(table->Exists(234));
			Assert::IsTrue(table->Exists(2));
		}

		TEST_METHOD(TestSizeAndCapacityIsCorrect)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			SetUpTestHashTable(table);
			Assert::AreEqual(12, table->GetSize());
			Assert::AreEqual(20, table->GetCapacity());
			table->Remove(1654);
			Assert::AreEqual(12, table->GetSize());
			table->Remove(1);
			table->Remove(88);
			Assert::AreEqual(10, table->GetSize());
			table->Add(1, "NewTestOne");
			table->Add(2, "OverrideTestTwo");
			table->Add(10, "TestTen");
			Assert::AreEqual(12, table->GetSize());
			Assert::AreEqual(20, table->GetCapacity());
			table->Add(5678, "FinalTest");
			Assert::AreEqual(13, table->GetSize());
			Assert::AreEqual(40, table->GetCapacity());
			table->Remove(2);

			int counter = 0;
			for (size_t i = 0; i < table->GetCapacity(); i++)
			{
				if (table->GetAt(i).isAssigned) counter++;
			}

			Assert::AreEqual(counter, table->GetSize());
		}

	private:
		void SetUpTestHashTable(HashTable<int, string>* table)
		{
			table->Add(1, "TestOne");
			table->Add(2, "TestTwo");
			table->Add(3, "TestThree");
			table->Add(4, "TestFour");
			table->Add(88, "TestFive");
			table->Add(37, "TestSix");
			table->Add(38, "TestSeven");
			table->Add(111, "TestEight");
			table->Add(234, "TestNine");
			table->Add(9, "TestTen");
			table->Add(23, "TestEleven");
			table->Add(14, "TestTwelve");
		}
	};
}