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
		TEST_METHOD(isWithInTheLastWeekTest)
		{
			time_t now = time(nullptr);
			time_t time1 = now - 6 * 24 * 60 * 60;
			time_t time2 = now - 8 * 24 * 60 * 60;
			Medicine medicine("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
			Sale sale1(medicine);
			sale1.setTimeOfSale(time1);
			Sale sale2(medicine);
			sale2.setTimeOfSale(time2);
			IsTrue(sale1.isWithinLastWeek() == true && sale2.isWithinLastWeek() == false);
		}
		TEST_METHOD(isWithInTheLastMounthTest)
		{
			time_t now = time(nullptr);
			time_t time1 = now - 4 * 6 * 24 * 60 * 60;
			time_t time2 = now - 4 * 8 * 24 * 60 * 60;
			Medicine medicine("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
			Sale sale1(medicine);
			sale1.setTimeOfSale(time1);
			Sale sale2(medicine);
			sale2.setTimeOfSale(time2);
			IsTrue(sale1.isWithinLastMounth() == true && sale2.isWithinLastMounth() == false);
		}
		TEST_METHOD(isWithInTheLastYearTest)
		{
			time_t now = time(nullptr);
			time_t time1 = now - 12 * 4 * 6 * 24 * 60 * 60;
			time_t time2 = now - 12 * 4 * 8 * 24 * 60 * 60;
			Medicine medicine("Зиртек", "Таблеточная", "28.02.2029", "Использовать по назначению", 500.0, "Компания1", "аллергия");
			Sale sale1(medicine);
			sale1.setTimeOfSale(time1);
			Sale sale2(medicine);
			sale2.setTimeOfSale(time2);
			IsTrue(sale1.isWithinLastYear() == true && sale2.isWithinLastYear() == false);
		}
	};
}
