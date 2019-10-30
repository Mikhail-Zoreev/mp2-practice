#pragma once

#include "TNode.h"

template <typename TKey, typename TData>
class TList
{
public:
	
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pPrevious;
	TNode<TKey, TData>* pNext;
	TNode<TKey, TData>* pCurrent;

public:
	TList();
	TList(const TList<TKey, TData>& temp);
	TList(const TNode<TKey, TData>* node_);
	~TList();

	void InsertForward(TKey key_, TData* pData_);
	void InsertBackward(TKey key_, TData* pData_);
	void InsertBefore(TKey key_b, TKey key_, TData* pData_);
	void InsertAfter(TKey key_a ,TKey key_, TData* pData_);
	
	void Remove(TKey key_);

	void Reset();
	bool IsEnded() const;
	void Next();
};

template <typename TKey, typename TData>
TList<TKey, TData>::TList()
{
	pFirst = nullptr;
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = nullptr;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TList& temp)
{
	pFirst = new TNode<TKey, TData>(*(temp.pFirst));
	TNode<TKey, TData>* node_ = pFirst, node_temp = temp.pFirst;
	while (node_temp->pNext != nullptr)
	{
		node_->pNext = new TNode<TKey, TData>(*(node_temp->pNext));
		node_ = node_->pNext;
		node_temp = node_temp->pNext;
	}
	pPrevious = nullptr;
	pNext = nullptr;
	pCurrent = pFirst;
}

template <typename TKey, typename TData>
TList<TKey, TData>::TList(const TNode<TKey, TData > * node_)
{
	
}

template <typename TKey, typename TData>
TList<TKey, TData>::~TList()
{
	TNode<TKey, TData> *del = pFirst, *next;
	while (del != nullptr)
	{
		next = del->pNext;
		delete del;
		del = next;
		
	}
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertForward(TKey key_, TData* pData_)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TKey, TData>(key_, pData_);
		pCurrent = pFirst;
		return;
	}
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	temp->pNext = pFirst;
	if (pCurrent == pFirst) pPrevious = temp;
	pFirst = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBackward(TKey key_, TData* pData_)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TKey, TData>(key_, pData_);
		pCurrent = pFirst;
		return;
	}
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	TNode<TKey, TData>* node = pFirst;
	while (node->pNext != nullptr)
	{
		node = node->pNext;
	}
	node->pNext = temp;
	if (pCurrent = node) pNext = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertBefore(TKey key_b, TKey key_, TData* pData_)
{
	if (pFirst == nullptr) return;
	if (pFirst->key == key_b)
	{
		InsertForward(key_, pData_);
		return;
	}
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node->pNext != nullptr) && (prev_node->pNext->key != key_b))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node->pNext == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext;
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	prev_node->pNext = temp;
	temp->pNext = next_node;
	if (pCurrent == prev_node) pNext = temp;
	if (pCurrent == next_node) pPrevious = temp;
}

template <typename TKey, typename TData>
void TList<TKey, TData>::InsertAfter(TKey key_a, TKey key_, TData* pData_)
{
	if (pFirst == nullptr) return;
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node != nullptr) && (prev_node->key != key_a))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext;
	TNode<TKey, TData>* temp = new TNode<TKey, TData>(key_, pData_);
	prev_node->pNext = temp;
	temp->pNext = next_node;
	if (pCurrent == prev_node) pNext = temp;
	if (pCurrent == next_node) pPrevious = temp;

}

template <typename TKey, typename TData> //��������� ��������
void TList<TKey, TData>::Remove(TKey key_)
{
	if (pFirst == nullptr) return;
	if (pFirst->key == key_)
	{
		TNode<TKey, TData>* next_node = pFirst->pNext;
		delete pFirst;
		pFirst = next_node;
		return;
	}
	TNode<TKey, TData>* prev_node = pFirst;
	while ((prev_node->pNext != nullptr) && (prev_node->pNext->key != key_))
	{
		prev_node = prev_node->pNext;
	}
	if (prev_node->pNext == nullptr) throw "Can't find";
	TNode<TKey, TData>* next_node = prev_node->pNext->pNext;
	delete prev_node->pNext;
	prev_node->pNext = next_node;
}