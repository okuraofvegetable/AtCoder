#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll A[200100];
ll L ,R;
int main(){
	cin >> N;
	L = 0,R = 0;
	for(int i=0;i<N;i++){
		cin >> A[i];
		A[i]-=(i+1);
	}
	sort(A,A+N);
	for(int i=0;i<N;i++){
		if(i>0)R += A[i];
	}
	ll ans = 1000000000000000ll;
	for(int i=0;i<N;i++){
		//cout << L << ' ' << R << endl;
		ans = min(ans,R-A[i]*(ll)(N-i-1)+A[i]*i-L);
		L += A[i];
		R -= A[i+1];
	}
	cout << ans << endl;
	return 0;
}