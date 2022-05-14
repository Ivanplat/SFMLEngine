#include "pch.h"
#include "Delegate.h"


void CDelegateVoid::Add(IDelegateVoid* Delegate)
{
	if (Delegate)
	{
		DelegatesList_.push_back(Delegate);
	}
}

void CDelegateVoid::Remove(IDelegateVoid* Delegate)
{
	for (auto it = DelegatesList_.begin(); it != DelegatesList_.end(); it++)
	{
		if ((*it)->Compare(Delegate))
		{
			delete (*it);
			DelegatesList_.erase(it);
			break;
		}
	}
	delete Delegate;
}

void CDelegateVoid::RemoveAll()
{
	for (auto it = DelegatesList_.begin(); it != DelegatesList_.end(); it++)
	{
		delete (*it);
	}
	DelegatesList_.clear();
}

void CDelegateVoid::Invoke()
{
	for (auto it = DelegatesList_.begin(); it != DelegatesList_.end(); it++)
	{
		(*it)->Invoke();
	}
}


IDelegateVoid* NewDelegate(void (*Func)(), std::string DelegateName)
{
	return new CStaticDelegateVoid(Func, DelegateName);
}
