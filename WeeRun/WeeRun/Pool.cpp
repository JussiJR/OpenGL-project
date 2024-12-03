#include "Pool.h"


template<class T>
inline Pool<T>::Pool(int size)
{
	Data = (T*)malloc(sizeof(T) * size);
	index = -1;

}


template<class T>
inline T Pool<T>::Lend()
{

	if (index == -1) throw(EXCEPTIONS_POOL_EMPTY_DATA);
	return Data[--index];
}
template<class T>
inline void Pool<T>::Trim()
{
	realloc(data, sizeof(T) * index + 1);

	//FIXME: May need some additional help with memory management
	//TODO: if needed maybe need to free with loop
	maxSize = index + 1;
}

template<class T>
void Pool<T>::ReturnObject(T* object)
{

	if (index == maxSize) {
		realloc(data, sizeof(T) * 2 * index + 1);
		maxSize = 2 * index + 1;
	}
	data[index++] = *object;
	free(object);
}
