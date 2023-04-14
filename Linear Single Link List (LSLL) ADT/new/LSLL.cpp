#include"LSLL.h"
template <typename T>
LSLL<T>::LSLL()
{
	head = nullptr;
}
template <typename T>
void LSLL<T>::insertAtHead(T val)
{
	Node<T>* temp = nullptr;
	temp = head;
	head = new Node<T>(val);
	head->next = temp;
}
template <typename T>
void LSLL<T>::print()
{
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->info << " ";
		temp = temp->next;
	}
}
template<typename T>
LSLL<T>::~LSLL()
{
	{
		if (head)
		{
			Node<T>* previous = head;
			Node<T>* temp = head->next;
			while (temp != nullptr)
			{
				delete previous;
				previous = temp;
				temp = temp->next;
			}
			delete previous;
			head = nullptr;
		}
	}
}
template <typename T>
void LSLL<T>::insertAtTail(T val)
{
	if (head == nullptr)
	{
		this->insertAtHead(val);
		return;
	}
	Node<T>* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = new Node<T>(val);
}
template <typename T>
void LSLL<T>::insertAfter(T key, T val)
{
	Node<T>* obj = head;
	while (obj != nullptr)
	{
		if (obj->info == key)
		{
			Node<T>* p = new Node<T>(val);
			p->next = obj->next;
			obj->next = p;
			return;
		}
		obj = obj->next;
	}
}
template<typename T>
void LSLL<T>::insertBefore(T key, T val)
{
	if (head)
	{
		if (head->info == key)
		{
			this->insertAtHead(val);
			return;
		}
		Node<T>* obj = head->next;
		Node<T>* prev = head;
		while (obj != nullptr)
		{
			if (obj->info == key)
			{
				Node<T>* p = new Node<T>(val);
				p->next = obj;
				prev->next = p;
				return;
			}
			prev = obj;
			obj = obj->next;
		}
	}
}
template<typename T>
void LSLL<T>::removeAtHead()
{
	if (!head)
	{
		return;
	}
	Node<T>* obj = head;
	head = head->next;
	delete obj;
}
template<typename T>
void LSLL<T>::removeAtTail()
{
	if (head)
	{
		if (head->next == nullptr)
		{
			this->removeAtHead();
			return;
		}

		Node<T>* obj = head->next;
		Node<T>* prev = head;
		while (obj->next != nullptr)
		{
			prev = obj;
			obj = obj->next;
		}
		delete prev->next;
		prev->next = nullptr;
	}
}
template<typename T>
void LSLL<T>::removeAfter(T key)
{
	Node<T>* obj = head;
	while (obj != nullptr)
	{
		if (obj->info == key)
		{
			if (obj->next == nullptr)
			{
				return;
			}
			Node<T>* temp = obj->next->next;
			delete obj->next;
			obj->next = temp;
			return;
		}
		obj = obj->next;
	}
}
template<typename T>
void LSLL<T>::removeBefore(T key)
{
	if (head)
	{
		if (head->next == nullptr || head->info == key)
		{
			return;
		}
		else if (head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* obj = head->next->next;
		Node<T>* prev = head;
		while (obj != nullptr)
		{
			if (obj->info == key)
			{
				delete prev->next;
				prev->next = obj;
			}
			obj = obj->next;
			prev = prev->next;
		}
	}
}
template<typename T>
void LSLL<T>::remove(T key)
{
	if (head)
	{
		if (head->info == key)
		{
			this->removeAtHead();
			return;
		}
		Node<T>* temp = head->next;
		Node<T>* prev = head;

		while (temp != nullptr)
		{
			if (temp->info == key)
			{
				Node<T>* cpy = temp->next;
				delete prev->next;
				prev->next = cpy;
				return;
			}
			prev = temp;
			temp = temp->next;
		}
	}
}
template<typename T>
LSLL<T>::LSLL(const LSLL<T>& ref) :LSLL()
{
	if (!ref.head)
	{
		return;
	}
	*this = ref;
}
template<typename T>
LSLL<T>& LSLL<T>::operator=(const LSLL<T>& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~LSLL();
	if (ref.head == nullptr)
	{
		return *this;
	}
	Node<T>* cpy = ref.head;
	while (cpy != nullptr)
	{
		this->insertAtTail(cpy->info);
		cpy = cpy->next;
	}
	return *this;
}
template<typename T>
void LSLL<T>::sortByCopy()
{
	if (head)
	{
		Node<T>* temp1 = head;
		Node<T>* temp2 = head->next;
		while (temp1 != nullptr)
		{
			temp2 = temp1->next;
			while (temp2 != nullptr)
			{
				if (temp1->info > temp2->info)
				{
					T temp = temp1->info;
					temp1->info = temp2->info;
					temp2->info = temp;
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
}
template<typename T>
void LSLL<T>::sortByReference()
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	Node<T>* temp = head;
	int node1 = 1;
	int node2 = 1;
	while (temp != nullptr)
	{
		Node<T>* temp2 = temp->next;
		node2 = node1 + 1;
		while (temp2 != nullptr)
		{
			if (temp->info > temp2->info)
			{
				Node<T>* copy = temp;
				temp = temp2;
				temp2 = copy;
				swapNodes(node1, node2);
			}
			node2++;
			temp2 = temp2->next;
		}
		node1++;
		temp = temp->next;
	}
}
template<typename T>
LSLL<T> LSLL<T>::doUnion(LSLL<T>& list2)
{
	LSLL<T> result;
	Node<T>* temp=this->head;
	while (temp != nullptr)
	{
		if (result.checkPresence(temp->info) == false)
		{
			result.insertAtTail(temp->info);
		}
		temp = temp->next;
	}
	temp = list2.head;
	while (temp != nullptr)
	{
		if (result.checkPresence(temp->info) == false)
		{
			result.insertAtTail(temp->info);
		}
		temp = temp->next;
	}
	return result;
}
template<typename T>
void  LSLL<T>::setHead(Node<T>* hea)
{
	head = hea;
}

template<typename T>
bool LSLL<T>::checkPresence(T num)
{
	Node<T>* temp = this->head;
	while (temp != nullptr)
	{
		if (temp->info == num)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}
template<typename T>
bool LSLL<T>::isEqual(LSLL<T>& list2)
{
	Node<T>* temp = list2.head;
	if (this->checkLength() != list2.checkLength())
	{
		return false;
	}
	while (temp != nullptr)
	{
		if (this->checkPresence(temp->info) == false)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}
template<typename T>
int LSLL<T>::checkLength()
{
	int length = 0;
	Node<T>* temp = this->head;
	while (temp != nullptr)
	{
		length++;
		temp = temp->next;
	}
	return length;
}
template<typename T>
LSLL<T> LSLL<T>::createClone()
{
	return *this;
}
template<typename T>
void LSLL<T>::delAlternate()
{
	if (head)
	{
		Node<T>* temp = head->next;
		Node<T>* prev = head;
		while (temp != nullptr)
		{
			Node<T>* temp1 = temp->next;
			delete prev->next;
			prev->next = temp1;
			prev = prev->next;
			if (prev == nullptr)
			{
				temp = nullptr;
			}
			else
				temp = prev->next;
		}
	}
}
template<typename T>
void LSLL<T>::splitList(LSLL<T>& list1, LSLL<T>& list2)
{
	int length = this->checkLength();
	int first = 0;
	if (length % 2 == 0)
	{
		first = length / 2;
	}
	else
	{
		first = (length / 2) + 1;
	}
	list1.head = this->head;
	Node<T>* temp = this->head;
	Node<T>* prev = nullptr;
	for (int i = 1; i <= first; i++)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = nullptr;
	list2.head = temp;
	head = nullptr;
}
template<typename T>
void LSLL<T>::removeDuplicates()
{
	LSLL<T> temp;
	Node<T>* iterator = head;
	Node<T>* prev = nullptr;
	while (iterator != nullptr)
	{
		if (temp.checkPresence(iterator->info))
		{
			Node<T>* temp = prev->next;
			prev->next = prev->next->next;
			delete temp;
			iterator = prev->next;
			continue;
		}
		else
			temp.insertAtHead(iterator->info);

		prev = iterator;
		iterator = iterator->next;
	}
}
template<typename T>
LSLL<T>  LSLL<T>::mergeSortedList(LSLL<T>& list2)
{
	LSLL<T> result = *this;
	result.removeDuplicates();
	Node<T>* temp1 = list2.head;
	while (temp1 != nullptr)
	{
		if (temp1->info < result.head->info)
		{
			result.insertAtHead(temp1->info);
		}
		else
		{
			Node<T>* tempResult = result.head;
			while (tempResult!=nullptr)
			{
				if (tempResult->next == nullptr&&temp1->info>tempResult->info)
				{
					tempResult->next = new Node<T>(temp1->info);
					break;
				}
				else
				{
					if (temp1->info > tempResult->info && temp1->info < tempResult->next->info)
					{
						Node<T>* ptr = new Node<T>(temp1->info);
						ptr->next = tempResult->next;
						tempResult->next = ptr;
						ptr = nullptr;
						break;
					}
				}
				tempResult = tempResult->next;
			}			
		}
		temp1 = temp1->next;
	}
	return result;
}
template<typename T>
void LSLL<T>::reversePrint()
{
	LSLL<T> temp;
	Node<T>* iterator = this->head;
	while (iterator != nullptr)
	{

		temp.insertAtHead(iterator->info);
		iterator = iterator->next;
	}
	temp.print();
}
template<typename T>
void LSLL<T>::reverseList()
{
	Node<T>* temp = this->head;
	Node<T>* dup = temp->next;
	while (dup != nullptr)
	{
		Node<T>* copyTemp = temp;
		temp = dup;
		Node<T>* copyDup = dup;
		dup = dup->next;
		copyDup->next = copyTemp;
		if (copyTemp == head)
		{
			copyTemp->next = nullptr;
		}

		
	}
	head = temp;
}
template<typename T>
void LSLL<T>::swapNodes(int num1, int num2)
{
	if (num1 == num2)
	{
		return;
	}
	int count1 = 1;
	int count2 = 1;
	Node<T>* prev1;
	Node<T>*prev2;
	Node<T>* prev=head;
	prev1 = nullptr;
	prev2 = nullptr;
	Node<T>* temp=head;
	Node<T>* temp1 = nullptr;
	Node<T>* temp2 = nullptr;
	if (head)
	{
		while (temp != nullptr)
		{
			if (count1 == num1)
			{
				prev1 = prev;
				temp1 = temp;
			}
			if (count2 == num2)
			{
				prev2 = prev;
				temp2 = temp;
			}
			count1++;
			count2++;
			prev = temp;
			temp = temp->next;
		}
	}
	if (num1 > num2)
	{
		Node<T>* copy = prev1;
		prev1 = prev2;
		prev2 = copy;
		copy = temp1;
		temp1 = temp2;
		temp2 = copy;
	}
	if (temp1 == head && temp1->next==temp2)
	{
		Node<T>* copy = head->next;
		head->next = head->next->next;
		copy->next = head;
		head = copy;
		return;
	}
	
	if (temp1 == head && temp1->next != temp2)
	{
		Node<T>* copy = prev2->next->next;
		prev2->next->next = head->next;
		head->next = copy;
		copy = head;
		head = prev2->next;
		prev2->next = copy;
		return;
	}
	if (temp1->next != temp2)
	{
		Node<T>* copy = temp2->next;
		temp2->next = temp1->next;
		temp1->next = copy;
		copy = prev1->next;
		prev1->next = prev2->next;
		prev2->next = copy;
		return;
	}
	if (temp1->next == temp2)
	{
		Node<T>* copy = temp1->next;
		temp1->next = temp2->next;
		temp2->next = prev1->next;
		prev1->next = copy;
		return;
	}
}
 template<typename T>
T LSLL<T>::findMiddlePoint()
{
	Node<T>* slow = head;
	Node<T>* fast = nullptr;
	if (slow)
	{
		 fast = slow->next;
	}
	while (fast != nullptr)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast != nullptr)
		{
			fast = fast->next;
		}
	}
	return slow->info;
}
template<typename T>
Node<T>* LSLL<T>::getHead()
{
	return head;
}
template<typename T>
T LSLL<T>::valueAt(int num)
{
	Node<T>* temp = head;
	int counter = 0;
	while (temp != nullptr)
	{
		counter++;
		if (counter == num)
		{
			return temp->info;
		}
		temp = temp->next;
	}
}
template<typename T>
void LSLL<T>::deleteNode(int num)
{
	if (head)
	{
		if (num == 1)
		{
			removeAtHead();
		}
		int counter = 2;
		Node<T>* temp = head->next;
		Node<T>* prev = head;
		while (temp != nullptr)
		{
			if (counter == num)
			{
				Node<T>* copy = prev->next;
				prev->next = prev->next->next;
				delete copy;
				return;
			}
			counter++;
			prev = temp;
			temp = temp->next;
		}
	}
}
template<typename T>
bool LSLL<T>::detectCycle()
{
	if (head)
	{
		Node<T>* slow = head;
		Node<T>* fast = head;
		while (fast!=nullptr)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast == nullptr)
			{
				return false;
			}
			else
				fast = fast->next;
			if (slow == fast)
			{
				return true;
			}
		}
		return false;
	}
}
template<typename T>
LSLL<T>::LSLL(Node<T>& ref)
{
	head = &ref;
}

