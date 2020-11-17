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

		TEST_METHOD(TestAdd)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			
		}
	};
}