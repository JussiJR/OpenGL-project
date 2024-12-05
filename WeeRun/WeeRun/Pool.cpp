#include "Pool.h"

template<class T>
Pool<T>::Pool(int size, bool InitializeStatic)
{
	if (InitializeStatic) {
		_staticData = new T[size];
		_staticMaxSize = size;
	}
	_data = new T[size];
	_maxSize = size;
}

template<class T>
inline T* Pool<T>::operator[](int i)
{
	return &(_staticData[i]);
}

template<class T>
T Pool<T>::Pop()
{
	T ret = *_data[_index--];
	return ret;
}

template<class T>
T Pool<T>::Remove(int i)
{
	_staticData[i == -1 ? _staticIndex : i] = NULL;
}

template<class T>
void Pool<T>::Add(T* entity)
{
	//Resize of fifo collection
	if (_staticIndex == _staticMaxSize) {
		T* nArray = new T[_staticMaxSize * 2];
		copy(_staticData, _staticData + _staticMaxSize, nArray);
		delete[] _staticData;
		_staticData = nArray;
	}

	_staticData[++_staticIndex] = *entity;
}

template<class T>
void Pool<T>::Push(T entity)
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

