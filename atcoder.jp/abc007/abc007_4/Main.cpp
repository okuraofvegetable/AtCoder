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
ll dp[20][2][2];
ll a,b;
ll ca,cb;
int cnt;
int s[20][2];
ll culc(int digit,bool used,bool flag,int num)
{
	if(digit==-1)return used?1ll:0ll;
	ll &ret=dp[digit][used][flag];
	if(ret!=-1)return ret;
	ret=0;
	for(int i=0;i<=9;i++)
	{
		if(!flag||i<=s[digit][num])ret+=culc(digit-1,(used||i==4||i==9),(flag&&i==s[digit][num]),num);
	}
	return ret;
}
int main()
{
	cin >> a >> b;
	a--;
	memset(dp,-1,sizeof(dp));
	cnt=0;
	while(a>0)
	{
		s[cnt++][0]=a%10;
		a/=10;
	}
	ca=culc(cnt,false,true,0);
	memset(dp,-1,sizeof(dp));
	cnt=0;
	while(b>0)
	{
		s[cnt++][1]=b%10;
		b/=10;
	}
	cb=culc(cnt,false,true,1);
	//cout << cb << ' ' << ca << endl;
	cout << cb-ca << endl;
	return 0;
}
