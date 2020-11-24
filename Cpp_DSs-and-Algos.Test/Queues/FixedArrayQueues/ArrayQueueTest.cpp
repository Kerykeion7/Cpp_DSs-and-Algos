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

		TEST_METHOD(Test_IsEmpty)
		{
			ArrayQueue<int>* q = new ArrayQueue<int>();
			Assert::IsTrue(q->Length() == 0 && q->IsEmpty());
			q->Enqueue(1);
			q->Enqueue(2);
			Assert::IsFalse(q->Length() == 0 && q->IsEmpty());
			Assert::IsTrue(q->Length() == 2 && !q->IsEmpty());
		}

		TEST_METHOD(Test_IsFull)
		{
			ArrayQueue<int>* q = SetupTestArrayQ();
			Assert::IsFalse(q->IsFull());
			q->Enqueue(5);
			q->Enqueue(6);
			Assert::IsTrue(q->IsFull());
		}

		TEST_METHOD(Test_Dequeuing_and_Enqueuing)
		{
			ArrayQueue<int>* q = SetupTestArrayQ();
			Assert::IsFalse(q->IsEmpty());
			q->Enqueue(5);
			q->Enqueue(6);
			Assert::IsTrue(q->Length() == 6);
			Assert::AreEqual(1, q->Dequeue());
			Assert::IsTrue(q->Length() == 5);
			Assert::AreEqual(2, q->Dequeue());
			Assert::AreEqual(3, q->Dequeue());
			Assert::IsTrue(q->Length() == 3);
			Assert::AreEqual(4, q->Dequeue());
			Assert::AreEqual(5, q->Dequeue());
			Assert::AreEqual(6, q->Dequeue());
			Assert::IsTrue(q->IsEmpty() && q->Length() == 0);
		}

	private:

		ArrayQueue<int>* SetupTestArrayQ()
		{
			ArrayQueue<int>* q = new ArrayQueue<int>();
			q->Enqueue(1);
			q->Enqueue(2);
			q->Enqueue(3);
			q->Enqueue(4);
			return q;
		}
	};
}