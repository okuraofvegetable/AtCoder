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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
ll Z;
ll a[100100];
ll gcd(ll a,ll b){
	return b==0ll?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	scanf("%d %lld",&N,&Z);
	for(int i=0;i<N;i++)scanf("%lld",&a[i]);
	ll ans = 1ll;
	for(int i=0;i<N;i++)ans = lcm(ans,gcd(Z,a[i]));
	cout << ans << endl;
	return 0;
}