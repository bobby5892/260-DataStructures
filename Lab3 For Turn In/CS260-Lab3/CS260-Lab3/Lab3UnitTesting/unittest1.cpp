#include "stdafx.h"
#include "CppUnitTest.h"
#include "../CS260-Lab3/TextClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
// NOTE FOR VISUAL STUDIO 
// You have to add Existing Item of the Class your testing
namespace Lab3UnitTesting
{		
	TEST_CLASS(Lab3Test)
	{
	public:
		//TEST_METHOD_INITIALIZE(methodName) {

		//}
		TEST_METHOD(DefaultTest)
		{
			// Testing that Testing is Workin
			Logger::WriteMessage("In Default");
			Assert::AreEqual(0, 0);
		}
		TEST_METHOD(isEmpty)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			//processor->isEmpty();

			Logger::WriteMessage("In isEmpty");
			Assert::IsTrue(processor->isEmpty());
			
		}
		// Add a Link to an Empty List
		TEST_METHOD(addToEmptyHead)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addToEmptyHead");
			processor->insertHead('c');

			Assert::AreEqual(processor->getHead()->value,'c');

		}
		TEST_METHOD(addTwoElementsToEmptyHeadNext)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addTwoElementsToEmptyHeadNext");
			//First
			processor->insertHead('c');

			//Second
			processor->insertHead('d');
			Assert::AreEqual(processor->getHead()->next->value, 'c');
		}
		TEST_METHOD(addToEmptyHeadCheckTail)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addToEmptyHead");
			processor->insertHead('c');

			Assert::AreEqual(processor->getTail()->value, 'c');

		}
		TEST_METHOD(addToHeadAndRemove)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addToEmptyHead");
			processor->insertHead('c');

			Assert::AreEqual(processor->deleteHead(), 'c');

		}
		TEST_METHOD(addToTailAndRemove)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addToEmptyHead");
			processor->insertTail('c');

			Assert::AreEqual(processor->deleteTail(), 'c');

		}
		TEST_METHOD(addToHeadAndRemoveTail)
		{
			// Testing that Testing is Workin
			TextClass* processor = new TextClass();
			Logger::WriteMessage("In addToEmptyHead");
			processor->insertHead('c');
			processor->insertHead('d');
			processor->insertHead('e');

			Assert::AreEqual(processor->deleteTail(), 'c');
			Assert::AreEqual(processor->deleteTail(), 'd');
			Assert::AreEqual(processor->deleteTail(), 'e');

		}
		TEST_METHOD(removeHeadExceptionOnEmpty)
		{
			TextClass* processor = new TextClass();
			bool exceptionThrown = false;
			try
				{
				processor->deleteHead();
				}
			catch (...)
			{
				
				exceptionThrown = true;
			}
			
			Logger::WriteMessage("In removeHeadExceptionOnEmpty");
			Assert::IsTrue(exceptionThrown);
		
		}
		TEST_METHOD(removeTailExceptionOnEmpty)
		{
			TextClass* processor = new TextClass();
			bool exceptionThrown = false;
			try
			{
				processor->deleteTail();
			}
			catch (...)
			{

				exceptionThrown = true;
			}

			Logger::WriteMessage("In removeHeadExceptionOnEmpty");
			Assert::IsTrue(exceptionThrown);

		}

		TEST_METHOD(forwardAndBackThruList)
		{
			TextClass* processor = new TextClass();
			// Put things in 
			for (int i = 0; i < 10; i++) {
				processor->insertHead('c');
			}
			// Set this up
			Link *tempTail = processor->getTail();
			Link *tempHead = processor->getHead();
			int tailCount = 0;
			int headCount = 0;
			while (tempTail != nullptr) {
				tailCount++;
				tempTail = tempTail->prev;
			}
			while (tempHead != nullptr) {
				headCount++;
				tempHead = tempHead->next;
			}
			Logger::WriteMessage("In forwardAndBack");

			Assert::AreEqual(tailCount,headCount);

		}

	};
}