/*
 * TreeSet.h
 *
 *  Created on: 07/03/2013
 *      Author: yuriclaure
 */

#ifndef TREESET_H_
#define TREESET_H_

#include "Collection.h"
#include "Set.h"

typedef enum {
	PreOrder, InOrder, PostOrder
} TreeIteratorType;

template<typename E>
class TreeIterator;
template<typename E>
class TreeSet;

template<typename E>
class TreeNode {
	private:
		friend class TreeIterator<E> ;
		friend class TreeSet<E> ;
		E value;
		TreeNode<E> * leftChild;
		TreeNode<E> * rightChild;
		TreeNode(const E& value) :
				value(value), leftChild(0), rightChild(0) {
		}
};

template<typename E>
class TreeIterator: public Iterator<E> {
	private:
		Set<E> values;
		Iterator<E> * iterator;
	public:
		TreeIterator(TreeNode<E> * root, TreeIteratorType type) {
			saveValues(root, type);
			iterator = values.iterator();
		}
		virtual ~TreeIterator() {
			delete iterator;
		}
		virtual void saveValues(TreeNode<E> * node, TreeIteratorType type) {
			if (node != 0) {
				if (type == PreOrder) {
					values.add(node->value);
					saveValues(node->leftChild, type);
					saveValues(node->rightChild, type);
				} else if (type == InOrder) {
					saveValues(node->leftChild, type);
					values.add(node->value);
					saveValues(node->rightChild, type);
				} else if (type == PostOrder) {
					saveValues(node->leftChild, type);
					saveValues(node->rightChild, type);
					values.add(node->value);
				}
			}
		}
		virtual bool hasNext() const {
			return iterator->hasNext();
		}
		virtual const E& next() {
			return iterator->next();
		}
};

template<typename E>
class TreeSet: public SortedSet<E> {
	private:
		TreeNode<E> * root;
		int numberOfElements;
		virtual void recursiveAdd(TreeNode<E> *& node, const E& value);
		virtual bool recursiveRemove(TreeNode<E> *& node, const E& value);
		virtual bool recursiveContains(TreeNode<E> * node, const E& value) const;
		virtual void clear(TreeNode<E> *& node);

	public:
		using Collection<E>::add;
		TreeSet() :
				root(0), numberOfElements(0) {
		}
		virtual ~TreeSet() {
			clear();
		}
		virtual void add(const E& value) {
			if (!contains(value))
				recursiveAdd(root, value);
		}
		virtual bool remove(const E& value) {
			if (contains(value))
				return recursiveRemove(root, value);
			else
				return false;
		}
		virtual void clear() {
			clear(root);
			numberOfElements = 0;
			root = 0;
		}
		virtual bool isEmpty() const {
			return numberOfElements == 0;
		}
		virtual int size() const {
			return numberOfElements;
		}
		virtual bool contains(const E& value) const {
			return recursiveContains(root, value);
		}
		virtual Iterator<E>* iterator() const {
			return tIterator(InOrder);
		}
		virtual Iterator<E>* tIterator(TreeIteratorType type = InOrder) const {
			return new TreeIterator<E>(root, type);
		}

};

template<typename E>
void TreeSet<E>::recursiveAdd(TreeNode<E> *& node, const E& value) {
	if (node == 0) {
		node = new TreeNode<E>(value);
		numberOfElements++;
	} else {
		if (value < node->value) {
			recursiveAdd(node->leftChild, value);
		} else {
			recursiveAdd(node->rightChild, value);
		}
	}
}

template<typename E>
bool TreeSet<E>::recursiveRemove(TreeNode<E> *& node, const E& value) {

	if (node == 0)
		return false;

	if (value < node->value) {
		recursiveRemove(node->leftChild, value);
	} else if (value > node->value) {
		recursiveRemove(node->rightChild, value);
	} else {
		TreeNode<E> * temp;

		if (node->leftChild == 0) {
			temp = node->rightChild;
			delete node;
			node = temp;
		} else if (node->rightChild == 0) {
			temp = node->leftChild;
			delete node;
			node = temp;
		} else {
			temp = node->rightChild;
			TreeNode<E> * parent = 0;

			while (temp->leftChild != 0) {
				parent = temp;
				temp = temp->leftChild;
			}

			node->value = temp->value;

			if (parent != 0)
				recursiveRemove(parent->leftChild, parent->leftChild->value);
			else
				recursiveRemove(node->rightChild, node->rightChild->value);
		}
	}
	numberOfElements--;
	return true;
}

template<typename E>
bool TreeSet<E>::recursiveContains(TreeNode<E> * node, const E& value) const {
	if (node == 0)
		return false;
	if (node->value > value)
		return recursiveContains(node->leftChild, value);
	else if (node->value < value)
		return recursiveContains(node->rightChild, value);
	else
		return true;
}

template<typename E>
void TreeSet<E>::clear(TreeNode<E> *& node) {
	if (node != 0) {
		clear(node->leftChild);
		clear(node->rightChild);
		delete node;
	}
}

#endif /* TREESET_H_ */
