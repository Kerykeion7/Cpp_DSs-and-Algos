#include "pch.h"
#include "CppUnitTest.h"
#include "../../Cpp_DSs-and-Algos.proj/HashTables/HashTable.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppDSsandAlgosTest
{
	TEST_CLASS(CppDSsandAlgosTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			HashTable<int, string>* table = new HashTable<int, string>();
			Assert::IsNotNull(table);
		}
	};
}