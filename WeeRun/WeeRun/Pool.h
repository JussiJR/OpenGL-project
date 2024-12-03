#pragma once
#ifndef __pool_h_
#define __pool_h_
#include <iostream>
#include "Entity.h"

/// <summary>
/// Uses heap for dynamic sized memory
/// </summary>
template <class T> class Pool {
private:

	/// <summary>
	/// Self made container with stack like behaiviour or something
	/// </summary>
	T* data;

	/// <summary>
	/// current index going on
	/// </summary>
	int index = 0;

	/// <summary>
	/// Amount what Pool can hold before needing to reallocate 
	/// </summary>
	int maxSize = 0;

public:

	

	/// <summary>
	/// Constructor for pool
	/// </summary>
	/// <param name="size"></param>
	Pool<T>(int size);

	/// <summary>
	/// Method for lending from pool
	/// </summary>
	/// <returns>if pool has objects it lends objcect from top like if taken from stack, if empty returns new object. </returns>
	T Lend();

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

