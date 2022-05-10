#include "pch.h"
#include "Class.h"

SClass::SClass() noexcept
{
	SetClassName();
}

void SClass::SetClassName()
{
	ClassName = typeid(*this).name();
}
