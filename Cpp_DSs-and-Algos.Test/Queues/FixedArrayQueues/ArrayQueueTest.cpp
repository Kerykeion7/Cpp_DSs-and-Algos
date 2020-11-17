#include "pch.h"
#include "CppUnitTest.h"
#include "../../../Cpp_DSs-and-Algos.proj/Queues/FixedArrayQueues/ArrayQueue.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayQueueTest
{
	TEST_CLASS(ArrayQueueTest)
	{
	public:

		TEST_METHOD(TestArrayQueueIsNotNull)
		{
			ArrayQueue<int>* q = new ArrayQueue<int>();
			Assert::IsNotNull(q);
		}
	};
}