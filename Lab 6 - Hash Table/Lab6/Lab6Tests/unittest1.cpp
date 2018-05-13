#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab6/chainHash.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab6Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::IsTrue(true);
		}
		// Test Link
		TEST_METHOD(LinkTestConstructor)
		{
			Link<int>* temp = new Link<int>;
			Assert::IsTrue(temp->getNext() == nullptr);
		}
		TEST_METHOD(LinkTestOverLoadedConstructor)
		{
			Link<int>* temp = new Link<int>(nullptr,5);
			Assert::IsTrue(temp->get() == 5);
		}
		// Test List
		TEST_METHOD(ListTestAddFind)
		{
			List<int>* temp = new List<int>;
			temp->add(5);
			Assert::IsTrue(temp->find(5));
		}
		// Test Chain HAsh
		TEST_METHOD(TestChainHash) {
			ChainHashTable<int>* temp= new ChainHashTable<int>;
			temp->addValue(5);
			Assert::IsTrue(temp->findValue(5));
		}
	};
}