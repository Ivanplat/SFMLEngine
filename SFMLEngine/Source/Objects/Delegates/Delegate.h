#pragma once
#include <list>


class IDelegateVoid
{
public:
	virtual ~IDelegateVoid() {};
	virtual void Invoke() = 0;
	virtual bool Compare(IDelegateVoid* Delegate) = 0;
public:
	std::string DelegateName;
};

class CStaticDelegateVoid : public IDelegateVoid
{
public:
	typedef void(*PFunc)();
	CStaticDelegateVoid(PFunc Func, std::string InDelegateName) 
	{ 
		Func_ = Func;
		DelegateName = InDelegateName;
	}
	virtual void Invoke() override { Func_(); };
	virtual bool Compare(IDelegateVoid* Delegate) override
	{
		CStaticDelegateVoid* StaticDelegate = static_cast<CStaticDelegateVoid*>(Delegate);
		if (!StaticDelegate || StaticDelegate->Func_ != Func_)
		{
			return false;
		}
		return true;
	}
private:
	PFunc Func_;
};


template<class TObj>
class CMethodDelegateVoid : public IDelegateVoid
{
public:
	typedef void(TObj::* PMethod)();
	CMethodDelegateVoid(TObj* Obj, PMethod Method, std::string InDelegateName)
	{
		Method_ = Method;
		Obj_ = Obj;
		DelegateName = InDelegateName;
	}
	virtual void Invoke() override {( Obj_->*Method_)(); }
	virtual bool Compare(IDelegateVoid* Delegate) override
	{
		CMethodDelegateVoid* MethodDelegate = dynamic_cast<CMethodDelegateVoid*>(Delegate);
		if (!MethodDelegate || MethodDelegate->Obj_ != Obj_ || MethodDelegate->Method_ != Method_)
		{
			return false;
		}
		return true;
	}
private:
	PMethod Method_;
	TObj* Obj_;
};

IDelegateVoid* NewDelegate(void (*Func)(), std::string DelegateName);

template<class TObj>
IDelegateVoid* NewDelegate(TObj* Obj, void(TObj::* Func)(), std::string DelegateName)
{
	return new CMethodDelegateVoid<TObj>(Obj, Func, DelegateName);
}


class CDelegateVoid
{
public:
	CDelegateVoid(IDelegateVoid* Delegate, std::string InDelegateName) { Add(Delegate); if (Delegate) { DelegateName = InDelegateName; } }
	virtual ~CDelegateVoid() { RemoveAll(); };
public:
	CDelegateVoid& operator=(IDelegateVoid* Delegate)
	{
		RemoveAll();
		Add(Delegate);
		if (Delegate)
		{
			DelegateName = Delegate->DelegateName;
		}
		return *this;
	}
	CDelegateVoid& operator+=(IDelegateVoid* Delegate)
	{
		Add(Delegate);
		return *this;
	}
	CDelegateVoid& operator-=(IDelegateVoid* Delegate)
	{
		Remove(Delegate);
		return *this;
	}
	void operator()()
	{
		Invoke();
	}
private:
	void Add(IDelegateVoid* Delegate);
	void Remove(IDelegateVoid* Delegate);
	void RemoveAll();
	void Invoke();
private:
	std::list<IDelegateVoid*> DelegatesList_;
public:
	std::string DelegateName;
};