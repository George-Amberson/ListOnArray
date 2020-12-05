#pragma once
#include <iostream>
#include <cmath>
#include <exception>
#include <sstream>

using namespace std;
template<class A1>
class ListOnArray;

template<class A3>
class ListOnArrayIterator
{
private:
	ListOnArray<A3> &link;
	int index;
public:
	ListOnArrayIterator(ListOnArray<A3>& _lhs,int _index=-1) :link(_lhs),index(_index) {}
	ListOnArrayIterator(ListOnArrayIterator& _lhs) :link(_lhs.link), index(_lhs.index) {}
	ListOnArrayIterator& operator =(const ListOnArrayIterator& _lhs)
	{
		index = _lhs.index;
		return(*this);
	}
	ListOnArrayIterator operator ++(int)
	{
		if (index != -1) index = link.links[index];
		return (*this);
	}
	template<class A4>
	friend bool operator !=(const ListOnArrayIterator<A4>& _lhs,const ListOnArrayIterator<A4>&_rhs)
	{
			if (_lhs.index == _rhs.index)
			{
				return false;
			}
		return true;
	}
	A3& operator *()
	{
		if (this->index == -1) throw logic_error("end iterator");
		return(link.data[index]);
	}
};

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
	ListOnArrayIterator<A1> begin()
	{
		return(ListOnArrayIterator<A1>((*this),root));
	}
	ListOnArrayIterator<A1> end()
	{
		return(ListOnArrayIterator<A1>((*this)));
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
	stringstream GCD(int k)
	{
		if (this->IsEmpty()) throw logic_error("container is empty");
		int j = root;
		stringstream s;

		while (j != -1)
		{
			if (data[j] % k == 0)s << data[j] << " ";
			j = links[j];
		}
		return s;
	}
	template<class A2>
	friend class ListOnArrayIterator;
	void reverse()
	{
		if (this->IsEmpty()) throw logic_error("container is empty");
		int tec = root;
		int prev = -1;
		int next = 0;
		while (tec != -1)
		{
			next = links[tec];
			links[tec] = prev;
			prev = tec;
			tec = next;

		}
		root = prev;
	}
private:

	A1* data;
	int* links;
	int root;
	int size;
	int DataCount;
};
	