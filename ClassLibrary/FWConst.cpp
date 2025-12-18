#include "FWConst.h"

FWConst::FWConst(const int value) : value{value}
{
}

int FWConst::generate()
{
	return value;
}