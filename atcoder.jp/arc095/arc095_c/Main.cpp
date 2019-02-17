#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
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
string s[13],t[13];
int H,W;
int used[13];
vector<int> p;
bool ans = false;
int b;
bool check(){
	vector<string> vec;
	for(int i=0;i<H;i++){
		string rt = t[i];
		reverse(all(rt));
		bool found = false;
		for(int j=0;j<vec.size();j++){
			if(vec[j]==rt){
				vec.erase(vec.begin()+j);
				found = true;
				break;
			}
		}
		if(!found)vec.pb(t[i]);
	}
	if(vec.size()==0)return true;
	else if(vec.size()==1){
		string u = vec[0];
		reverse(all(u));
		if(vec[0]==u)return true;
		else return false;
	}
	return false;
}
void dfs(int n){
	if(n==W){
		for(int i=0;i<H;i++){
			for(int j=0;j<W/2;j++){
				t[i][j]=s[i][p[j*2]];
				t[i][W-1-j]=s[i][p[j*2+1]];
			}
		}
		ans |= check();
		return;
	}
	if(n+1==W){
		/*for(int i=0;i<p.size();i++)cout << p[i] << ' ';
		cout << endl;*/
		for(int i=0;i<H;i++){
			for(int j=0;j<W/2;j++){
				t[i][j]=s[i][p[j*2]];
				t[i][W-1-j]=s[i][p[j*2+1]];
			}
		}
		for(int i=0;i<H;i++)t[i][W/2]=s[i][b];
		ans |= check();
		return;
	}
	int f = -1;
	for(int i=0;i<W;i++){
		if(!used[i]){
			f=i;
			break;
		}
	}
	p.pb(f);
	used[f]=true;
	for(int i=f+1;i<W;i++){
		if(used[i])continue;
		p.pb(i);
		used[i]=true;
		dfs(n+2);
		p.pop_back();
		used[i]=false;
	}
	p.pop_back();
	used[f]=false;
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> s[i];
		t[i]=s[i];
	}
	if(W%2==0)dfs(0);
	else{
		for(int i=0;i<W;i++){
			b = i;
			used[i]=true;
			dfs(0);
			used[i]=false;
		}
	}
	if(ans)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}