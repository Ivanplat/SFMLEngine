#pragma once
#include "pch.h"
#include "Modules/BaseModule.h"

class GarbageCollector
{
private:
	explicit GarbageCollector() noexcept {}
	virtual ~GarbageCollector() noexcept;
public:
	static GarbageCollector* Instance();
	virtual void Startup();
	virtual void Shutdown();
	template<class T>
	void DestroyModule(T* Module);
	template<class T>
	T* NewModule();
	template<class T>
	T* GetModule();
private:
	std::vector<IBaseModule*> Modules_;
};

template<class T>
T* GarbageCollector::NewModule()
{
	auto mdl = new T();
	if (dynamic_cast<IBaseModule*>(mdl))
	{
		Modules_.push_back(mdl);
		return mdl;
	}
	delete mdl;
	return nullptr;
}

template<class T>
T* GarbageCollector::GetModule()
{
	for (auto i : Modules_)
	{
		if (auto mdl = dynamic_cast<T*>(i))
		{
			return mdl;
		}
	}
	return nullptr;
}

template<class T>
void GarbageCollector::DestroyModule(T* Module)
{
	if (auto mdl = GetModule<T>())
	{
		if (auto mdlc = dynamic_cast<IBaseModule*>(mdl))
		{
			auto it = std::find(Modules_.begin(), Modules_.end(), mdlc);
			if (it != Modules_.end())
			{
				Modules_.erase(it);
			}
		}
		delete mdl;
	}
}