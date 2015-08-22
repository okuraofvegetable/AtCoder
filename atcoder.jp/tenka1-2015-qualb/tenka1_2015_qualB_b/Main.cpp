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
int main()
{
	string s;
	cin >> s;
	if(s=="{}")
	{
		cout << "dict" << endl;
		return 0;
	}
	int nest = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='{')nest++;
		if(s[i]=='}')nest--;
		if(nest==1&&s[i]==':')
		{
			cout << "dict" << endl;
			return 0;
		}
	}
	cout << "set" << endl;
	return 0;
}
