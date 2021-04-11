#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Student\ Tkachenko.Marharyta.IK11\Lab4.5\Lab4.5\Pair.cpp"
#include "C:\Student\ Tkachenko.Marharyta.IK11\Lab4.5\Lab4.5\FuzzyNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair* A = new FuzzyNumber(1, 7, 4);
			Pair* B = new FuzzyNumber(3, 9, 6);
			Pair* C = new FuzzyNumber();
			C = *A + B;
			Assert::AreEqual(((FuzzyNumber*)C)->GetX(), 4.0);
		}
	};
}
