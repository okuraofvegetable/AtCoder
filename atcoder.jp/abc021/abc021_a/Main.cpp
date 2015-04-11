#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << __builtin_popcount(n) << endl;
	for(int i=0;i<4;i++)
	{
		if((n>>i)&1)cout << (1<<i) << endl;
	}
	return 0;
}
