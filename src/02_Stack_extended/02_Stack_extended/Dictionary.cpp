#pragma once

#include "Dictionary.h"

Dictionary::Dictionary(size_t size_)
{
	if (size_ == 0) throw Exception(CantCreate);
    size = size_;
    head = 0;
    values = new Element[size];
}

Dictionary::Dictionary(const Dictionary& temp)
{
    size = temp.size;
    head = temp.head;
    values = new Element[size];
    for (size_t i = 0; i < head; i++)
    {
        values[i] = temp.values[i];
    }
}

Dictionary::~Dictionary()
{
    delete[] values;
}

void Dictionary::Push(const std::string& key_, double value_)
{
    if (head == size)
    {
        Element* temp = new Element[size + 10];
        for (size_t i = 0; i < size; i++)
        {
            temp[i] = values[i];
        }
        delete[] values;
        values = temp;
        size += 10;
    }
    values[head].key = key_;
    values[head].value = value_;
    head++;
}

unsigned Dictionary::Count(const std::string& key_) const
{
    unsigned result = 0;
    for (size_t i = 0; i < head; i++)
    {
        if (values[i].key == key_) result++;
    }
    return result;
}

const double Dictionary::operator[](const std::string& key_) const
{
    for (size_t i = 0; i < head; i++)
    {
        if (values[i].key == key_) return values[i].value;
    }
    throw Exception(CantFind);
}

const Dictionary& Dictionary::operator=(const Dictionary& temp)
{
    if (size != temp.size) delete[] values;
    size = temp.size;
    head = temp.head;
    values = new Element[size];
    for (size_t i = 0; i < head; i++)
    {
        values[i] = temp.values[i];
    }
    return *this;
}