#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,K;
vector<int> v;
int used[105];
int main()
{
	cin >> N;
	int a,b;
	cin >> a >> b;
	cin >> K;
	v.pb(a);
	for(int i=0;i<K;i++)
	{
		int x;
		cin >> x;
		v.pb(x);
	}
	v.pb(b);
	memset(used,0,sizeof(used));
	for(int i=0;i<K+2;i++)
	{
		if(used[v[i]])
		{
			cout << "NO" << endl;
			return 0;
		}
		else used[v[i]]=1;
	}
	cout << "YES" << endl;
	return 0;
}
