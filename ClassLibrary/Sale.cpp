#include "Sale.h"

Sale::Sale(Medicine item) : medicine{item}, timeOfSale{time(nullptr)}
{
}

std::string Sale::getName()
{
	return name;
}

Medicine Sale::getMedicine()
{
	return medicine;
}

bool Sale::isWithinLastWeek()
{
	time_t now = time(nullptr);
	if (difftime(now, timeOfSale) <= 7.0 * 24.0 * 60.0 * 60.0)
	{
		return true;
	}
	else return false;
}

bool Sale::isWithinLastMounth()
{
	time_t now = time(nullptr);
	if (difftime(now, timeOfSale) <= 4.0 * 7.0 * 24.0 * 60.0 * 60.0)
	{
		return true;
	}
	else return false;
}

bool Sale::isWithinLastYear()
{
	time_t now = time(nullptr);
	if (difftime(now, timeOfSale) <= 12.0 * 4.0 * 7.0 * 24.0 * 60.0 * 60.0)
	{
		return true;
	}
	else return false;
}