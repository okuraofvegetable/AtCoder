#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
ll A[100100];
int l[100100];
int r[100100];
int sgn(int x){
	if(x>0)return 0;
	else return 1;
}
int main(){
	cin >> N;
	ll sum = 0ll;
	ll mi = INF;
	bool zero = false;
	for(int i=0;i<N;i++){
		cin >> A[i];
		if(A[i]==0)zero = true;
		sum += abs(A[i]);
		mi = min(mi,abs(A[i]));
	}
	if(zero){
		cout << sum << endl;
		return 0;
	}
	int pre = 0;
	for(int i=0;i<N-1;i++){
		if((pre+sgn(A[i]))%2==1){
			l[i]=1;
		}else{
			l[i]=0;
		}
		pre = l[i];
	}
	pre = 0;
	for(int i=N-1;i>0;i--){
		if((pre+sgn(A[i]))%2==1){
			r[i]=1;
		}else{
			r[i]=0;
		}
		pre = r[i];
	}
	/*for(int i=0;i<N;i++){
		cout << l[i] << ' ';
	}
	cout << endl;
	for(int i=0;i<N;i++){
		cout << r[i] << ' ';
	}
	cout << endl;*/
	bool flag = false;
	for(int i=1;i<N-1;i++){
		if((sgn(A[i])+l[i-1]+r[i+1])%2==0){
			flag = true;
			break;
		}
	}
	if((sgn(A[0])+r[1])%2==0)flag = true;
	if((sgn(A[N-1])+l[N-2])%2==0)flag = true;
	if(flag)cout << sum << endl;
	else cout << sum - mi*2 << endl;
	return 0;
}