#pragma once

class SClass
{
public:
	explicit SClass() noexcept = default;
	virtual ~SClass() noexcept = default;
public:
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