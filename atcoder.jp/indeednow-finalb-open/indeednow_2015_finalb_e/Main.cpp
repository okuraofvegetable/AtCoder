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
#define MAX_N 100100
vector<int> vs;
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
}bit;
set<int> s;
int n;
int a[100100];
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(s.find(a[i])==s.end())
		{
			s.insert(a[i]);
			vs.pb(a[i]);
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	sort(all(vs));
	vs.erase(unique(all(vs)),vs.end());
	for(int i=0;i<n;i++)a[i]=lower_bound(all(vs),a[i])-vs.begin()+1;
	ll ans = 0ll;
	for(int i=n-1;i>=0;i--)
	{
		ans += bit.sum(a[i]);
		bit.add(a[i],vs[a[i]-1]);
	}
	cout << ans << endl;
	return 0;
}
