#pragma once
template <class T>
class ListElement {

public:
	T data;
	struct ListElement* next;
	struct ListElement* prev;
};

template <class T>
class LinkedList {
public:
	int counter;
	struct ListElement<T>* head;
	struct ListElement<T>* tail;

	ListElement<T>* createNode(T t);
	void addToTail(T data);
	void addToHead(T data);

	void showNodeData(int index);
	void setElement(int index, T data);
	void searchElement(T data);

	void removeLast();
	void removeFirst();
	bool removeElement(int index);
	bool removeElement(T data);
	void removeAll();

	void toString();
	void toString(int amount);

private:
	int listElementDataCmp(ListElement<T>* listElement, ListElement<T>* exampleData);
};