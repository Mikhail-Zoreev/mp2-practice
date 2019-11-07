﻿#pragma once

#include "Stack.h"
#include "Exception.h"
#include "TList.h"

template<typename ValueType>
class ListStack : public Stack<ValueType>
{
protected:
	TList<int, ValueType>* list;

public:
	ListStack();
	ListStack(const ListStack& temp);
	~ListStack();

	void Push(ValueType element);   //Вставить элемент
	ValueType Top() const;          //Вернуть первый элемент
	void Pop();						//Вынуть первый элемент

	bool IsEmpty() const;
	bool IsFull() const;*/
};

/*template<typename ValueType>
ListStack<ValueType>::ListStack()
{
	list = new TList<ValueType>
}

template<typename ValueType>
ListStack<ValueType>::ListStack(const ListStack& temp)
{
	list = new TList<ValueType>(*(temp->list));
}

template<typename ValueType>
ListStack<ValueType>::~ListStack()
{
	delete list;
}

template<typename ValueType>
void ListStack<ValueType>::Push(ValueType element)
{
	list->InsertForward(0 ,&element);
}

template<typename ValueType>
ValueType ListStack<ValueType>::Top() const
{
	return list->pFirst
}*/