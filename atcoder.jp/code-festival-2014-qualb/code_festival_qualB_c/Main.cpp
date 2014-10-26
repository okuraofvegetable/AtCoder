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
#define EQ(a,b) (abs((a)-(b))<eps)
int a[30],b[30],c[30];
void fail()
{
	cout << "NO" << endl;
	exit(0);
}
void success()
{
	cout << "YES" << endl;
	exit(0);
}
int main()
{
	string s1,s2,s3;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	int N = (int)s3.size()/2;
	for(int i=0;i<s1.size();i++)a[s1[i]-'A']++;
	for(int i=0;i<s2.size();i++)b[s2[i]-'A']++;
	for(int i=0;i<s3.size();i++)c[s3[i]-'A']++;
	int r=0,q=0;
	for(int i=0;i<30;i++)
	{
		int k = max(c[i]-b[i],0);
		if(a[i]<k)fail();
		int t = min(a[i],c[i]);
		r+=k;
		q+=t-k;
	}
	if(r<=N&&r+q>=N)success();
	else fail();
	return 0;
}
