#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4.rec/Lb_6.4.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
	TEST_CLASS(UnitTest64rec)
	{
    public:

       
        TEST_METHOD(TestProductNegatives)
        {
            const int SIZE = 5;
            double arr[SIZE] = { -2.0, 3.5, -4.0, 5.0, 6.0 };

           
            double expectedProduct = 8.0;

           
            double result = productNegatives(arr, SIZE, 0, 1.0);
            Assert::AreEqual(expectedProduct, result);
        }

     
        
        
    };
}