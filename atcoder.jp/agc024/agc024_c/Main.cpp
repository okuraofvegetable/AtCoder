#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll A[200100];
ll B[200100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		if(A[i]>i){
			cout << -1 << endl;
			return 0;
		}
		B[i]=i-A[i];
	}
	for(int i=1;i<N;i++){
		if(A[i]-A[i-1]>1){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i=0;i<N-1;i++){
		if(B[i+1]-B[i]<0){
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0ll;
	for(int i=N-1;i>=0;i--){
		if(i+1<N&&B[i+1]==B[i])continue;
		ans += A[i];
	}
	cout << ans << endl;
	return 0;
}