#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,A[2010];
bitset<4000000> bs(1);
int main(){
	int sum = 0;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
		sum += A[i];
	}
	sum = (sum+1)/2;
	for(int i=0;i<N;i++){
		bs |= bs<<A[i];
	}
	for(int i=sum;;i++){
		if(bs[i]){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}