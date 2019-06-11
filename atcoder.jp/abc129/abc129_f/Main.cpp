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

typedef vector<ll> vec;
typedef vector<vec> mat;

ll MOD;

void print_mat(mat A){
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[i].size();j++){
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}
}

mat mul(mat &A,mat &B){
	assert(A[0].size()==B.size());
	mat C(A.size(),vec(B[0].size()));
	for(int i=0;i<A.size();i++){
		for(int k=0;k<B.size();k++){
			for(int j=0;j<B[0].size();j++){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
			}
		}
	}
	return C;
}

mat pow(mat A, ll n){
	assert(A.size()==A[0].size());
	mat B(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++){
		B[i][i]=1ll;
	}
	while(n>0){
		if(n&1)B = mul(B,A);
		A = mul(A,A);
		n >>= 1;
	}
	return B;
}

ll pow(ll a,ll n){
	ll res = 1ll;
	a %= MOD;
	while(n>0){
		if(n&1)res = (res*a)%MOD;
		a = (a*a)%MOD;
		n >>= 1;
	}
	return res;
}

// 1 1 2 3 5 8 ...
ll fib(ll x){
	mat A(2,vec(2));
	A[0][0]=1;A[0][1]=1;A[1][0]=1;A[1][1]=0;
	A = pow(A,x);
	return A[1][0];
}


ll L,A,B,M;
ll k[25];
ll rui[25];
int main(){
	cin >> L >> A >> B >> M;
	MOD = M;
	rui[0]=1ll;
	for(int i=1;i<=18;i++)rui[i]=rui[i-1]*10ll;
	for(int i=1;i<=18;i++){
		ll l = -1, r = L;
		while(r-l>1ll){
			ll mid = (l+r)/2;
			if(A+mid*B<rui[i-1])l=mid;
			else r=mid;
		}
		k[i]=r;
		//cout << i << ' ' << r << endl;
	}
	k[19]=L;
	k[20]=L;
	/*for(int i=18;i>=1;i--){
		krui[i] = ((i*((k[i+1]-k[i])%M))%M);
	}
	for(int i=1;i<=18;i++){
		//cout << i << ' ' << krui[i] << endl;
	} */

	ll ans = 0ll;
	ll ret = 1ll;
	for(int i=18;i>=1;i--){
		//if(k[i]==k[i+1])continue;
		mat S(3,vec(3));
		S[0][0]=rui[i]%MOD;S[0][1]=1;S[0][2]=0;
		S[1][0]=0;S[1][1]=1;S[1][2]=B%MOD;
		S[2][0]=0;S[2][1]=0;S[2][2]=1;
		mat v(3,vec(1));
		v[0][0]=0ll;
		v[1][0]=(A+B*k[i])%MOD;
		v[2][0]=1ll;
		ll n = k[i+1]-k[i];
		mat ruiS = pow(S,n);
		mat res = mul(ruiS,v);
		for(int j=0;j<i+1;j++){
			//i+1
			ret = (ret*pow(10ll,k[i+2]-k[i+1]))%MOD;
		}
		//cout << res[0][0] << ' ' << ret << endl;
		ans = (ans+((res[0][0]*ret)%MOD))%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}