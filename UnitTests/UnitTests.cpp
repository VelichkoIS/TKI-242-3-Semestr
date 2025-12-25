#include "CppUnitTest.h"
#include "InquiryOffice.h"
#define AreEqual Assert::AreEqual
#define IsTrue Assert::IsTrue

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(MedicineTest)
	{
	public:
		
		TEST_METHOD(defaultConstructorTest)
		{
			Medicine medicine;
			IsTrue(medicine.getName() == "не указанно" &&
				   medicine.getAnnotation() == "не указанно" &&
				   medicine.getExpirationDate() == "не указанно" &&
				   medicine.getFormOfIssue() == "не указанно" &&
				   medicine.getIllness() == "не указанно" &&
				   medicine.getPrice() == 0 &&
				   medicine.getManufacturer() == "не указанно");
		}
		TEST_METHOD(constructorTest)
		{
			Medicine medicine("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
			IsTrue(medicine.getName() == "Зиртек" &&
				medicine.getAnnotation() == "Использовать по назначению" &&
				medicine.getExpirationDate() == "28.02.2029" &&
				medicine.getFormOfIssue() == "Таблеточная" &&
				medicine.getIllness() == "аллергия" &&
				medicine.getPrice() == 500.0 &&
				medicine.getManufacturer() == "Компания1");
		}
	};
	TEST_CLASS(SaleTest)
	{
	public:
		TEST_METHOD(constructorTest)
		{
			Medicine medicine("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
			Sale sale(medicine);
			IsTrue(sale.getName() == medicine.getName() && sale.getMedicine() == medicine);
		}

	};
}
