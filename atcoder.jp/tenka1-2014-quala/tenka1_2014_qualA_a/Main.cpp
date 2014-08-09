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
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
int a[100100];
string s;
vector<string> vec;
string itos(int k)
{
	string s;
	while(k>0)
	{
		s+='0'+k%10;
		k/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	for(int i=1;i<=1000;i++)
	{
		vec.pb(itos(i));
	}
	SORT(vec);
	for(int i=0;i<vec.size();i++)
	{
		cout << vec[i] << endl;
	}
	return 0;
}
