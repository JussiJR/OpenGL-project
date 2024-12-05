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
/// NOTE: Many of the methods mess up with pointers to memory and may be invalid since no checks are implemented
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
	/// Cosntructor for pool
	/// </summary>
	/// <param name="size">size of collections</param>
	/// <param name="InitializeStatic">does static collection get initialized also</param>
	Pool(int size, bool InitializeStatic);
	
	
	/// <summary>
	/// Empty constructor
	/// </summary>
	Pool() {}

	
	/// <summary>
	/// Returns pointer to object in static collection
	/// </summary>
	/// <param name="i"></param>
	/// <returns></returns>
	T* operator[](int i);
	
	
	/// <summary>
	/// Pops top one out and returns it
	/// </summary>
	/// <returns></returns>
	T Pop();
	
	/// <summary>
	/// Removes Object from static collection
	/// </summary>
	/// <param name="i">index of object (-1 = top one) </param>
	/// <returns>object what was deleted from collection</returns>
	T Remove(int i);
	
	/// <summary>
	/// Adds object to static collection
	/// NOTE: does not clean up duplicate if the value is not from stack
	/// </summary>
	/// <param name="entity"> pointer to be added</param>
	void Add(T* entity);
	
	/// <summary>
	/// way to push to fifo collection
	/// NOTE: DOES NOT CLEAN UP
	/// </summary>
	/// <param name="entity">entity to be added</param>
	void Push(T entity);
};


#endif

