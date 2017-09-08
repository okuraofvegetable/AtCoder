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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
void debug(int* v,int sz){
	printf("[");
	for(int i=0;i<sz;i++)printf("%d%c",v[i],(i==sz-1)?']':',');
	printf("\n");
}
string A,B;
int N;
int sumA,sumB;
vector<int> vec;
deque<int> deq;
int one;
int L[2010],R[2010];
bool comp(int a,int b){
	return L[a]>L[b];
}
int main(){
	cin >> A;
	cin >> B;
	N = A.size();
	for(int i=0;i<N;i++){
		if(A[i]=='1'){
			sumA++;
			vec.pb(1);
		}else vec.pb(0);
		if(B[i]=='1'){
			sumB++,one=i;
			deq.pb(1);
		}else deq.pb(0);
	}
	if(sumB==0){
		if(sumA==0)printf("0\n");
		else printf("-1\n");
		return 0;
	}
	int prev = -1;
	for(int i=one;i<one+N;i++){
		int idx = i;
		if(idx>=N)idx-=N;
		if(B[idx]=='1')L[idx]=0;
		else L[idx]=prev+1;
		prev = L[idx];
	}
	for(int i=one;i>one-N;i--){
		int idx = i;
		if(idx<0)idx+=N;
		if(B[idx]=='1')R[idx]=0;
		else R[idx]=prev+1;
		prev = R[idx];
	}
	//debug(L,N);
	//debug(R,N);
	int ans = INF;
	for(int i=0;i<N;i++){
		vector<int> d;
		for(int j=0;j<N;j++){
			if(vec[j]!=deq[j])d.pb(j);
		}
		sort(all(d),comp);
		int Lmax=0,Rmax=0;
		int ds = d.size();
		for(int j=0;j<=ds;j++){
			int ret,diff;
			if(j<ds)Lmax=L[d[j]];
			else Lmax=0;
			if(j>0)Rmax=max(Rmax,R[d[j-1]]);
			{
				ret = ds+2*Lmax+Rmax;
				diff = abs(Rmax+i);
				diff%=N;
				chmin(diff,N-diff);
				ret += diff;
				chmin(ans,ret);	
			}
			{
				ret = ds+2*Rmax+Lmax;
				diff = abs(-Lmax+i);
				diff%=N;
				chmin(diff,N-diff);
				ret += diff;
				chmin(ans,ret);
			}
		}
		deq.push_front(deq.back()); //shift right
		deq.pop_back();
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}