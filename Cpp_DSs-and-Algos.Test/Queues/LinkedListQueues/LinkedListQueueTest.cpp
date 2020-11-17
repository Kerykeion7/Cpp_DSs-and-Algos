#include "pch.h"
#include "CppUnitTest.h"
#include "../../../Cpp_DSs-and-Algos.proj/Queues/LinkedListQueues/LinkedListQueue.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListQueueTest
{
	TEST_CLASS(LinkedListQueueTest)
	{
	public:

		TEST_METHOD(TestLinkedListIsNotNull)
		{
			LinkedListQueue<string>* q = new LinkedListQueue<string>();
			Assert::IsNotNull(q);
		}
	};
}