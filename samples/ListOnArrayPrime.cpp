
#include <iomanip>
#include "ListOnArray.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	ListOnArray<int>A(10);
	for (int i = 0; i < 5; i++)
	{
		A.push_back(i * 10);
	}
	for (auto i = A.begin(); i != A.end(); i++)
	{
		cout << *(i) << " ";
	}
	cout << endl;
	A.reverse();
	for (auto i = A.begin(); i != A.end(); i++)
	{
		cout << *(i) << " ";
	}
	return 0;
}
	


