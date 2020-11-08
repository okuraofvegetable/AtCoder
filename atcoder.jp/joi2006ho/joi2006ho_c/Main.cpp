#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define EQ(a,b) (abs((a)-(b))<EPS)
int n;
int buf[100];
void dfs(int c,int p)
{
	int i;
	if(c==0)
	{
		for(i=0;i<p-1;i++)
		{
			cout << buf[i] << ' ';
		}
		cout << buf[i] << endl;
		return;
	}
	for(i=min(c,((p==0) ? c : buf[p-1]));i>0;i--)
	{
		buf[p]=i;
		dfs(c-i,p+1);
	}
	return;
}
int main()
{
	//while(1)
	{
		cin >> n;
		//if(n==0)break;
		dfs(n,0);
	}
	return 0;
}
