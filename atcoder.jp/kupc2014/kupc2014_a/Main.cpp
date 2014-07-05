#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[8];
	for(int i=0;i<6;i++)cin >> a[i];
	sort(a,a+3);sort(a+3,a+6);
	int ans=0;
	for(int i=0;i<3;i++)ans+=abs(a[i+3]-a[i]);
	cout << ans << endl;
	return 0;
}
