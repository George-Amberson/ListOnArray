#pragma once
#include <iostream>

using namespace std;
template<class A2>
class Node
{
public:
	Node() :next(nullptr){}
	A2 value;
	Node* next;
};

template<class A1>
class List
{
public:
	List() :head(nullptr), size(0) {}
	List(int _size)
	{
		if (_size < 0) throw logic_error("negative size");
		(*this).addNodes(_size);
	}
	List(List& lhs)
	{
		if (lhs.head == nullptr) throw logic_error("empty stack");
		(*this).addNodes(lhs.size);
		Node<A1>*tmpt = head;
		Node<A1>* tmpl = lhs.head;
		while (tmpl != nullptr)
		{
			(*tmpt).value = tmpl->value;
			tmpt = (*tmpt).next;
			tmpl = tmpl->next;
		}
	}
	~List()
	{
		if (!(*this).IsEmpty()) {
			Node<A1>*tmp = head;

			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
				delete head;
				head = tmp;
			}
		}
	}
	bool IsEmpty()
	{
		return(head == nullptr);
	}
	int GetSize()
	{
		return size;
	}
	void push_back(const A1& lhs)
	{
		if (!(*this).IsEmpty()) {
			Node<A1>*tmp = head;
			while (head->next != nullptr)
			{
				head = head->next;
			}
			head->next = new Node<A1>;
			(*head->next).value = lhs;
			head = tmp;
		}
		else
		{
			head = new Node<A1>;
			head->value = lhs;
			head->next = nullptr;
		}
	}
	void push_front(const A1& lhs)
	{
		Node<A1>* tmp = new Node<A1>;
		tmp->value = lhs;
		tmp->next = head;
		head = tmp;
	}
	A1& pop_front()
	{
		if (head == nullptr) throw logic_error("list is empty");
		Node<A1>* tmp = head->next;
		A1 tm = head->value;
		delete head;
		head = tmp;
		return tm;
	}
	A1& pop_back()
	{
		if ((*this).IsEmpty()) throw logic_error("List is empty");
		Node<A1>*tmp = head;

		while ((head->next)->next != nullptr)
		{
			head = head->next;
		}
		A1 tmp1 = head->next->value;
		delete head->next;
		head->next = nullptr;
		head = tmp;
		return tmp1;

	}
	template<class A1>
	friend ostream& operator<<(ostream& out, List<A1>& lhs)
	{
		Node<A1>*tmp = lhs.head;
		while (tmp->next != nullptr)
		{
			out << tmp->value << " ";
			tmp = tmp->next;
		}
		cout << tmp->value << "\n";
		return out;
	}
private:

	void addNodes(int _size)
	{
		size = _size;
		head = new Node<A1>;
		(*head).next = nullptr;
		Node<A1>* tmp = head;
		for (int i = 1; i < size - 1; i++)
		{
			(*tmp).next = new Node<A1>;
			tmp = (*tmp).next;
		}
		(*tmp).next = nullptr;
	}
	Node<A1>* head;
	int size;
};
