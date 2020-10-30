
#include <iomanip>
#include "List.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	/*List<int>A;
	for (int i = 0; i < 10; i++)
	{
		A.push_back(i);

	}
	A.pop_front();
	A.pop_back();
	cout << A.pop_back()<<" "<<A.pop_front();*/
	List<int>q;
	int m = 2;
	q.push_back(0);
	q.push_back(1);
	cout << q.pop_back();
	List<int> v(5);
	
	v.push_front(0);
	v.push_front(1);
	v.push_front(2);
	v.pop_front();
	v.pop_front();
	cout << v.pop_front();
	return 0;
}
	


