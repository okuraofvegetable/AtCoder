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
int N,Q;
int k[100100];
vector<int> s;
int main()
{
	cin >> N;
	int cnt = 0;
	rep(i,N)
	{
		int a;
		cin >> a;
		if(a>0)
		{
			s.pb(a);
			cnt++;
		}
	}
	cin >> Q;
	rep(i,Q)cin >> k[i];
	sort(all(s));
	N=cnt;
	rep(i,Q)
	{
		int l = -1,r = INF;
		while(r-l>1)
		{
			int mid = (l+r)/2;
			int t = lower_bound(all(s),mid)-s.begin();
			if(N-t<=k[i])r=mid;
			else l = mid;
		}
		printf("%d\n",r);
	}
	return 0;
}
