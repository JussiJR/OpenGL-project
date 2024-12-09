#pragma once
#ifndef __pool_h_
#define __pool_h_
#include "Entity.h"

using namespace std;

/// <summary>
/// Uses heap for dynamic sized arrays and controls them.
/// NOTE: Many of the methods mess up with pointers to memory and may be invalid since no checks are implemented
/// </summary>
template <class T> class Pool {
public:

	/// <summary>
	/// Self made container with stack like behaiviour or something
	/// </summary>
	T* _data;


	/// <summary>
	/// current index going on
	/// </summary>
	int _index = 0;

	/// <summary>
	/// Amount what Pool can hold before needing to reallocate 
	/// </summary>
	int _maxSize = 0;

	/// <summary>
	/// Static array's top index
	/// </summary>
	int _staticIndex = 0;

	/// <summary>
	/// static array's max size before need for resize
	/// </summary>
	int _staticMaxSize = 0;

	/// <summary>
	/// Cosntructor for pool
	/// </summary>
	/// <param name="size">size of collections</param>
	/// <param name="InitializeStatic">does static collection get initialized also</param>
	Pool(int fifosize, int staticsize)
	{
		_data = new T[fifosize + staticsize];
		_staticMaxSize = staticsize;
		_maxSize = fifosize;

	}
	
	
	/// <summary>
	/// Empty constructor
	/// </summary>
	Pool() {}

	
	/// <summary>
	/// Returns pointer to object in static collection
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	T* operator[](int i)
	{
		if (i >= _staticMaxSize)return NULL;
		return &_data[i < 0 ? _staticIndex : i];
	}
	
	
	/// <summary>
	/// Pops top one out and returns it
	/// </summary>
	/// <returns>poped value or NULL if stack side empty</returns>
	T Pop()
	{
		if (_index == (_staticMaxSize - 1)) return NULL;
		return *_data[_index--];
	}
	
	/// <summary>
	/// Removes Object from static collection
	/// </summary>
	/// <param name="i">index of object (-1 = top one) </param>
	void Remove(int i)
	{
		if (i >= _staticMaxSize) return;
		_data[i == -1 ? _staticIndex : i] = NULL;
	}

	
	/// <summary>
	/// Adds object to static collection
	/// NOTE: does not clean up duplicate if the value is not from stack
	/// </summary>
	/// <param name="entity"> pointer to be added</param>
	void Add(T* entity)
	{
		//Resize of fifo collection
		if (_staticIndex == _staticMaxSize) throw(errno);
		_data[++_staticIndex] = *entity;
	}

	
	/// <summary>
	/// way to push to fifo collection
	/// NOTE: DOES NOT CLEAN UP
	/// </summary>
	/// <param name="entity">entity to be added</param>
	void Push(T entity)
	{
		// resize of static collection
		if (_index == _maxSize) {
			T* nArray = new T[_maxSize * 2];
			copy(_data, _data + _maxSize, nArray);
			delete[] _data;
			_data = nArray;
		}
		_data[++_index] = entity;
	}

	/// <summary>
	/// Checks if referenced value like is in fifo like collection
	/// </summary>
	/// <param name="reference">value to be checked</param>
	/// <returns>true if variable like it is in fifo like collection otherwise false</returns>
	bool Contains(T reference)
	{
		if (_index == -1) return false;

		//!	"Cache" the reference
		const long long* value = (long long*) reference;

		//!  O (n) Solution with kind of made up hashing idea
		for (int i = 0; i <= _index;i++) {
			const long long* test = (long long*)_data[i];
			if (value == test) return true;
		}

		return false;
	}

	int Count() const
	{
		return _staticMaxSize - _index + 1;
	}

};


#endif

