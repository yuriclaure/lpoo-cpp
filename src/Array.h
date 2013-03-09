/*
 * Array.h
 *
 *  Created on: 02/03/2013
 *      Author: yuriclaure
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Collection.h"

template<typename E>
class ArrayIterator: public Iterator<E> {
	private:
		E * data;
		int length;
		int currentPosition;
	public:
		ArrayIterator(E * data, int length) :
				currentPosition(0) {
			this->data = data;
			this->length = length;
		}
		virtual ~ArrayIterator() {
			printf("LOL\n");
		}
		virtual bool hasNext() const {
			return currentPosition < length;
		}
		virtual const E& next() {
			return data[currentPosition++];
		}
};

template<typename E, int initialSize = 10>
class Array: public Collection<E> {
	private:
		E * data;
		int ocupedPositions;
		int length;
	public:
		using Collection<E>::add;
		Array() :
				ocupedPositions(0), length(initialSize) {
			data = new E[initialSize];
		}

		virtual ~Array() {
			delete[] data;
		}

		void add(const E& value);
		bool remove(const E& value);
		void clear() {
			ocupedPositions = 0;
		}
		bool isEmpty() const {
			return ocupedPositions == 0;
		}
		int size() const {
			return ocupedPositions;
		}
		bool contains(const E& value) const;
		Iterator<E>* iterator() const {
			return new ArrayIterator<E>(data, ocupedPositions);
		}
		void expand();
		E& operator[](int i) const {
			return data[i];
		}
		E& operator[](int i) {
			return data[i];
		}
};

template<typename E, int initialSize>
void Array<E, initialSize>::add(const E& value) {
	if (ocupedPositions == length)
		expand();
	(*this)[ocupedPositions++] = value;
}

template<typename E, int initialSize>
bool Array<E, initialSize>::remove(const E& value) {
	if (contains(value)) {
		int i = 0;
		while ((*this)[i] != value) {
			i++;
		}

		while (i < ocupedPositions - 1) {
			(*this)[i] = (*this)[i + 1];
			i++;
		}
		ocupedPositions--;
		return true;
	} else {
		return false;
	}
}

template<typename E, int initialSize>
bool Array<E, initialSize>::contains(const E& value) const {
	for (Iterator<E>* i = iterator(); i->hasNext();)
		if (i->next() == value)
			return true;
	return false;
}

template<typename E, int initialSize>
void Array<E, initialSize>::expand() {
	E * newData = new E[length + initialSize];
	for (int i = 0; i < ocupedPositions; i++)
		newData[i] = (*this)[i];
	delete[] data;
	data = newData;
	length = length + initialSize;
}

#endif /* ARRAY_H_ */
