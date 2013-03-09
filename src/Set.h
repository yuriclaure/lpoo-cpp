/*
 * Set.h
 *
 *  Created on: 05/03/2013
 *      Author: yuriclaure
 */

#ifndef SET_H_
#define SET_H_

#include "Collection.h"

template<typename E>
class Set;
template<typename E>
class SortedSet;
template<typename E>
class SetIterator;

template<typename E>
class SetNode {
	private:
		friend class Set<E> ;
		friend class SortedSet<E> ;
		friend class SetIterator<E> ;
		E value;
		SetNode<E> * next;
		SetNode(const E& value) :
				value(value), next(0) {
		}

};

template<typename E>
class SetIterator: public Iterator<E> {
	private:
		SetNode<E> * node;
	public:
		SetIterator(SetNode<E> * head) {
			this->node = head;
		}
		virtual ~SetIterator() {
		}
		virtual bool hasNext() const {
			return !(node == 0);
		}
		virtual const E& next() {
			SetNode<E> * result = node;
			node = node->next;
			return result->value;
		}
};

template<typename E>
class Set: public Collection<E> {
	protected:
		SetNode<E> * head;
		SetNode<E> * tail;
		int numberOfElements;

	public:
		using Collection<E>::add;
		Set() :
				head(0), tail(0), numberOfElements(0) {
		}
		virtual ~Set() {
			clear();
		}
		virtual void add(const E& value);
		virtual bool remove(const E& value);
		virtual void clear();
		virtual bool isEmpty() const {
			return numberOfElements == 0;
		}
		virtual int size() const {
			return numberOfElements;
		}
		virtual bool contains(const E& value) const;
		virtual Iterator<E>* iterator() const {
			return new SetIterator<E>(head);
		}

};

template<typename E>
void Set<E>::add(const E& value) {
	if (!contains(value)) {
		SetNode<E> * node = new SetNode<E>(value);

		if (head == 0)
			head = node;
		else
			tail->next = node;
		tail = node;

		++numberOfElements;
	}
}

template<typename E>
bool Set<E>::remove(const E& value) {
	if (contains(value)) {
		SetNode<E> * previousNode = 0;
		for (SetNode<E> * node = head; node != 0; node = node->next) {
			if (node->value == value) {
				if (previousNode != 0)
					previousNode->next = node->next;
				delete node;
				numberOfElements--;
				return true;
			}
			previousNode = node;
		}
		return false;
	} else {
		return false;
	}

}

template<typename E>
void Set<E>::clear() {

	while (head != 0) {
		SetNode<E> * temp = head;

		head = head->next;
		delete temp;
	}
	tail = 0;
	numberOfElements = 0;
}

template<typename E>
bool Set<E>::contains(const E& value) const {
	for (SetNode<E> * node = head; node != 0; node = node->next)
		if (node->value == value)
			return true;
	return false;
}

template<typename E>
class SortedSet: public Set<E> {
	public:
		using Collection<E>::add;
		SortedSet() {
			this->head = 0;
			this->tail = 0;
			this->numberOfElements = 0;
		}
		virtual ~SortedSet() {
			Set<E>::clear();
		}
		virtual void add(const E& value);

};

template<typename E>
void SortedSet<E>::add(const E& value) {
	if (!contains(value)) {
		SetNode<E> * node = new SetNode<E>(value);

		if (this->head == 0) {
			this->head = node;
		} else {
			SetNode<E> * previousNode = 0;
			for (SetNode<E> * iteratorNode = this->head; iteratorNode != 0; iteratorNode = iteratorNode->next) {
				if (iteratorNode->value > value) {
					if (previousNode != 0) {
						previousNode->next = node;
					} else {
						this->head = node;
					}
					node->next = iteratorNode;

					break;
				} else if (iteratorNode->next == 0) {
					iteratorNode->next = node;
					break;
				}
				previousNode = iteratorNode;
			}

		}

		this->numberOfElements++;
	}
}

#endif /* SET_H_ */
