#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB6_3rec/LAB6_3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        static void printArray(int* arr, int size) {
            for (int i = 0; i < size; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        TEST_METHOD(ArrayFunctionsTest_FindMax_Int) {
            int size = 10;
            int* arr = new int[size];

            fillArray(arr, size);

            printArray(arr, size);

            int maxElement = findMaxRecursive(arr, 0, size - 1);

            bool isCorrect = true;
            for (int i = 0; i < size; i++) {
                if (arr[i] > maxElement) {
                    isCorrect = false;
                    break;
                }
            }

            Assert::IsTrue(isCorrect);

            delete[] arr;
        }

        TEST_METHOD(ArrayFunctionsTest_FindMax_Double) {
            int size = 10;
            double* arr = new double[size];

            fillArray(arr, size);

           
            printArray(reinterpret_cast<int*>(arr), size);

            double maxElement = findMaxRecursive(arr, 0, size - 1);

            bool isCorrect = true;
            for (int i = 0; i < size; i++) {
                if (arr[i] > maxElement) {
                    isCorrect = false;
                    break;
                }
            }

            Assert::IsTrue(isCorrect);

            delete[] arr;
        }
    };
}
