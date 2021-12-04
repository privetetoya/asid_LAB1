#include "pch.h"
#include "CppUnitTest.h"
#include "..\АиСД. Лабораторная работа 1\Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab
{
	TEST_CLASS(UnitTestLab)
	{
	public:
		
		TEST_METHOD(Constructor_List)
		{
			List TestList;
			Assert::IsTrue(TestList.get_size() == 0);
		}
		TEST_METHOD(ConstructorwithvalueList)
		{
			List TestList(1);
			Assert::IsTrue(TestList.get_size() == 1);
		}
		TEST_METHOD(DestructorList)
		{
			List TestList;
			TestList.push_back(1);
			TestList.~List();
			Assert::IsTrue(TestList.get_size() == 0);
		}
		TEST_METHOD(PushBack)
		{
			List TestList;
			TestList.push_back(1);
			TestList.push_back(2);
			Assert::IsTrue(TestList.get_size() == 2);
			TestList.pop_front();
			Assert::IsTrue(TestList.get_size() == 1);
			int element = TestList.at(0);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(PushFront)
		{
			List TestList;
			TestList.push_front(1);
			TestList.push_front(2);
			Assert::IsTrue(TestList.get_size() == 2);
			TestList.pop_front();
			int element = TestList.at(0);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(PopBack)
		{
			List TestList;
			Assert::IsTrue(TestList.get_size() == 0);
			try {
				TestList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			TestList.push_back(1);
			TestList.push_back(2);
			Assert::IsTrue(TestList.get_size() == 2);
			try {
				TestList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			Assert::IsTrue(TestList.get_size() == 1);
			int element = TestList.at(0);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(PopFront)
		{
			List TestList;
			try {
				TestList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			TestList.push_back(1);
			TestList.push_back(2);
			TestList.push_back(3);
			Assert::IsTrue(TestList.get_size() == 3);
			try {
				TestList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty", error.what());
			}
			Assert::IsTrue(TestList.get_size() == 2);
			int element = TestList.at(0);
			Assert::IsTrue(element == 2);
		}
		TEST_METHOD(Insert)
		{
			List TestList;

			try {
				TestList.insert(1, 2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.push_back(1);
			TestList.push_back(2);
			Assert::IsTrue(TestList.get_size() == 2);
			try {
				TestList.insert(4, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.insert(3, 1);
			Assert::IsTrue(TestList.get_size() == 3);
			int element = TestList.at(1);
			Assert::IsTrue(element == 3);
		}
		TEST_METHOD(At)
		{
			List TestList;
			try {
				TestList.at(2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.push_back(1);
			try {
				TestList.at(6);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			int element = TestList.at(0);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(Remove)
		{
			List TestList;
			TestList.push_back(1);
			TestList.push_back(2);
			TestList.insert(3, 3);
			Assert::IsTrue(TestList.get_size() == 3);
			try {
				TestList.remove(-100);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			try {
				TestList.remove(100);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.remove(3);
			Assert::IsTrue(TestList.get_size() == 2);
			int element1 = TestList.at(0);
			int element2 = TestList.at(1);
			Assert::IsTrue(element1 == 1);
			Assert::IsTrue(element2 == 2);
		}
		TEST_METHOD(Clear)
		{
			List TestList;
			TestList.push_back(1);
			TestList.clear();
			Assert::IsTrue(TestList.get_size() == 0);
		}
		TEST_METHOD(Set)
		{
			List TestList;
			TestList.push_back(10);
			TestList.push_back(11);
			Assert::IsTrue(TestList.get_size() == 2);
			try {
				TestList.set(100, 6);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			try {
				TestList.set(-100, 4);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.set(1, 1);
			int element = TestList.at(1);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(Empty)
		{
			List TestList;
			TestList.push_back(2);
			Assert::IsTrue(TestList.isEmpty() == false);
			TestList.clear();
			Assert::IsTrue(TestList.isEmpty() == true);
		}
		TEST_METHOD(FindLast)
		{
			List TestList;
			TestList.push_back(3);
			TestList.push_front(1);
			List NewTestList;
			NewTestList.push_back(3);
			NewTestList.push_front(9);
			stringstream output;
			try {
				TestList.find_last(NewTestList);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Not included", error.what());
			}

			TestList.insert(2, 2);
			TestList.push_back(4);
			output << TestList.find_last(NewTestList);
			int element = TestList.at(3);
			Assert::IsTrue(element == 4);
			TestList.pop_back();
			output << TestList.find_last(NewTestList);
			int element1 = TestList.at(2);
			Assert::IsTrue(element1 == 2);
		}
	};
}
