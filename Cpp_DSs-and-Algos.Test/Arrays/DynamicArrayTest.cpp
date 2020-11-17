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
	};
}