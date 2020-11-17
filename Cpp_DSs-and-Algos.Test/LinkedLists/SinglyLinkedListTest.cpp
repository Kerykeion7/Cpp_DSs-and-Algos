#include "pch.h"
#include "CppUnitTest.h"
#include "../../Cpp_DSs-and-Algos.proj/LinkedLists/SinglyLinkedList.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SinglyLinkedListTest
{
	TEST_CLASS(SinglyLinkedListTest)
	{
	public:

		TEST_METHOD(TestLinkedListIsNotNull)
		{
			SinglyLinkedList<string>* lst = new SinglyLinkedList<string>();
			Assert::IsNotNull(lst);
		}
	};
}