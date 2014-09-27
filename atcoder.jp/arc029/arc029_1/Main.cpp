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
int main()
{
	int n;
	cin >> n;
	vector<int> niku;
	for(int i=0;i<n;i++)
	{
		int k;
		cin >> k;
		niku.pb(k);
	}
	sort(all(niku),greater<int>());
	int cnt1=0,cnt2=0;
	for(int i=0;i<4;i++)
	{
		if(cnt1<cnt2)cnt1+=niku[i];
		else cnt2+=niku[i];
	}
	cout << max(cnt1,cnt2) << endl;
	return 0;
}
