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

		TEST_METHOD(Test_IsEmpty)
		{
			LinkedListQueue<string>* q = new LinkedListQueue<string>();
			Assert::IsTrue(q->GetSize() == 0 && q->IsEmpty());
			q->Enqueue("one");
			q->Enqueue("two");
			Assert::IsFalse(q->GetSize() == 0 && q->IsEmpty());
			Assert::IsTrue(q->GetSize() == 2 && !q->IsEmpty());
		}

		TEST_METHOD(Test_Dequeuing_and_Enqueuing)
		{
			LinkedListQueue<string>* q = SetupTestLlstQ();
			Assert::IsFalse(q->IsEmpty());
			q->Enqueue("five");
			q->Enqueue("six");
			Assert::IsTrue(q->GetSize() == 6);
			Assert::IsTrue("one" == q->Dequeue());
			Assert::IsTrue(q->GetSize() == 5);
			Assert::IsTrue("two" == q->Dequeue());
			Assert::IsTrue("three" == q->Dequeue());
			Assert::IsTrue(q->GetSize() == 3);
			Assert::IsTrue("four" == q->Dequeue());
			Assert::IsTrue("five" == q->Dequeue());
			Assert::IsTrue("six" == q->Dequeue());
			Assert::IsTrue(q->IsEmpty() && q->GetSize() == 0);
		}

	private:
		LinkedListQueue<string>* SetupTestLlstQ()
		{
			LinkedListQueue<string>* q = new LinkedListQueue<string>();
			q->Enqueue("one");
			q->Enqueue("two");
			q->Enqueue("three");
			q->Enqueue("four");
			return q;
		}
	};
}