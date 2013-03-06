#ifndef COLLECTION_H_
#define COLLECTION_H_

template<typename E>
class Iterator {
	public:
		virtual ~Iterator() {
		}
		virtual bool hasNext() const = 0;
		virtual const E& next() = 0;
};

template<typename E>
class Collection {

	public:
		virtual void add(const E& value) = 0;
		void add(const Collection<E>& collection);
		virtual bool remove(const E& value) = 0;
		virtual void clear() = 0;
		virtual ~Collection() {
		}
		virtual bool isEmpty() const = 0;
		virtual int size() const = 0;
		virtual bool contains(const E& value) const = 0;
		virtual Iterator<E>* iterator() const = 0;

};

template<typename E>
void Collection<E>::add(const Collection<E>& collection) {
	for (Iterator<E>* i = collection.iterator(); i->hasNext();)
		this->add(i->next());

}

#endif
