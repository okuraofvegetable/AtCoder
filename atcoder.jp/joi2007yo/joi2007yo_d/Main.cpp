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
vector<int> card;
vector<int> tmp;
vector<int> tm2;
int n;
void cut(int k)
{
	for(int i=0;i<k;i++)
	{
		tmp.pb(card[i]);
	}
	for(int i=k;i<card.size();i++)
	{
		tm2.pb(card[i]);
	}
	for(int i=0;i<tmp.size();i++)
	{
		tm2.pb(tmp[i]);
	}
	card.clear();
	card=tm2;
	tmp.clear();
	tm2.clear();
	return ;
}
void riffle()
{
	tmp=card;
	for(int i=0;i<n;i++)
	{
		card[2*i]=tmp[i];
	}
	for(int i=n;i<2*n;i++)
	{
		card[(i-n)*2+1]=tmp[i];
	}
	tmp.clear();
	return ;
}
int main()
{
	cin >> n;
	for(int i=1;i<=2*n;i++)
	{
		card.pb(i);
	}
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int k;
		cin >> k;
		if(k==0)
		{
			riffle();
		}
		else
		{
			cut(k);
		}
	}
	for(int i=0;i<sz(card);i++)
	{
		cout << card[i] << endl;
	}
	return 0;
}
