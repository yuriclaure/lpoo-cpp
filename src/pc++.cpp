//============================================================================
// Name        : pc++.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "String.h"
#include "Collection.h"
#include "Array.h"
#include "TreeSet.h"

int main(void) {

	/* TESTING ARRAY CLASS WITH INT */
	puts("******************* TESTING ARRAY WITH INT *******************");
	Array<int, 10> array;

	/* Adding */
	puts("\n- Adding");
	for (int i = 0; i < 20; i++)
		array.add(i);

	/* Printing with iterator */
	puts("\n- Printing with iterator");
	for (Iterator<int> * i = array.iterator(); i->hasNext();)
		printf("%d ", i->next());
	printf("\n");

	/* Removing */
	puts("\n- Removing");
	for (int i = 10; i <= 15; i++)
		array.remove(i);

	/* Printing by direct access */
	puts("\n- Printing by direct access");
	for (int i = 0; i < array.size(); i++)
		printf("%d ", array[i]);
	printf("\n");

	/* TESTING TREESET CLASS WITH INT */
	puts("\n******************* TESTING TREESET WITH INT *******************");
	TreeSet<int> tree;

	/* Adding the values from array */
	puts("\n- Adding the values from the array");
	tree.add(array);

	/* Printing with iterator in InOrder */
	puts("\n- Printing with iterator in InOrder order");
	for (Iterator<int> * i = tree.iterator(); i->hasNext();)
		printf("%d ", i->next());
	printf("\n");

	/* Removing */
	puts("\n- Removing");
	for (int i = 5; i <= 10; i++)
		tree.remove(i);

	/* Printing with iterator in PostOrder */
	puts("\n- Printing with iterator in PostOrder order");
	for (Iterator<int> * i = tree.tIterator(PostOrder); i->hasNext();)
		printf("%d ", i->next());
	printf("\n");

	/* TESTING STRING */
	puts("\n******************* TESTING STRING *******************");

	/* Using the copy constructor */
	puts("\n- Creating using copy constructor");
	String string1 = "primeira string";
	String string2 = "segunda string";

	/* Using the atribution operator */
	puts("\n- Creating using atribution operator");
	String string3;
	String string4;
	string3 = "terceira string";
	string4 = "quarta string";

	String string5;
	puts("\n- Concatenation");
	string5 += string1;
	string5.print();
	puts("\n- Concatenation using atribution");
	string5 = string1 + string4;
	string5.print();

	string5 = string1;

	/* Comparation */
	puts("\n- Comparation");
	if (string5 == string1)
		puts("EQUAL");
	else
		puts("NOT EQUAL");

	if (string5 == "primeira string")
		puts("EQUAL");
	else
		puts("NOT EQUAL");

	if (string5 == "primeira")
		puts("EQUAL");
	else
		puts("NOT EQUAL");

	if (string5 == string2)
		puts("EQUAL");
	else
		puts("NOT EQUAL");

	/* TESTING ARRAY CLASS WITH String */
	puts("\n******************* TESTING ARRAY WITH String *******************");
	Array<String> StringArray;

	/* Adding */
	puts("\n- Adding");
	StringArray.add("string1");
	StringArray.add("string2");
	StringArray.add(string3);
	StringArray.add(string4);

	/* Printing with iterator */
	puts("\n- Printing with iterator");
	for (Iterator<String> * i = StringArray.iterator(); i->hasNext();)
		(i->next()).print();
	printf("\n");

	/* Removing */
	puts("\n- Removing");
	StringArray.remove(string3);
	StringArray.remove("string1");

	/* Printing by direct access */
	puts("\n- Printing by direct access");
	for (int i = 0; i < StringArray.size(); i++)
		printf("%s\n", (StringArray[i]).toString());

	/* TESTING TREESET CLASS WITH STRING */
	puts("\n******************* TESTING TREESET WITH STRING *******************");
	TreeSet<String> StringTree;

	/* Adding */
	puts("\n- Adding");
	StringTree.add("string1");
	StringTree.add("string2");
	StringTree.add(string3);
	StringTree.add(string4);

	/* Printing with iterator in InOrder */
	puts("\n- Printing with iterator in InOrder order");
	for (Iterator<String> * i = StringTree.iterator(); i->hasNext();)
		printf("%s\n", (i->next()).toString());

	/* Removing */
	puts("\n- Removing");
	StringTree.remove(string3);
	StringTree.remove("string1");

	/* Printing with iterator in PostOrder */
	puts("\n- Printing with iterator in PostOrder order");
	for (Iterator<String> * i = StringTree.tIterator(PostOrder); i->hasNext();)
		printf("%s\n", (i->next()).toString());

	return 0;
}
