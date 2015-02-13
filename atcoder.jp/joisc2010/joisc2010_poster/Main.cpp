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
string rec(int N,int K)
{
	string ret;
	if(!N)return "J";
	if(K>=(1<<(N-1)))
	{
		rep(i,1<<(N-1))ret+='I';
		return ret+rec(N-1,K-(1<<(N-1)));
	}
	else
	{
		rep(i,(1<<(N-1)))ret+='J';
		rep(i,(1<<(N-1)))ret+='O';
		return ret;
	}
}
int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	cout << rec(N,K-1) << endl;
	return 0;
}
