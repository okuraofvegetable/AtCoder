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
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int a[110];
int main()
{
	int n,c;
	cin >> n >> c;
	for(int i=0;i<n;i++)cin >> a[i];
	int ans=INF;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			int res=0;
			if(i==j)continue;
			for(int k=0;k<n;k++)
			{
				if(k%2==1&&a[k]!=j)res++;
				if(k%2==0&&a[k]!=i)res++;
			}
			ans=min(ans,res);
		}
	}
	cout << ans*c << endl;
	return 0;
}
