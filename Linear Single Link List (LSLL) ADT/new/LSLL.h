#ifndef LSLL_H
#define LSLL_H
#include"Node.h"
template <typename T>
class LSLL
{
	Node<T>* head;
	bool checkPresence(T);
public:
	LSLL();
	~LSLL();
	Node<T>* getHead();
	LSLL(Node<T>&);
	void setHead(Node<T>* hea);
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void remove(T key);
	LSLL(const LSLL<T>& ref);
	LSLL<T>& operator=(const LSLL<T>& ref);
	void print();
	void sortByCopy();
	void sortByReference();
	LSLL<T> doUnion(LSLL<T>&);
	bool isEqual(LSLL<T>&);
	LSLL<T> createClone();
	void delAlternate();
	void splitList(LSLL<T>& list1, LSLL<T>& list2);
	void removeDuplicates();
	LSLL<T> mergeSortedList(LSLL<T>& list2);
	void reversePrint();
	void reverseList();
	void swapNodes(int num1, int num2);
	T findMiddlePoint();
	T valueAt(int num);
	void deleteNode(int num);
	bool detectCycle();
	int checkLength();
};
#endif 

