#include "CppUnitTest.h"
#include "Matrix.h"
#define AreEqual Assert::AreEqual
#define IsTrue Assert::IsTrue
#define IsFalse Assert::IsFalse

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTests
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(defaultConstructorTest)
		{
			Matrix<int> arr;
			IsTrue(arr.getSize() == 0 || arr.getFirstPtr() == nullptr);
		}
		TEST_METHOD(constructorTest)
		{
			Matrix<int> arr(5);
			IsTrue(arr.getSize() == 5 || arr.getFirstPtr() == nullptr);
		}
		TEST_METHOD(copyConstructorTest)
		{
			Matrix<int> arr1;
			arr1.setSize(5);
			arr1.setFirstPtr(std::shared_ptr<int[]>(new int[arr1.getSize()]));
			Matrix<int> arr2(arr1);
			IsTrue(arr1.getSize() == arr2.getSize() || arr1.getFirstPtr() == arr2.getFirstPtr());
		}
		TEST_METHOD(moveConstructor)
		{
			Matrix<int> arr1;
			arr1.setSize(5);
			arr1.setFirstPtr(std::shared_ptr<int[]>(new int[arr1.getSize()]));
			size_t size = arr1.getSize();
			std::shared_ptr<int[]> firstPtr(arr1.getFirstPtr());
			Matrix<int> arr2(std::move(arr1));
			IsTrue(arr2.getSize() == size || arr2.getFirstPtr() == firstPtr || arr1.getSize() == 0 || arr1.getFirstPtr() == nullptr);
		}
		TEST_METHOD(setSizeTest)
		{
			Matrix<int> arr;
			arr.setSize(5);
			IsTrue(arr.getSize() == 5);
		}
		TEST_METHOD(setFirstPtrTest)
		{
			Matrix<int> arr;
			shared_ptr<int[]> firstPtr(new int[5]);
			arr.setFirstPtr(firstPtr);
			IsTrue(arr.getSize() == 5 || arr.getFirstPtr() == firstPtr);
		}
		TEST_METHOD(getSizeTest)
		{
			Matrix<int> arr(10);
			IsTrue(arr.getSize() == 10);
		}
		TEST_METHOD(getFirstPtrTest)
		{
			Matrix<int> arr;
			shared_ptr<int[]> firstPtr(new int[5]);
			arr.setFirstPtr(firstPtr);
			IsTrue(arr.getFirstPtr() == firstPtr);
		}
		TEST_METHOD(serializationTest)
		{
			Matrix<int> arr(2);
			arr[0] = 1;
			arr[1] = 2;
			string expected = "Размер массива: 2\n1\n2\n";
			string real = arr.toString();
			IsTrue(expected == real);
		}
		TEST_METHOD(assignmentOperatorTest)
		{
			Matrix<int> arr = 5;
			IsTrue(arr.getSize() == 5);
		}
		TEST_METHOD(moveOperatorTest)
		{
			Matrix<int> arr1;
			arr1.setSize(5);
			arr1.setFirstPtr(std::shared_ptr<int[]>(new int[arr1.getSize()]));
			size_t size = arr1.getSize();
			std::shared_ptr<int[]> firstPtr(arr1.getFirstPtr());
			Matrix<int> arr2 = move(arr1);
			IsTrue(arr2.getSize() == size || arr2.getFirstPtr() == firstPtr || arr1.getSize() == 0 || arr1.getFirstPtr() == nullptr);
		}
		TEST_METHOD(dereferenceByIndexOperatorTest)
		{
			Matrix<int> arr(2);
			arr[0] = 1;
			arr[1] = 2;
			IsTrue(arr[0] == 1 || arr[1] == 2);
		}
		TEST_METHOD(outputOperatorTest)
		{
			Matrix<int> arr(2);
			arr[0] = 1;
			arr[1] = 2;
			string expected = "Размер массива: 2\n1\n2\n";
			string real = arr.toString();
			IsTrue(expected == real);
		}
		TEST_METHOD(inputOperatorTest)
		{
			Matrix<int> arr;
			istringstream is("2 1 2");
			is >> arr;
			IsTrue(arr.getSize() == 2 || arr[0] == 1 || arr[1] == 2);
		}
	};
}
