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
string s;
vector<int> deg;
ll b[12];
ll a[12];
ll Pow[12];
int N;
int main()
{
	cin >> s;
	N = s.size();
	Pow[0]=1ll;
	for(int i=0;i<11;i++)Pow[i+1]=Pow[i]*10ll;
	for(int i=0;i<s.size();i++)
	{
		deg.pb(s[i]-'0');
		a[i+1]=a[i]*10ll+(ll)(s[i]-'0');
	}
	reverse(all(s));
	b[0]=(s[0]-'0');
	for(int i=1;i<s.size();i++)
	{
		b[i]=b[i-1]+(s[i]-'0')*Pow[i];
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++)
	{
		if(deg[i]==0)ans+=a[i]*Pow[N-i-1];
		else if(deg[i]==1)
		{
			if(i==N-1)
			{
				ans += a[i]+1;
			}
			else
			{
				ans += a[i]*Pow[N-i-1];
				//cout << a[i] << ' ' << Pow[N-i-1] << endl;
				ans += b[N-i-2]+1;
			}
		}
		else ans += (a[i]+1)*Pow[N-i-1];
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
