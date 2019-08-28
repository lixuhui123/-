 
#include <iostream>
using namespace std;
int main()
{
	 
	int arr[] = { 4,5,6,6,82,8 };
	
	for (auto i : arr)

		cout << i << endl;
	int array[] = { 1, 2, 3, 4, 5 };
	//for (auto& e : array)
	//	e *= 2;
	for (auto i : arr)
		cout << i << " ";
	int x = 0;
	auto &f = &x;
	system("pause");
	return 0;
}