#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP Lab5.2/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(WholePart1(5, 2), 2);
		}
	};
}
