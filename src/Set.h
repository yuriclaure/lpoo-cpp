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
class Set: public Collection<E> {

};

template<typename E>
class SortedSet: public Set<E> {

};

#endif /* SET_H_ */
