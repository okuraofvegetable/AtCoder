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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int rank[300100];
int sa[300100];
int tmp[300100];
int k;
string s;
int N,K;
bool compare_sa(int i,int j){
	if(rank[i]!=rank[j])return rank[i]<rank[j];
	int ri = (i+k<=N)?rank[i+k]:-1;
	int rj = (j+k<=N)?rank[j+k]:-1;
	return ri < rj;
}
int main(){
	cin >> s;
	scanf("%d",&K);
	N = sz(s);
	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='a')cnt++;
	}
	if(cnt<=K){
		for(int i=0;i<N-K;i++)printf("a");
		printf("\n");
		return 0;
	}
	for(int i=0;i<=N;i++){
		sa[i] = i;
		rank[i]=(i<N)?(int)(s[i]-'a'):-1;
	}
	sort(sa,sa+N+1);
	for(k=1;k<=N;k*=2){
		sort(sa,sa+N+1,compare_sa);
		tmp[sa[0]]=0;
		for(int j=1;j<=N;j++){
			tmp[sa[j]]=tmp[sa[j-1]]+(compare_sa(sa[j-1],sa[j])?1:0);
		}
		for(int j=0;j<=N;j++)rank[j]=tmp[j];
	}
	//for(int i=0;i<=N;i++)printf("%d\n",sa[i]);
	cnt = 0;
	int max_len = K;
	for(int i=0;i<N;i++){
		if(s[i]!='a')cnt++;
		if(cnt==K)max_len = i+1;
	}
	int l = INF,r = max_len;
	cnt = 0;
	for(int i=0;i<N;i++){
		if(cnt>=max_len-K){
			l = i;
			break;
		}
		if(s[i]=='a')cnt++;
	}
	//printf("%d %d\n",l,r);
	int ans = -1;
	for(int i=0;i<=N;i++){
		if(sa[i]>=l&&sa[i]<=r){
			ans = sa[i];
			break;
		}
	}
	for(int i=0;i<max_len;i++)printf("a");
	cout << s.substr(ans) << endl;
	return 0;
}