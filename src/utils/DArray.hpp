#ifndef DARRAY_HPP
#define DARRAY_HPP

#include <stdint.h>
#include <stdlib.h>

template <class T>
class DArray
{
	T *array;
	uint8_t size;
	uint8_t maxSize;

public:
	DArray(uint8_t maxSize);
	~DArray();

	T get(uint8_t index) const;
	uint8_t getSize() const;
	bool isEmpty() const;
	uint8_t find(T element) const;

	bool add(T element);
	bool remove(T element);
	bool removeAt(uint8_t index);
	void clear();
};


template <class T>
DArray<T>::DArray(uint8_t maxSize)
	: size(0)
	, maxSize(maxSize)
{
	array = (T*) malloc(sizeof(T) * maxSize);
}

template <class T>
DArray<T>::~DArray()
{
	free(array);
}


template <class T>
T DArray<T>::get(uint8_t index) const
{
	if (size == 0 || index >= size)
		return NULL;

	return array[index];
}

template <class T>
uint8_t DArray<T>::getSize() const
{
	return size;
}

template <class T>
bool DArray<T>::isEmpty() const
{
	return size == 0;
}

template <class T>
uint8_t DArray<T>::find(T element) const
{
	for (uint8_t i = 0; i != size; i++)
		if (array[i] == element)
			return i;

	return maxSize;
}

template <class T>
bool DArray<T>::add(T element)
{
	if (size == maxSize)
		return false;

	array[size] = element;
	size++;
	return true;
}

template <class T>
bool DArray<T>::remove(T element)
{
	return removeAt(find(element));
}

template <class T>
bool DArray<T>::removeAt(uint8_t index)
{
	if (isEmpty() || index >= size)
		return false;

	for (int i = index; i != size - 1; i++)
		array[i] = array[i + 1];

	size--;
	return true;
}

template <class T>
void DArray<T>::clear()
{
	size = 0;
}

#endif
