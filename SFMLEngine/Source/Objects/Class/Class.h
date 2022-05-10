#pragma once
#include <string>

class SClass
{
public:
	explicit SClass() noexcept;
	virtual ~SClass() noexcept = default;
	void SetClassName();
public:
	std::string ClassName;
};


template<class T>
T* Cast(SClass* Class)
{
	if (auto* t = dynamic_cast<T*>(Class))
	{
		return t;
	}
	return nullptr;
}