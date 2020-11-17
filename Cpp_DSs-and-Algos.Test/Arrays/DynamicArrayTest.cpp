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