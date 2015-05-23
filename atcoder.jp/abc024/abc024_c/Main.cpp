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
int N,D,K;
int L[10010],R[10010];
int S[110],T[110];
int ans[110];
int main()
{
	cin >> N >> D >> K;
	for(int i=0;i<D;i++)cin >> L[i] >> R[i];
	for(int i=0;i<K;i++)cin >> S[i] >> T[i];
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<D;j++)
		{
			if(L[j]<=S[i]&&S[i]<=R[j])
			{
				if(S[i]<T[i])
				{
					S[i]=R[j];
					if(L[j]<=T[i]&&T[i]<=R[j])
					{
						ans[i]=j+1;
						break;
					}
				}
				else
				{
					S[i]=L[j];
					if(L[j]<=T[i]&&T[i]<=R[j])
					{
						ans[i]=j+1;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<K;i++)cout << ans[i] << endl;
	return 0;
}
