#include "pch.h"
#include "CppUnitTest.h"
#include "../../Cpp_DSs-and-Algos.proj/Arrays/DynamicArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTest
{
	TEST_CLASS(DynamicArrayTest)
	{
	public:

		TEST_METHOD(TestDynamicArrayIsNotNull)
		{
			DynamicArray<int> *array = new DynamicArray<int>();
			Assert::IsNotNull(array);
		}

		TEST_METHOD(TestDynamicArrayCountEquals8)
		{
			DynamicArray<int>* array = new DynamicArray<int>();
			SetUpMainTestArray(array);
			Assert::AreEqual(array->Count, 8);
		}

		TEST_METHOD(TestDynamicArraysEqualMinCapacity)
		{
			DynamicArray<int>* array1 = new DynamicArray<int>();
			DynamicArray<int>* array2 = new DynamicArray<int>(2);

			Assert::AreEqual(array1->Capacity(), 4);
			Assert::AreEqual(array2->Capacity(), 4);
		}

		TEST_METHOD(TestArrayCapacityEqualsGivenCapacity_AndArrayIsEmpty)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			Assert::AreEqual(array->Capacity(), 10);
			Assert::IsTrue(array->IsEmpty());
		}

		TEST_METHOD(TestArrayIsNotEmptyAndCountEqualsLength)
		{
			DynamicArray<int>* array = new DynamicArray<int>();
			SetUpMainTestArray(array);
			Assert::IsFalse(array->IsEmpty());
			Assert::AreEqual(array->Count, array->Length());
		}

		TEST_METHOD(TestPoppedEqualsTen)
		{
			DynamicArray<int>* array = new DynamicArray<int>();
			SetUpMainTestArray(array);
			Assert::AreEqual(array->Pop(), 10);
		}

		TEST_METHOD(TestArrayDoublesSizeOnCapacityReached)
		{
			DynamicArray<int>* array = new DynamicArray<int>();
			SetUpMainTestArray(array);
			Assert::AreEqual(array->Capacity(), 8);
			array->Push(11);
			Assert::IsTrue(array->Capacity() == 16);
		}

		TEST_METHOD(TestArrayHalvesOnCountIsQuarterOfCapacity)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			SetUpMainTestArray(array);
			array->Pop();
			array->Pop();
			array->Pop();
			array->Pop();
			array->Pop();
			array->Pop();
			Assert::IsTrue(array->Capacity() == 5);
		}

		TEST_METHOD(TestInsertAt2EqualsGivenValue)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			SetUpMainTestArray(array);

			array->InsertAt(3, 2);
			Assert::AreEqual(array->GetAt(2), 3);
		}

		TEST_METHOD(TestPrependInsertsAtIndex0)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			SetUpMainTestArray(array);

			array->Prepend(888);
			Assert::AreEqual(array->GetAt(0), 888);
		}

		TEST_METHOD(TestRemoveAt5RemovesValue8)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			SetUpMainTestArray(array);

			Assert::AreEqual(array->GetAt(5), 8);
			array->RemoveAt(5);
			Assert::AreNotEqual(array->GetAt(5), 8);
		}

		TEST_METHOD(TestRemoveTenReallyRemovesAllTens)
		{
			DynamicArray<int>* array = new DynamicArray<int>(10);
			SetUpMainTestArray(array);
			array->Prepend(10);
			array->InsertAt(10, 5);
			array->Remove(10);
			array->Push(12345);

			Assert::IsFalse(array->Contains(10));
			Assert::IsTrue(array->Contains(12345));
			Assert::IsTrue(array->Contains(5));
		}

		TEST_METHOD(TestCustomArrayEqualsBuiltInArray) 
		{
			DynamicArray<int>* array = new DynamicArray<int>();
			SetUpMainTestArray(array);
			int expected[8] = { 1,2,4,5,6,8,9,10 };
			int fakeExpected[8] = { 5, 6, 8, 8, 4 ,8 ,5, 8};
			int actual[8] = {};

			array->CopyTo(actual);

			for (int i = 0; i < 8; i++)
			{
				if (fakeExpected[i] != actual[i]) Assert::IsFalse(false);
			};

			for (int i = 0; i < 8; i++)
			{
				if (expected[i] != actual[i]) Assert::IsTrue(false);
			};
			Assert::IsTrue(true);
		}

	private:
		void SetUpMainTestArray(DynamicArray<int>* array) 
		{
			array->Push(1);
			array->Push(2);
			array->Push(4);
			array->Push(5);
			array->Push(6);
			array->Push(8);
			array->Push(9);
			array->Push(10);
		}
	};
}