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
int live=5;
int sz;
ll ans=0ll;
int combo=0;
short damage[1000100];
bool charge[1000100];
short ret[1000100];
int comb[1000100];
ll culc_damage(ll x,int t)
{
	return x+(x/10ll)*(((ll)(comb[t]/10)));
}
int main()
{
	string action;
	cin >> action;
	sz=action.size();
	for(int i=0;i<sz+10;i++)
	{
		//cout << i << ':' << ans << endl;
		if(i>0)comb[i]=comb[i-1];
		if(damage[i])
		{
			int p=(damage[i]==10?2:4);
			comb[i]=++combo;
			ans+=culc_damage((ll)damage[i],i-p);
		}
		if(ret[i])live+=ret[i];
		if(i>=sz)continue;
		if(action[i]=='-')continue;
		if(action[i]=='N')
		{
			if(charge[i]||live==0)continue;
			live--;
			damage[i+2]=10;
			ret[i+7]+=1;
		}
		if(action[i]=='C')
		{
			if(charge[i]||live<3)continue;
			live-=3;
			damage[i+4]=50;
			charge[i+1]=true;
			charge[i+2]=true;
			ret[i+9]+=3;
		}
	}
	cout << ans << endl;
	return 0;
}
