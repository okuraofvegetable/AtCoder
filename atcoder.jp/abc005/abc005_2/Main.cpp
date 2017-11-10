#include <iostream>
using namespace std;
#define INF 1000000000
int main()
{
	int n;
	cin >> n;
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		ans=min(ans,k);
	}
	cout << ans << endl;
	return 0;
}