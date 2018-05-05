#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab5/ParseTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::IsFalse(false);
		}
		
		TEST_METHOD(LOADPARSETREE) {
			ParseTree* tree = new ParseTree;
			Assert::IsTrue(tree->stackEmpty());
		}

		TEST_METHOD(StackAddAndPeak) {
			ParseTree* tree = new ParseTree;
			tree->stackAdd('t');
			Assert::AreEqual(tree->stackPeek(), 't');
		}

		TEST_METHOD(StackAddAndRemove) {
			ParseTree* tree = new ParseTree;
			tree->stackAdd('t');
			Assert::AreEqual(tree->stackPop(), 't');
			Assert::IsTrue(tree->stackEmpty());
		}
		TEST_METHOD(StackAddAndRemoveDeeper) {
			ParseTree* tree = new ParseTree;
			tree->stackAdd('t');
			tree->stackAdd('e');
			tree->stackAdd('s');
			tree->stackAdd('t');
			Assert::AreEqual(tree->stackPop(), 't');
			Assert::AreEqual(tree->stackPop(), 's');
			Assert::AreEqual(tree->stackPop(), 'e');
			Assert::AreEqual(tree->stackPop(), 't');
			Assert::IsTrue(tree->stackEmpty());
		}
		TEST_METHOD(OneCharPolish) {
			try {
				ParseTree* tree2 = new ParseTree("A");
				std::string temp= "A";
				Assert::AreEqual(temp, tree2->getPostString());
			}
			catch (...) {
				//Assert::Fail;
			}
		}
		TEST_METHOD(MoreCharPolish) {
			try {
				ParseTree* tree = new ParseTree("01234");
				Assert::AreEqual((std::string) "01234", tree->getPostString());
			}
			catch (...) {
				//Assert::Fail;

			}
		}
		TEST_METHOD(SimplePolish) {
			try {
				ParseTree* tree = new ParseTree("1+2");
				Assert::AreEqual((std::string) "12+", tree->getPostString());
			}
			catch (...) {
				//Assert::Fail;

			}
		}
		TEST_METHOD(SimpleWithPolish) {
			try {
				ParseTree* tree = new ParseTree("1+2");
				Assert::AreEqual((std::string) "12+", tree->getPostString());
			}
			catch (...) {
				//Assert::Fail;

			}
		}
		TEST_METHOD(SimpleWithMorePolish) {
			try {
				ParseTree* tree = new ParseTree("1+2+1+1+1");
				Assert::AreEqual((std::string) "12111++++", tree->getPostString());
			}
			catch (...) {
				//Assert::Fail;

			}
		}
		TEST_METHOD(SimpleWithMoreAddMinusPolish) {
			try {
				ParseTree* tree = new ParseTree("1+2-1");
				Assert::AreEqual((std::string) "12+1-", tree->getPostString());

			}
			catch (...) {
				//Assert::Fail;

			}
		}
		TEST_METHOD(SimpleWithMoreOperatorsPolish) {
			try {
				ParseTree* tree = new ParseTree("1+2*1/1+1");
				Assert::AreEqual((std::string) "121*1/+1+", tree->getPostString());
				
			}
			catch (...) {
				//Assert::Fail;

			}
		}
	
	};
}