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
int imos[3010][3010];
bool used[3010];
int ans[3010];
int N,M;
int main()
{
	scanf("%d %d",&N,&M);
	rep(i,M)
	{
		int A,B,C,D;
		scanf("%d %d %d %d",&A,&B,&C,&D);
		A--;C--;
		imos[A][C]++;
		imos[A][D]--;
		imos[B][C]--;
		imos[B][D]++;
	}
	rep(i,N)rep(j,N)imos[i][j+1]+=imos[i][j];
	rep(j,N)rep(i,N)imos[i+1][j]+=imos[i][j];
	vector<P> v;
	rep(i,N)
	{
		int cnt = 0;
		rep(j,N)if(imos[i][j]==0)cnt++;
		v.pb(P(cnt,i));
	}
	sort(all(v));
	memset(used,false,sizeof(used));
	//rep(i,N)cout << v[i].fi << ' ' << v[i].sec << endl;
	rep(i,N)
	{
		int r = v[i].sec;
		rep(j,N)if(!used[j]&&imos[r][j]==0)
		{
			ans[r]=j;
			used[j]=true;
			break;
		}
	}
	rep(i,N)printf("%d\n",ans[i]+1);
	return 0;
}
