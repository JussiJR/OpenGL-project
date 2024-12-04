#include "Pool.h"




template<class T>
inline T Pool<T>::Lend()
{
	if (_index == -1) throw(EXCEPTIONS_POOL_EMPTY_DATA);
	return (T)_data[--_index];
}

template<class T>
T* Pool<T>::StaticPoint(int index)
{

	if (_staticIndex == -1) throw(EXCEPTIONS_POOL_EMPTY_DATA);
	return &_staticData[index == -1 ? _staticIndex: index];
}

template<class T>
void Pool<T>::StaticClean()
{

	realloc(_staticData, sizeof(T) * _index + 1);

	//FIXME: May need some additional help with memory management
	//TODO: if needed maybe need to free with loop
	_maxSize = _index + 1;
}



template<class T>
T* Pool<T>::StaticAdd(T* object)
{
	if (_staticIndex == _staticMaxSize) {
		realloc(_staticData, sizeof(T) * 2 * _index + 1);
		_staticMaxSize = 2 * _staticIndex + 1;
	}
	_staticData[_staticIndex++] = *object;
	free(object);
	return &_staticData[_staticIndex];	 
}

template<class T>
T Pool<T>::StaticStaticWRemove()
{
	if (_index == -1) throw(EXCEPTIONS_POOL_EMPTY_DATA);
	return (T)_data[--_index];
}

template<class T>
inline void Pool<T>::Trim()
{
	realloc(_data, sizeof(T) * _index + 1);
	//FIXME: May need some additional help with memory management
	//TODO: if needed maybe need to free with loop
	_maxSize = _index + 1;
}

template<class T>
void Pool<T>::ReturnObject(T* object)
{
	if (_index == _maxSize) {
		realloc(_data, sizeof(T) * 2 * _index + 1);
		_maxSize = 2 * _index + 1;
	}
	_data[_index++] = *object;
	free(object);
}
