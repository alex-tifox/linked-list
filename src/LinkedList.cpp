#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "LinkedList.h"
using namespace std;

/*
 *	MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
template <class T>
ListElement<T>* LinkedList<T>::createNode(T t)
{
	this->counter = this->counter + 1;
	struct ListElement<T> *temp;
	temp = new ListElement<T>();
	temp->data = t;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

/*
*	Inserts element to head
*/
template <class T>
void LinkedList<T>::addToHead(T data)
{
	struct ListElement<T> *temp;
	temp = createNode(data);

	if (this->head == this->tail && this->head == NULL)
	{
		std::cout << "Element inserted in empty list" << std::endl;
		this->head = this->tail = temp;
		this->head->next = this->tail->next = NULL;
		this->head->prev = this->tail->prev = NULL;
	}
	else
	{
		temp->next = this->head;
		this->head->prev = temp;
		this->head = temp;
		this->head->prev = this->tail;
		this->tail->next = this->head;
		std::cout << "Element inserted" << std::endl;
	}

	std::cout << this->head->data << std::endl;
}

/*
 *	Inserts element to tail
 */
template <class T>
void LinkedList<T>::addToTail(T data)
{
	ListElement<T> *temp;

	temp = createNode(data);

	this->tail->next = temp;
	temp->prev = this->tail;
	this->tail = temp;

	this->head->prev = this->tail;
	this->tail->next = this->head;

	std::cout << "Element inserted to tail" << endl;
	std::cout << this->tail->data << endl;
}

/*
*	Removes last element
*/
template<class T>
void LinkedList<T>::removeLast()
{
	ListElement<T> *temp;

	temp = this->tail->prev;
	delete this->tail;

	this->tail = temp;
	this->tail->next = this->head;
	this->head->prev = this->tail;
}

/*
*	Removes first element
*/
template<class T>
void LinkedList<T>::removeFirst()
{
	ListElement<T> *temp;

	temp = this->head->next;
	delete this->head;

	this->head = temp;
	this->tail->next = this->head;
	this->head->prev = this->tail;
}

/* 
*	Shows node's data by index
*/
template<class T>
void LinkedList<T>::showNodeData(int index)
{
	if (index >= this->counter || index <= 0)
	{
		cout << "Element does not exists, enter valid index" << endl;
		return;
	}

	ListElement<T> *toDisplay = this->head;

	for (int i = 0; i < this->counter; i++)
	{
		if (index == i + 1) cout << "Your element: "<< toDisplay->data << endl;
		else toDisplay = toDisplay->next;
	}
}

template<class T>
void LinkedList<T>::searchElement(T data)
{
	ListElement<T> *elementToSearch = this->head;
	bool found = false;
	ListElement<T> *toCompare = createNode(data);
	for (int i = 0; i < this->counter; i++)
	{
		if (listElementDataCmp(elementToSearch, toCompare) == 0)
		{
			cout << "Your element's found: " << elementToSearch->data << endl;
			found = true;
			return;
		}
		else
		{
			elementToSearch = elementToSearch->next;
			if (i == this->counter - 1) goto end;
		}
	}

	end:
	if (!found) cout << "Not found or something went wrong" << endl;
}

/*
*	Sets element by index with data to input
*/
template<class T>
void LinkedList<T>::setElement(int index, T data)
{
	if (index >= this->counter || index <= 0)
	{
		cout << "Element does not exists, you cannot change its data" << endl;
		return;
	}

	ListElement<T> *toChange = this->head;

	for (int i = 0; i < this->counter; i++)
	{
		if (index == i + 1) toChange->data = data;
		else toChange = toChange->next;
	}
}

/*
*	Removes element by index
*/
template<class T>
bool LinkedList<T>::removeElement(int index)
{
	if (index >= this->counter || index <= 0) 
	{
		std::cout << "Element does not exists, cannot delete. Enter valid index.\n You have "
			<< this->counter << "elements for disposition" << std::endl;
		return false;
	}
	
	bool removed;
	ListElement<T> *toDelete = this->head;

	for (int i = 0; i < this->counter; i++)
	{
		if (index == i + 1)
		{
			toDelete->prev->next = toDelete->next;
			toDelete->next->prev = toDelete->prev;
			delete toDelete;
			cout << "Element removed" << endl;
			return true;
		}
		else
		{
			toDelete = toDelete->next;
		}
	}

	return false;
}

/*
*	Removes element by data
*/
template<class T>
bool LinkedList<T>::removeElement(T data)
{
	bool removed;
	ListElement<T> *toDelete = this->head;
	ListElement<T> *toCompare = createNode(data);

	for (int i = 0; i < this->counter; i++)
	{
		if (listElementDataCmp(elementToSearch, toCompare) == 0)
		{
			toDelete->prev->next = toDelete->next;
			toDelete->next->prev = toDelete->prev;
			delete toDelete;
			cout << "Element removed" << endl;
			return true;
		}
		else
		{
			toDelete = toDelete->next;
		}
	}

	return false;
}

/*
*	Removes all data from list
*/
template<class T>
void LinkedList<T>::removeAll()
{
	ListElement<T> *toDelete;

	for (int i = 0; i < this->counter; i++)
	{
		toDelete = this->head;
		this->head = this->head->next;
		delete toDelete;
	}
	delete this;
}

/*
*	Shows all list's data
*/
template<class T>
void LinkedList<T>::toString()
{
	ListElement<char> *element = this->head;

	for (int i = 0; i < this->counter; i++)
	{
		std::cout << "Element data: " << element->data << endl;
		element = element->next;
		if (i > 0 && element == this->head) break;
	}
}

/*
*	Shows list's data regarding to input amount
*/
template<class T>
void LinkedList<T>::toString(int amount)
{
	if (amount <= 0) cout << "Enter valid amount of elements.\n You have " << this->counter << " elements to print";
	else if (amount >= this->counter)
	{
		ListElement<char> *element = this->head;

		for (int i = 0; i < this->counter; i++)
		{
			std::cout << element->data << endl;
			element = element->next;
			if (i > 0 && element == this->head) break;
		}
	} 
	else
	{
		ListElement<char> *element = this->head;

		for (int i = 0; i < amount; i++)
		{
			std::cout << element->data << endl;
			element = element->next;
			if (i > 0 && element == this->head) break;
		}
		cout << "You have " << this->counter << " elements to print";
	}
}

/*
	Comparing objects
*/
template <class T>
int LinkedList<T>::listElementDataCmp(ListElement<T>* listElement, ListElement<T>* exampleData)
{
	int diff = listElement->data - exampleData->data;
	if (diff != 0) return diff; 

	return listElement->data - exampleData->data;
}

int main()
{
	clock_t begin, end;
	double time_spent;
	begin = clock();

	LinkedList<char>*linkedLi = new LinkedList<char>();

	// a, f, b, c
	linkedLi->addToHead('f');
	linkedLi->addToHead('a');
	linkedLi->addToTail('b');
	linkedLi->addToTail('c');
	
	//linkedLi->removeLast();
	//linkedLi->removeFirst();

	//linkedLi->showNodeData(5);
	//linkedLi->showNodeData(-1);

	//linkedLi->setElement(1, 'g');

	//linkedLi->removeElement(2);
	//linkedLi->removeAll();

	linkedLi->searchElement('e');

	linkedLi->toString();

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	std::cout << time_spent << std::endl;
}


