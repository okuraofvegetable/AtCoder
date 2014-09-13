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
int a[1001000],b[1001000];
vector<int> vec;
int imos[1001000];
int main()
{
	int n;
	scanf("%d",&n);
	vec.pb(0);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		vec.pb(a[i]);
		vec.pb(b[i]);
	}
	SORT(vec);
	vec.erase(unique(all(vec)),vec.end());
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(all(vec),a[i])-vec.begin();
		b[i]=lower_bound(all(vec),b[i])-vec.begin();
		imos[a[i]]++;
		imos[b[i]+1]--;
	}
	int ans=imos[0];
	for(int i=1;i<100001;i++)
	{
		imos[i]+=imos[i-1];
		ans=max(ans,imos[i]);
	}
	printf("%d\n",ans);
	return 0;
}
