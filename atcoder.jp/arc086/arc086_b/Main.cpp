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
int n;
int a[55];
int mx_id,mi_id;
int mx=-INF,mi=INF;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(mx<a[i]){
			mx = a[i];
			mx_id = i;
		}
		if(mi>a[i]){
			mi = a[i];
			mi_id = i;
		}
	}
	if(mx+mi>=0){
		cout << 2*n-1 << endl;
		for(int i=0;i<n;i++)printf("%d %d\n",mx_id+1,i+1);
		for(int i=0;i<n-1;i++)printf("%d %d\n",i+1,i+2);
	}else{
		cout << 2*n-1 << endl;
		for(int i=0;i<n;i++)printf("%d %d\n",mi_id+1,i+1);
		for(int i=n-1;i>0;i--)printf("%d %d\n",i+1,i);
	}
	return 0;
}