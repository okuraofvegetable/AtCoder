#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
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
int N,M;
int a[105];
void print(vector<int> &vec){
	int checksum = 0;
	for(int i=0;i<vec.size();i++){
		assert(vec[i]>=0);
		checksum+=vec[i];
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	assert(checksum==N);
}
int main(){
	cin >> N >> M;
	vector<int> odd,even;
	for(int i=0;i<M;i++){
		cin >> a[i];
		if(a[i]&1){
			odd.pb(a[i]);
		}else even.pb(a[i]);
	}
	vector<int> A,B;
	if(N&1){
		if(odd.size()>1){
			cout << "Impossible" << endl;
			return 0;
		}
		assert((int)odd.size()==1);
		if(even.size()>0){
			A.pb(odd[0]);
			for(int i=0;i<even.size();i++)A.pb(even[i]);
			B.pb(odd[0]+1);
			for(int i=0;i+1<even.size();i++)B.pb(even[i]);
			B.pb(even.back()-1);
		}else{
			A = odd;
			if(odd[0]>1)B.pb(odd[0]-1);
			B.pb(1);
		}
	}else{
		if(odd.size()>2){
			cout << "Impossible" << endl;
			return 0;
		}
		if(odd.size()==0){
			B.pb(1);
			for(int i=0;i<M-1;i++)B.pb(even[i]);
			B.pb(even[M-1]-1);
			A = even;
		}else{
			assert((int)odd.size()==2);
			if(odd[0]>1)B.pb(odd[0]-1);
			for(int i=0;i<even.size();i++){
				B.pb(even[i]);
			}
			B.pb(odd[1]+1);
			A.pb(odd[0]);
			for(int i=0;i<even.size();i++){
				A.pb(even[i]);
			}
			A.pb(odd[1]);
		}
	}
	print(A);
	cout << B.size() << endl;
	print(B);
	return 0;
}