#include <bits/stdc++.h>
using namespace std;
#define MM 200100
#define MN 15
int N,M;
int a[55],b[55];
int c[55],d[55];
int ans[55];
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<M;i++){
		cin >> c[i] >> d[i];
	}
	for(int i=0;i<N;i++){
		int val = 1145141919;
		for(int j=M-1;j>=0;j--){
			int ret = abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(ret<=val){
				val = ret;
				ans[i] = j;
			}
		}
	}
	for(int i=0;i<N;i++){
		cout << ans[i]+1 << endl;
	}
	return 0;
}