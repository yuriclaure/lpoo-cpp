#include <stdio.h>

using namespace std;

class StringData {

	private:

		friend class String;
		int refCount;
		int len;
		~StringData() {

		}
		StringData(int len) {
			refCount = 1;
			this->len = len;
		}
		StringData(const char*);
		char* buffer() {
			//return (char*)(this + 8);
			return (((char*) this) + 8);
		}

	private:

		void* operator new(size_t size, int len) {
			return ::operator new(size + round4(len + 1));
		}
		static int round4(int len) {
			return ((((int) (len / 4)) + 1) * 4);
		}

		void operator delete(void* obj) {
			::operator delete(obj);
		}
		void operator delete(void* obj, int size) {
			::operator delete(obj);
		}

};

class String {

	private:
		StringData* data;

	public:
		String(const char*);
		String(const String&);
		~String();
		String& operator =(const String&);
		String& operator=(const char* string);
		int length() const;
		bool operator ==(const String&) const;
		int compare(const String&) const;
		bool operator ==(const char*) const;
		int compare(const char*) const;
		String& operator +(String&) const;
		String& operator +(const char*) const;
		String& operator +=(String&);
		String& operator +=(const char*);
		String& toLower();
		String& toUpper();
		char& operator[](int) const;
		char& operator[](int);
		void print() const;
};
