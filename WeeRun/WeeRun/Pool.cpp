#include "Pool.h"

template<class T>
Pool<T>::Pool(int fifosize,int staticsize)
{
	_data = new T[size+staticsize];
	_staticMaxSize = staticsize
	_maxSize = size;

}

template<class T>
inline T* Pool<T>::operator[](int i)
{
	return &(_staticData[i<0 ? _staticIndex : i]);
}

template<class T>
T Pool<T>::Pop()
{
	if (_index == (_staticMaxSize - 1)) return NULL;
	T ret = *_data[_index--];
	return ret;
}

template<class T>
void Pool<T>::Remove(int i)
{
	if (i >= _staticMaxSize) return NULL;
	_data[i == -1 ? _staticIndex : i] = NULL;
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

template<class T>
bool Pool<T>::Contains(T reference)
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

template<class T>
T* Pool<T>::getBuffer() const
{
	return _data;
}

