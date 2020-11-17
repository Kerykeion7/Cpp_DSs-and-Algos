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
	};
}