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
#define MAX_DIGIT 15000
int n,k,m,r;
struct Double
{
	int a[MAX_DIGIT+1];
	Double()
	{
		memset(a,0,sizeof(a));
	}
	void set_integer(int p)//a=p
	{
		a[0]=p;
	}
	void add(Double b)//a+=b
	{
		int res=0;
		for(int i=MAX_DIGIT;i>=0;i--)
		{
			
			int k=(a[i]+b.a[i]+res)/10;
			a[i]=(a[i]+b.a[i]+res)%10;
			res=k;
		}
	}
	Double copy()
	{
		Double t;
		for(int i=0;i<=MAX_DIGIT;i++)
		{
			t.a[i]=a[i];
		}
		return t;
	}
	Double divide(int p)
	{
		Double b=copy();
		int res=0;
		for(int i=0;i<=MAX_DIGIT;i++)
		{
			int k=(b.a[i]+res)%p;
			b.a[i]=(b.a[i]+res)/p;
			res=k*10;
		}
		return b;
	}
	void print()//print stdout
	{
		cout << a[0];
		cout << '.';
		for(int i=0;i<r;i++)cout << a[i+1];
		cout << endl;
		return;
	}
};
Double reciprocal(int p)// return the reciprocal of p
{
	Double d;
	d.set_integer(1);
	return d.divide(p);
}
int main()
{
	// while(1)
	{
		cin >> n >> k >> m >> r;
		// if(n==0&&k==0&&m==0&&r==0)break;
		if(m==0)
		{
			reciprocal(n).print();
		}
		else
		{
			Double ans = reciprocal(n);
			for(int i=1;i<n;i++)
			{
				ans.add(reciprocal(n).divide(i));
			}
			ans.print();
		}
	}
	return 0;
}
