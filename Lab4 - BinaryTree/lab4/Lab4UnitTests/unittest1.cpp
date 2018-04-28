#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab4/Tree.cpp"
#include <ostream>
#include <string>
#include <iostream>
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD_INITIALIZE(methodName) {
		}
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			Assert::IsTrue(true);
		}
		TEST_METHOD(NodeTestConstructor) {
			Node<int>* node = new Node<int>(nullptr, nullptr, 0);
			Assert::AreEqual(0, node->getValue());
		}
		TEST_METHOD(TreeTestConstructor) {
			Tree<int>* tree = new Tree<int>();
			tree->insertItem(5);
			Assert::AreEqual(5,tree->recFindHome(5)->getValue());
		}
		TEST_METHOD(TreeTestValues) {
			Tree<int>* tree = new Tree<int>();
			tree->insertItem(5);
			tree->insertItem(3);
			Assert::AreEqual(3, tree->recFindHome(3)->getValue());
		}
		TEST_METHOD(TreeAlotValues) {
			Tree<int>* tree = new Tree<int>();
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(6);
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(6);
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(6);
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(6);
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(6);
			tree->insertItem(5);
			tree->insertItem(3);
			tree->insertItem(7);
			Assert::AreEqual(7, tree->recFindHome(7)->getValue());
		}
		TEST_METHOD(TestRightValue) {
			Tree<int>* tree = new Tree<int>();
			tree->insertItem(5);
			tree->insertItem(6);
			Assert::AreEqual(6, tree->recFindHome(5)->getRight()->getValue());
		}
		TEST_METHOD(TestRightThenLeftValue) {
			Tree<int>* tree = new Tree<int>();
			tree->insertItem(5);
			tree->insertItem(7);
			tree->insertItem(6);
			Assert::AreEqual(6, tree->recFindHome(6)->getValue());
		}

	};
}