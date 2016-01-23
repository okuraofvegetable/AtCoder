#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)]
int N;
bool isniko(int x){
	vector<int> v;
	while(x){
		v.pb(x%10);
		x/=10;
	}
	if(sz(v)%2!=0)return false;
	for(int i=0;i<sz(v)/2;i++){
		if(v[i*2]!=5)return false;
		if(v[i*2+1]!=2)return false;
	}
	return true;
}
int main(){
	scanf("%d",&N);
	/*int ans = 0;
	for(int i=1;i*i<=N;i++){
		if(N%i==0){
			if(isniko(i))ans++;
			if(N/i!=i&&isniko(N/i))ans++;
		}
	}*/
	printf("%d\n",N/25);
	return 0;
}