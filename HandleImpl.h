#pragma once

template<class T>
class Handle
{
//private:
	T* fPointer;
	int* fCount;

	void addRef()
	{
		++*fCount;
	}
	void releaseRef()
	{
		if (--*fCount == 0)
		{
			delete fPointer;
			delete fCount;
		}
	}

//public:

	Handle(*T aPointer = (T*)0 )
	{
		fPointer = aPointer;
		fCount = new int;
		*fCount = 1;
	}

	Handle( const Handle<T>& aOtherHandle)
	{
		fPointer = aOtherHandle.fPointer;
		fCount = aOtherHandle.fCount;
		addRef();
	}

	~Handle()
	{
		releaseRef();
	}

	Handle& operator=(Handle<T>& aOtherHandle)
	{
		if (&aOtherHandle != this)
		{
			aOtherHandle.addRef();
			releaseRef();
			fPointer = aOtherHandle.fPointer;
			fCount = aOtherHandle.fCount;
		}
		return *this;
	}
	
	T& operator*()
	{
		if (fPointer)
		{
			return *fPointer;
		}
		else
		{
			throw std::runtime_error("Dereference of unbound handle!");
		}
	}

	T* operator->()
	{
		if (fPoiter)
		{
			return fPointer;
		}
		else
		{
			throw std::runtime_error("Access through unbound handle!");
		}
	}
};