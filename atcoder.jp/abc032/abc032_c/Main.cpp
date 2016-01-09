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
int N;
ll K;
ll a[100100];
int main(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i]);
		if(a[i]==0){
			printf("%d\n",N);
			return 0;
		}
	}
	int ans = 0;
	int s = 0,t = 0;
	ll pro = 1ll;
	while(s<N){
		while(t<N&&pro*a[t]<=K){
			pro *= a[t++];
		}
		//cout << s << ' ' << t << endl;
		ans = max(ans,t-s);
		if(s<t)pro /= a[s];
		s++;
		t = max(s,t);
	}
	cout << ans << endl;
	return 0;
}
