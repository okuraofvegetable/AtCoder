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
int A[100100];
int imos[1200000];
int main()
{
	int N,T;
	cin >> N >> T;
	for(int i=0;i<N;i++)cin >> A[i];
	for(int i=0;i<N;i++)
	{
		imos[A[i]]++;
		imos[A[i]+T]--;
	}
	for(int i=0;i<1150000;i++)imos[i+1]+=imos[i];
	int ans = 0;
	for(int i=0;i<1150000;i++)if(imos[i]>0)ans++;
	cout << ans << endl;
	return 0;
}
