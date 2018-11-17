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
string s;
int N;
bool used[26];
int C[200100];
int nx[200100][26];
int nxt[26];
int cnt = 0;
int cur = 0;
int Next(int pos,int c){
	if(pos==-1)return nxt[c];
	else return nx[pos][c];
}
int main(){
	cin >> s;
	N = (int)s.size();
	for(int i=N-1;i>=0;i--){
		if(!used[s[i]-'a']){
			used[s[i]-'a']=true;
			cnt++;
		}
		if(cnt==26){
			cur++;
			cnt = 0;
			for(int i=0;i<26;i++)used[i]=false;
		}
		C[i]=cur;
	}
	//for(int i=0;i<N;i++)printf("%d",C[i]);
	memset(nxt,-1,sizeof(nxt));
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<26;j++){
			nx[i][j]=nxt[j];
		}
		nxt[s[i]-'a']=i;
	}
	int ans_len = cur+1;
	int pos = -1;
	for(int i=0;i<ans_len;i++){
		for(int j=0;j<26;j++){
			int p = Next(pos,j);
			if(p!=-1&&C[p+1]>=ans_len-i-1)continue;
			printf("%c",'a'+j);
			pos = p;
			break;
		}
	}
	printf("\n");
	return 0;
}