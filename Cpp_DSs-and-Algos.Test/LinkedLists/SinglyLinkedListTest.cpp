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

		TEST_METHOD(Test_GetSize_And_IsEmpty)
		{
			SinglyLinkedList<string>* lst = new SinglyLinkedList<string>();
			Assert::IsTrue(lst->Length() == 0 && lst->IsEmpty());
			SetupTestLstofStrings(lst);
			Assert::IsTrue(lst->Length() == 6 && !lst->IsEmpty());
		}

		TEST_METHOD(Test_Get_Funx) {
			SinglyLinkedList<string>* lst = new SinglyLinkedList<string>();
			SetupTestLstofStrings(lst);
			Assert::IsTrue(lst->GetFront() == "one" && lst->GetBack() == "ten");
			lst->PushFront("zero");
			lst->PushBack("eleven");
			Assert::IsTrue(lst->GetFront() == "zero" && lst->GetBack() == "eleven");
			Assert::IsTrue(lst->GetValueAt(2) == "four");
			Assert::IsTrue(lst->GetValueAtFromEnd(2) == "seven");
		}

		TEST_METHOD(Test_Pop_ReturnsCorrectValue)
		{
			SinglyLinkedList<string>* lst = new SinglyLinkedList<string>();
			SetupTestLstofStrings(lst);
			Assert::IsTrue(lst->Length() == 6);
			Assert::IsTrue(lst->PopFront() == "one" && lst->PopBack() == "ten");
			Assert::IsTrue(lst->Length() == 4);
		}

		TEST_METHOD(Test_LinkedListNodes_AreCorrect)
		{
			SinglyLinkedList<int>* lst = new SinglyLinkedList<int>();
			SetupTestLstOfInts(lst);
			lst->InsertAt(2, 1);
			lst->PushFront(0);
			lst->InsertAt(3, 3);
			lst->InsertAt(8, 8);
			lst->InsertAt(9, 9);
			Assert::AreEqual(11, lst->Length());
			for (int i = 0; i < lst->Length(); i++)
			{
				Assert::AreEqual(i, lst->GetValueAt(i));
			}

			lst->Reverse();
			for (int i = 0; i < lst->Length(); i++)
			{
				Assert::AreEqual(i, lst->GetValueAtFromEnd(i));
			}
		}

		TEST_METHOD(Test_Remove_Funx)
		{
			SinglyLinkedList<int>* lst = new SinglyLinkedList<int>();
			SetupTestLstOfInts(lst);

			Assert::AreEqual(6, lst->Length());
			Assert::AreEqual(4, lst->GetValueAt(1));
			lst->Remove(4);
			Assert::AreEqual(5, lst->Length());
			Assert::AreNotEqual(4, lst->GetValueAt(1));
			Assert::AreEqual(5, lst->GetValueAt(1));
			lst->RemoveAt(1);
			Assert::AreNotEqual(5, lst->GetValueAt(1));
			Assert::AreEqual(6, lst->GetValueAt(1));
		}

	private:
		void SetupTestLstofStrings(SinglyLinkedList<string>* lst) {
			lst->PushFront("five");
			lst->PushFront("four");
			lst->PushBack("six");
			lst->PushBack("seven");
			lst->PushBack("ten");
			lst->PushFront("one");
		}

		void SetupTestLstOfInts(SinglyLinkedList<int>* lst) {
			lst->PushFront(5);
			lst->PushFront(4);
			lst->PushBack(6);
			lst->PushBack(7);
			lst->PushBack(10);
			lst->PushFront(1);
		}
	};
}