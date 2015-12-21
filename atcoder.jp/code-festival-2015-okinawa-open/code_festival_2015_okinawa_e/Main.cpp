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
bool beki(ll x){
	while(x%2ll==0ll)x/=2ll;
	return (x==1ll);
}
int main(){
	ll h,w,ret=1ll;
	scanf("%lld %lld",&h,&w);
	while(ret<h*w)ret*=2ll;
	if(!beki(w))printf("%lld\n",ret-1);
	else{
		if(beki(h)||beki(h+1))printf("%lld\n",ret-1);
		else printf("%lld\n",ret-w);
	}
	return 0;
}