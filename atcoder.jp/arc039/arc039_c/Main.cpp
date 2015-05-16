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
const int SIZE = 200100;
struct UnionFind
{
	int par[SIZE];
	UnionFind()
	{
		for(int i=0;i<SIZE;i++)par[i] = i;
	}
	int find(int x)
	{
		if(par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y)
	{
		x = find(x);
		y = find(y);
		par[y]=x;
	}
	bool same(int x,int y)
	{
		return find(x) == find(y);
	}
}L,R,U,D;
int K;
string s;
map<P,int> m;
vector<P> vec;
int main()
{
	scanf("%d",&K);
	cin >> s;
	int id = 0;
	int now = 0;
	m[P(0,0)] = id++;
	vec.pb(P(0,0));
	for(int i=0;i<K;i++)
	{
		P next_place;
		if(s[i]=='L')
		{
			int next = L.find(now);
			next_place = vec[next];
			next_place.fi--;
		}
		else if(s[i]=='R')
		{
			int next = R.find(now);
			next_place = vec[next];
			next_place.fi++;
		}
		else if(s[i]=='U')
		{
			int next = U.find(now);
			next_place = vec[next];
			next_place.sec++;
		}
		else
		{
			int next = D.find(now);
			next_place = vec[next];
			next_place.sec--;
		}
		m[next_place]=id++;
		vec.pb(next_place);
		now = id-1;
		map<P,int>::iterator it;
		int x = next_place.fi , y = next_place.sec;
		//out << x << ' ' << y << endl;
		it = m.find(P(x+1,y));
		if(it!=m.end())L.unite(now,it->sec);
		it = m.find(P(x-1,y));
		if(it!=m.end())L.unite(it->sec,now);
		it = m.find(P(x-1,y));
		if(it!=m.end())R.unite(now,it->sec);
		it = m.find(P(x+1,y));
		if(it!=m.end())R.unite(it->sec,now);
		it = m.find(P(x,y-1));
		if(it!=m.end())U.unite(now,it->sec);
		it = m.find(P(x,y+1));
		if(it!=m.end())U.unite(it->sec,now);
		it = m.find(P(x,y+1));
		if(it!=m.end())D.unite(now,it->sec);
		it = m.find(P(x,y-1));
		if(it!=m.end())D.unite(it->sec,now);	
	}
	cout << vec[now].fi << ' ' << vec[now].sec << endl;
	return 0;
}
