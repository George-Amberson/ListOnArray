
#include <iomanip>
#include "ListOnArray.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	ListOnArray<int>A(10);
	for (int i = 0; i < 10; i++)
	{
		A.push_front(i);
		//cout << A.pop_back()
	}
	cout << A.pop_front();
	return 0;
}
	


