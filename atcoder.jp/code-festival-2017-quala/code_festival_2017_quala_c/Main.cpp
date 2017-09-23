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
string A[100];
int H,W;
int al[30];
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> A[i];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int idx = A[i][j]-'a';
			al[idx]++;
		}
	}
	vector<int> vec;
	for(int i=0;i<30;i++){
		if(al[i]!=0)vec.pb(al[i]);
	}
	sort(all(vec));
	int a = H%2, b = W%2;
	if(a+b==0){
		for(int i=0;i<vec.size();i++){
			if(vec[i]%4!=0){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
		return 0;
	}else if(a+b==1){
		int X = (a==0)?H/2:W/2;
		int cnt = 0;
		for(int i=0;i<vec.size();i++){
			if(vec[i]%4!=0){
				if(vec[i]%4!=2){
					cout << "No" << endl;
					return 0;
				}else{
					cnt++;
				}
			}	
		}
		if(cnt<=X)cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}else{
		int cnt1=0,cnt2=0;
		int X = H/2+W/2;
		for(int i=0;i<vec.size();i++){
			if(vec[i]%4==1)cnt1++;
			else if(vec[i]%4==2)cnt2++;
			else if(vec[i]%4==3){
				cnt1++;
				cnt2++;
			}
		}
		if(cnt1!=1){
			cout << "No" << endl;
			return 0;
		}
		if(cnt2<=X){
			cout << "Yes" << endl;
		}else cout << "No" << endl;
		return 0;
	}
	return 0;
}