#include "pch.h"
#include "CppUnitTest.h"
#include "../../Cpp_DSs-and-Algos.proj/BinarySearches/BinarySearch.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTest
{
	TEST_CLASS(BinarySearchTest)
	{
	public:

		TEST_METHOD(TestA)
		{
			int* arr = (int*)malloc(10 * sizeof(int));
			if (!arr) exit(EXIT_FAILURE);
			for (int i = 0; i < 10; i++)
			{
				arr[i] = i * 2 + 1;
			}
			Assert::AreEqual(0, IndexOf(arr, 0, 10, 1));
			Assert::AreEqual(1, IndexOf(arr, 0, 10, 3));
			Assert::AreEqual(2, IndexOf(arr, 0, 10, 5));
			Assert::AreEqual(3, IndexOf(arr, 0, 10, 7));
			Assert::AreEqual(4, IndexOf(arr, 0, 10, 9));
			Assert::AreEqual(5, IndexOf(arr, 0, 10, 11));
			Assert::AreEqual(6, IndexOf(arr, 0, 10, 13));
			Assert::AreEqual(7, IndexOf(arr, 0, 10, 15));
			Assert::AreEqual(8, IndexOf(arr, 0, 10, 17));
			Assert::AreEqual(9, IndexOf(arr, 0, 10, 19));
		}

		TEST_METHOD(TestB)
		{
			int arr[20] = { 5, 10, 13, 21, 25, 35, 42, 68, 69, 72, 73, 76, 85, 99, 101, 102, 111, 209, 235, 333 };
			Assert::AreEqual(0, IndexOf(arr, 0, 20, 5));
			Assert::AreEqual(1, IndexOf(arr, 0, 20, 10));
			Assert::AreEqual(2, IndexOf(arr, 0, 20, 13));
			Assert::AreEqual(3, IndexOf(arr, 0, 20, 21));
			Assert::AreEqual(4, IndexOf(arr, 0, 20, 25));
			Assert::AreEqual(5, IndexOf(arr, 0, 20, 35));
			Assert::AreEqual(6, IndexOf(arr, 0, 20, 42));
			Assert::AreEqual(7, IndexOf(arr, 0, 20, 68));
			Assert::AreEqual(8, IndexOf(arr, 0, 20, 69));
			Assert::AreEqual(9, IndexOf(arr, 0, 20, 72));
			Assert::AreEqual(10, IndexOf(arr, 0, 20, 73));
			Assert::AreEqual(11, IndexOf(arr, 0, 20, 76));
			Assert::AreEqual(12, IndexOf(arr, 0, 20, 85));
			Assert::AreEqual(13, IndexOf(arr, 0, 20, 99));
			Assert::AreEqual(14, IndexOf(arr, 0, 20, 101));
			Assert::AreEqual(15, IndexOf(arr, 0, 20, 102));
			Assert::AreEqual(16, IndexOf(arr, 0, 20, 111));
			Assert::AreEqual(17, IndexOf(arr, 0, 20, 209));
			Assert::AreEqual(18, IndexOf(arr, 0, 20, 235));
			Assert::AreEqual(19, IndexOf(arr, 0, 20, 333));
		}

		TEST_METHOD(TestC)
		{
			int arr[2] = { 5, 10 };
			Assert::AreEqual(0, IndexOf(arr, 0, 2, 5));
			Assert::AreEqual(1, IndexOf(arr, 0, 2, 10));
		}
	};
}