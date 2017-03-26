#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MM 200100
#define MN 15
int dig(ll x){
	int res = 0;
	while(x){
		x/=10;
		res++;
	}
	return res;
}
int main(){
	ll x;
	cin >> x;
	int ans = 114;
	for(ll i=1;i*i<=x;i++){
		if(x%i==0ll){
			ans =min(ans,max(dig(i),dig(x/i)));
		}
	}
	cout << ans << endl;
	return 0;
}