#include"LSLL.h"
#include<bitset>
template<typename T>
void deleteGreaterValuesOnRightSide(LSLL<T>& list)
{
	Node<T>* fast = nullptr;
	Node<T>* slow = nullptr;
	if (list.getHead())
	{
		slow = list.getHead();
		fast = slow->next;
	}
	while (fast != nullptr)
	{
		if (slow->info < fast->info)
		{
			T temp = slow->info;
			slow = slow->next;
			fast = fast->next;
			list.remove(temp);
			continue;
		}
		slow = slow->next;
		fast = fast->next;
	}
}

template<typename T>
Node<T>* findMiddle(Node<T>* start)
{
	Node<T>* slow = start;
	Node<T>* fast = start;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

template<typename T>
Node<T>* binarySearch(LSLL<T>& list,T value)
{
	if (list.getHead())
	{
		Node<T>* first = list.getHead();
		Node<T>* last = nullptr;
		Node<T>* middle = nullptr;
		do
		{
			middle = findMiddle(first, last);


			if (middle->info == value)
			{
				return middle;
			}
			else if (middle->info > value)
			{
				last = middle;
			}
			else
			{
				first = middle->next;
			}

		} while (middle != first && middle->next != nullptr);
		return nullptr;
	}
	return nullptr;
}
template<typename T>
bool detectJoiningPoint(LSLL<T>& list1, LSLL<T>& list2)
{
	int length1 = list1.checkLength();
	int length2 = list2.checkLength();
	int num = 0;
	if (length1 > length2)
	{
		num = length1 - length2;
	}
	else
		num = length2 - length1;
	if (length1 > length2)
	{
		int count = 0;
		Node<T>* temp = list1.getHead();
		Node<T>* ptr1 = temp;
		Node<T>* ptr2 = list2.getHead();
		while (count != num)
		{
			count++;
			temp = temp->next;
		}
		ptr1 = temp;
		while (ptr1 != nullptr && ptr2 != nullptr)
		{
			if (ptr1 == ptr2)
			{
				return true;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return false;
	}
	else
	{
		int count = 0;
		Node<T>* temp = list2.getHead();
		Node<T>* ptr1 = temp;
		Node<T>* ptr2 = list1.getHead();
		while (count != num)
		{
			count++;
			temp = temp->next;
		}
		ptr1 = temp;
		while (ptr1 != nullptr && ptr2 != nullptr)
		{
			if (ptr1 == ptr2)
			{
				return true;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return false;
	}
}
template<typename T>
Node<T>* detectCycle(LSLL<T>& list)
{
	if (list.getHead())
	{
		Node<T>* slow = list.getHead();
		Node<T>* fast = list.getHead();
		while (fast != nullptr)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast == nullptr)
			{
				exit(0);
			}
			else
				fast = fast->next;
			if (slow == fast)
			{
				return slow;
			}
		}
		exit(0);
	}
}
template<typename T>
void deleteCycle(LSLL<T>& list)
{
	Node<T>* fast = detectCycle(list);
	if (fast==nullptr)
	{
		return;
	}
	Node<T>* prev = fast;
	Node<T>* temp = list.getHead();
	while (temp != fast)
	{
		temp = temp->next;
		prev = fast;
		fast = fast->next;
	}
	prev->next = nullptr;

}
//template<typename T>
//Node<T>* XOR(Node<T>* next, Node<T>* prev)
//{
//	return (Node<T>*)(((unsigned long long int)next ^ (unsigned long long int)prev));
//}
//template<typename T>
//void findingPair(LSLL<T>& list, T val)
//{
//	if (list.getHead() == nullptr || list.getHead()->next == nullptr)
//	{
//		return;
//	}
//	Node<T>* start = list.getHead();
//	Node<T>* prev = nullptr;	
//	while (start != nullptr)
//	{
//		Node<T>* nexti = start->next;
//		start->next = XOR(nexti,prev);
//		prev = start;
//		start = nexti;
//	}
//	Node<T>* temp = list.getHead();
//	Node<T>* prev2 = nullptr;
//	while (temp!=nullptr)
//	{
//		cout << temp->info << " ";
//		prev2 = temp;
//		temp = XOR(prev2,temp->next);
//
//	}
//
//}
template<typename T>
void reArrangeInZigZag(LSLL<T>& list)
{
	if (list.getHead() == nullptr || list.getHead()->next == nullptr)
	{
		return;
	}
	list.sortByReference();
	int length = list.checkLength();
	int node1 = 2;
	int node2 = 3;
	while (node2 != length)
	{
		list.swapNodes(node1, node2);
		node1 += 2;
		node2 += 2;
	}
	list.swapNodes(node1, node2);
}
template<typename T>
void newRearrangeInZigZag(LSLL<T>& list)
{
	if (list.getHead() == nullptr || list.getHead()->next == nullptr)
	{
		return;
	}
	bool flag = true;
	Node<T>* temp = list.getHead();
	Node<T>* nexti = list.getHead()->next;
	while (nexti != nullptr)
	{
		if (flag)
		{
			if (temp->info > nexti->info)
			{
				T inf = temp->info;
				temp->info = nexti->info;
				nexti->info = inf;
			}
			flag = false;
			nexti = nexti->next;
			temp = temp->next;
		}
		else
		{
			if (temp->info < nexti->info)
			{
				T inf = temp->info;
				temp->info = nexti->info;
				nexti->info = inf;
			}
			flag = true;
			nexti = nexti->next;
			temp = temp->next;
		}
	}
}
template<typename T>
bool checkPalindromeInBigOn(LSLL<T> &link)
{
	Node<int>* slow = link.getHead();
	Node<int>* prevOfSlow = link.getHead();
	Node<int>* fast = link.getHead();
	while (fast->next && fast->next->next)
	{
		prevOfSlow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << slow->info << endl;
	if (fast->next == nullptr)
	{
		prevOfSlow->next = nullptr;
		slow = slow->next;
	}
	else
	{
		slow = slow->next;
		prevOfSlow->next->next = nullptr;
	}
	LSLL<T> dummy;
	while (slow != nullptr)
	{
		dummy.insertAtTail(slow->info);
		slow = slow->next;
	}
	dummy.reverseList();
	slow = dummy.getHead();
	fast = link.getHead();
	while (slow != nullptr)
	{
		if (slow->info == fast->info)
		{
			slow = slow->next;
			fast = fast->next;
		}
		else
			return false;
	}
	return true;
	

	
	return true;
}
int main()
{
	/*cout << endl << endl;
	LSLL<int> checkPalindrom;
	checkPalindrom.insertAtTail(1);
	checkPalindrom.insertAtTail(3);
	checkPalindrom.insertAtTail(1);
	checkPalindrom.insertAtTail(2);
	checkPalindrom.insertAtTail(1);
	checkPalindrom.insertAtTail(3);
	checkPalindrom.insertAtTail(1);

	cout << checkPalindromeInBigOn(checkPalindrom);*/
	LSLL<int> check;
	check.insertAtTail(1);
	check.insertAtTail(2);
	check.insertAtTail(3);
	check.ReverseLinkListRecursively(check.getHead(),check.getHead());
	check.PrintRecursively(check.getHead());


	




	return 0;
}