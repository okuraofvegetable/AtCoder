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
int N,T;
int A[100100],B[100100];
int sa[100100];
int main()
{
	scanf("%d %d",&N,&T);
	for(int i=0;i<N;i++)scanf("%d %d",&A[i],&B[i]);
	int time = 0;
	for(int i=0;i<N;i++)
	{
		time += A[i];
		sa[i] = A[i]-B[i];
	}
	sort(sa,sa+N,greater<int>());
	int ans = 0;
	if(time<=T)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<N;i++)
	{
		ans = i+1;
		time-=sa[i];
		if(time<=T)break;
		if(i==N-1)ans = -1;
	}
	printf("%d\n",ans);
	return 0;
}
