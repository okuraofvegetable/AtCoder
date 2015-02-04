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
#define rep(i,x) for(int i=0;i<x;i++)
#define EQ(a,b) (abs((a)-(b))<eps)
int l[105],r[105];
int N,len;
string rev(string s,int x)
{
	string L,M,R;
	L = s.substr(0,l[x]-1);
	M = s.substr(l[x]-1,r[x]-l[x]+1);
	R = s.substr(r[x],len-r[x]);
	reverse(M.begin(),M.end());
	string res = L+M+R;
	return res;
}
int main()
{
	string s;
	cin >> s;
	len = (int)s.size();
	cin >> N;
	rep(i,N)cin >> l[i] >> r[i];
	rep(i,N)s = rev(s,i);
	cout << s << endl;
	return 0;
}
