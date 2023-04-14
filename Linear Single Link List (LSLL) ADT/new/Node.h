#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T info;
	Node<T>* next;
	Node();
	Node(T);
};
#endif

