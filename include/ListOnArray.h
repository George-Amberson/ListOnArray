#pragma once
#include <iostream>
#include <cmath>
#include <exception>
using namespace std;


template<class A1>
class ListOnArray
{
public:
	ListOnArray(int _size=5)
	{
		data = new A1[_size];
		links = new int[_size];
		for (int i = 0; i < _size; i++) links[i] = -2;
		root = -1;
		size = _size;
		DataCount = 0;
	}
	
	ListOnArray(ListOnArray& lhs)
	{
		data = new A1[lhs.size];
		links = new int[lhs.size];
		root = lhs.root;
		for (int i = 0; i < lhs.size; i++) links[i] = lhs.links[i];
		while (root != -1)
		{
			data[root] = lhs.data[root];
			root = lhs.links[root];
		}
		root = lhs.root;
		size = lhs.size;
	}
	~ListOnArray()
	{
		if (data != nullptr)
		{
			delete[] data;

		}
		if (links != nullptr)
		{
			delete[] links;
		}
	}
	bool IsEmpty()
	{
		return(root == -1);
	}
	bool IsFull()
	{
		return(DataCount == size);
	}
	int GetSize()
	{
		return size;
	}
	void push_back(const A1& lhs)
	{
		if (this->IsFull()) throw logic_error("container is full");
		if (this->IsEmpty())
		{
			root = 0;
			data[0] = lhs;
			links[0] = -1;
			DataCount++;
			return;
		}
		int k = 0;
		while (links[k] != -2) k++;
		int j = root;
		while (links[j] != -1)
		{
			j = links[j];
		}
		data[k] = lhs;
		links[j] = k;
		links[k] = -1;
		DataCount++;
		
		
	}
	void push_front(const A1& lhs)
	{
		if (this->IsFull()) throw logic_error("container is full");
		if (this->IsEmpty())
		{
			root = 0;
			data[0] = lhs;
			links[0] = -1;
			DataCount++;
			return;
		}
		int k = 0;
		while (links[k] != -2) k++;
		
		data[k] = lhs;
		links[k] = root;
		root = k;
		DataCount++;
	}
	A1& pop_front()
	{
		if (this->IsEmpty()) throw logic_error("container is empty");
		A1 tmp = data[root];
		int t = links[root];
		links[root] = -2;
		root = t;
		DataCount--;
		return tmp;
	}
	A1& pop_back()
	{
		if (this->IsEmpty()) throw logic_error("container is empty");
		int j = root;
		if (DataCount > 1) {
			while (links[links[j]] != -1)
			{
				j = links[j];
			}
			links[links[j]] = -2;
			j = links[j];
			links[j] = -1;
		}
		else
		{
			links[root] = -2;
			root = -1;
		}
		A1 tmp = data[j];
		DataCount--;
		return tmp;
	}
	
	
private:
	A1* data;
	int* links;
	int root;
	int size;
	int DataCount;
};
