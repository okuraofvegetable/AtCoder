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
class My_Debug
{
private:
	bool DEBUG_FLAG;	
public:
	My_Debug():DEBUG_FLAG(true){}
	void dump(vector<int>& v){
		int sz = v.size();
		printf("[");
		for(int i=0;i<sz;i++)printf("%d%c",v[i],(i==sz-1)?']':',');
		printf("\n");
	}
	void dump(int* v,int sz){
		printf("[");
		for(int i=0;i<sz;i++)printf("%d%c",v[i],(i==sz-1)?']':',');
		printf("\n");
	}
};
int main(){
	int N;
	cin >> N;
	int ans = 0;
	for(int i=0;i<N;i++){
		int l,r;
		cin >> l >> r;
		ans += r-l+1;
	}
	cout << ans << endl;
	return 0;
}