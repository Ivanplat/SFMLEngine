#include "pch.h"
#include "Class.h"

SClass* SClass::Self_ = nullptr;

SClass::SClass() noexcept
{
	SetClassName();
	Self_ = this;
}

void SClass::SetClassName()
{
	ClassName = typeid(*this).name();
}

SClass* SClass::StaticClass()
{
	return Self_;
}
