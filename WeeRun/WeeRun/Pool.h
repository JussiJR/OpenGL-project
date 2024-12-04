#pragma once
#ifndef __pool_h_
#define __pool_h_
#include <iostream>
#include "Entity.h"
#include <iostream>

#define EXCEPTIONS_POOL_EMPTY_DATA 0x401F

using namespace std;

/// <summary>
/// Uses heap for dynamic sized arrays and controls them.
/// </summary>
template <class T> class Pool {
private:

	/// <summary>
	/// Self made container with stack like behaiviour or something
	/// </summary>
	T* _data;

	/// <summary>
	/// Static version of data ( does not delete on trim) and can be just referenced works like list 
	/// </summary>
	T* _staticData;

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
public:

	

	/// <summary>
	/// Constructor for pool
	/// </summary>
	/// <param name="size"></param>
	Pool<T>(int size)
	{
		_data = (T*)malloc(sizeof(T) * size);
		_index = -1;
		_staticData = (T*)malloc(sizeof(T) * size);
		_staticIndex = -1;
		_staticMaxSize = _maxSize = size + 1;
	}

	/// <summary>
	/// Method for lending from pool
	/// </summary>
	/// <returns>if pool has objects it lends objcect from top like if taken from stack, if empty throws error </returns>
	T Lend();

	/// <summary>
	/// indexed get from static array
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	T* StaticPoint(int index = -1);

	void StaticClean();

	/// <summary>
	/// Adds object to static array
	/// </summary>
	/// <param name="object">Object to be added</param>
	/// <returns>new pointer to array</returns>
	T* StaticAdd(T* object);

	T StaticStaticWRemove();

	/// <summary>
	/// Trims the storage so that it fits only amount what in current moment pool holds
	/// </summary>
	void Trim();

	/// <summary>
	/// Returns the object
	/// </summary>
	void ReturnObject(T* object);
};


#endif

