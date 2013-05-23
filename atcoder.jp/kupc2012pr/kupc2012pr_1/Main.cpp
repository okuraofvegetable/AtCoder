#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef unsigned long long ull;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
ull func(int m,int n)
{
	switch(m)
	{
		case 0:return(n+1);break;
		case 1:return(n+2);break;
		case 2:return(2*n+3);break;
		case 3:return((ull)(pow(2,n+3))-3);break;
	}
}
int main()
{
	ull ans=0;
	int m,n;
	cin >> m >> n;
	ans = func(m,n);
	cout << ans << endl;
	return 0;
}
