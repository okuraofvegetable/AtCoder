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
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
int A[20],B[55],C[55];
int I[55][20];
int main()
{
	scanf("%d %d",&N,&M);
	rep(i,N)scanf("%d",&A[i]);
	rep(i,M)
	{
		scanf("%d %d",&B[i],&C[i]);
		rep(j,C[i])
		{
			scanf("%d",&I[i][j]);
			I[i][j]--;
		}
	}
	int ans = 0;
	rep(i,1<<N)
	{
		if(__builtin_popcount(i)!=9)continue;
		int base=0;
		vector<int> vs;
		rep(j,N)if((i>>j)&1)
		{
			base+=A[j];
			vs.pb(j);
		}
		//cout << base << ' ';
		rep(j,M)
		{
			int cnt = 0;
			rep(k,C[j])if(binary_search(all(vs),I[j][k]))cnt++;
			if(cnt>=3)base+=B[j];
		}
		ans = max(ans,base);
		//cout << base << endl;
	}
	printf("%d\n",ans);
	return 0;
}
