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
int main()
{
	int n;
	cin >> n;
	if(n==1||n==2||n==3)
	{
		cout << -1 << endl;
		return 0;
	}
	int p=n/2+1;
	cout << ".#";
	for(int i=0;i<n-2;i++)cout << '.';
	cout << endl;
	for(int i=0;i<(n/2-1);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i||j==i+2)cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
	for(int i=0;i<n;i++)
	{
		if(i==(n/2-1))cout << '#';
		else if((i==(n/2-1)+1)&&(n%2==1))cout << '#';
		else cout << '.';
	}
	cout << endl;
	for(int i=0;i<n-(n/2+1);i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << '.';
		}
		cout << endl;
	}
	/*
	int p,q;
	p=n/4;
	q=n%4;
	if(q>0)p--;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>=3*p-1)
			{
				cout << '.';
			}
			else
			{
				if(j%3==0||j%3==1)cout << '#';
				else cout << '.';
			}
		}
		cout << endl;
	}
	if(q==0)
	{
		for(int i=0;i<n-2;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << '.';
			}
			cout << endl;
		}
	}
	if(q==1)
	{
		if(n!=5){for(int i=0;i<n;i++)cout << '.';
		cout << endl;}
		cout << ".#";
		for(int i=0;i<n-2;i++)cout << '.';
		cout << endl;
		cout << "#.#";
		for(int i=0;i<n-3;i++)cout << '.';
		cout << endl;
		cout << ".##";
		for(int i=0;i<n-3;i++)cout << '.';
		cout << endl;
		for(int i=0;i<n-6;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << '.';
			}
			cout << endl;
		}
	}
	if(q==2)
	{
		for(int i=0;i<n;i++)cout << '.';
		cout << endl;
		cout << "#.##";
		for(int i=0;i<n-4;i++)cout << '.';
		cout << endl;
		cout << "##.#";
		for(int i=0;i<n-4;i++)cout << '.';
		cout << endl;
		for(int i=0;i<n-5;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << '.';
			}
			cout << endl;
		}
	}
	if(q==3)
	{
		for(int i=0;i<n;i++)cout << '.';
		cout << endl;
		cout << ".#";
		for(int i=0;i<n-2;i++)cout << '.';
		cout << endl;
		cout << "#.#";
		for(int i=0;i<n-3;i++)cout << '.';
		cout << endl;
		cout << ".#.#";
		for(int i=0;i<n-4;i++)cout << '.';
		cout << endl;
		cout << "..##";
		for(int i=0;i<n-4;i++)cout << '.';
		cout << endl;
		for(int i=0;i<n-7;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << '.';
			}
			cout << endl;
		}
	}*/
	return 0;
}
