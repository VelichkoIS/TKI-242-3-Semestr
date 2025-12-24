#include "Medicine.h"

Medicine::Medicine() : name{ "не указанно" },
formOfIssue{ "не указанно" }, expirationDate{ "не указанно" }, annotation{ "не указанно" },
price{ 0 }, manufacturer{ "не указанно" }, illness{"не указанно"}
{}

Medicine::Medicine(const std::string& name, const std::string& formOfIssue, const std::string& expirationDate,
	const std::string& annotation, const double& price, const std::string& manufacturer, const std::string& illness) : name{name}, 
	formOfIssue{formOfIssue}, expirationDate{ expirationDate }, annotation{annotation}, 
	price{price}, manufacturer{manufacturer}, illness{illness}
{

}

std::string Medicine::getName()
{
	return name;
}

std::string Medicine::getFormOfIssue()
{
	return formOfIssue;
}

std::string Medicine::getExpirationDate()
{
	return expirationDate;
}

std::string Medicine::getAnnotation()
{
	return annotation;
}

double Medicine::getPrice()
{
	return price;
}

std::string Medicine::getManufacturer()
{
	return manufacturer;
}

std::string Medicine::getIllness()
{
	return illness;
}