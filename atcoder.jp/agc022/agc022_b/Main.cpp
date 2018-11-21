#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
vector<int> v;
int main(){
	cin >> N;
	int A,B,C;
	if(N==3){
		printf("2 5 63\n");
		return 0;
	}
	if(N<=5002){
		C = 1;
		B = N-3;
		if(B%2==0)B--;
		A = N-B-C;
	}else if(N<=7000){
		B = 4999;
		C = N-2-B;
		if(C%2==0)C--;
		A = N-B-C;
	}else{
		B = 4999;
		C = 1999;
		A = N-B-C;
	}
	int sum = 0;
	for(int i=0;i<B;i++){
		v.pb(3*(2*i+1));
		sum += 3*(2*i+1);
	}
	for(int i=0;i<C;i++){
		if(i%2==0){
			v.pb(15*i+5);
			sum += 15*i+5;
		}else{
			v.pb(15*i+10);
			sum += 15*i+10;
		}
	}
	for(int i=0;i<A;i++){
		v.pb(2*(i+1));
		sum += 2*(i+1);
	}
	sum %= 30;
	v.back() += (30-sum);
	for(int i=0;i<v.size();i++){
		printf("%d ",v[i]);
	}
	printf("\n");
	return 0;
}