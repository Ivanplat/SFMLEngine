#pragma once

#include "Class.h"

template<class T>
class TSubclassOf
{
public:
	explicit TSubclassOf();
	virtual ~TSubclassOf();
public:
	T* GetClass();
	void Destruct();
private:
	T* Class;
};

template<class T>
TSubclassOf<T>::TSubclassOf()
{
	auto t = new T();
	if (auto c = Cast<SClass>(t))
	{
		Class = dynamic_cast<T*>(c);
		return;
	}
	delete t;
}

template<class T>
TSubclassOf<T>::~TSubclassOf()
{

}

template<class T>
inline T* TSubclassOf<T>::GetClass()
{
	return Class;
}

template<class T>
void TSubclassOf<T>::Destruct()
{
	if (Class)
	{
		delete Class;
	}
}