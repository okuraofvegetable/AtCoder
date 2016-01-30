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
int n;
int a[200100];
vector<int> zip;
vector<int> s[100100];
int cnt = 0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)zip.pb(a[i]);
	sort(all(zip));
	zip.erase(unique(all(zip)),zip.end());
	for(int i=0;i<n;i++){
		a[i]=lower_bound(all(zip),a[i])-zip.begin();
		s[a[i]].pb(i);
	}
	for(int i=0;i<zip.size();i++)sort(all(s[i]));
	
	int ans = 0;
	int pre = INF;
	for(int i=0;i<zip.size();i++){
		int p=s[i].back();
		while(!s[i].empty()&&s[i].back()>pre){
			s[i].pop_back();
		}
		if(!s[i].empty()){
			pre = s[i].back();
			ans++;
		}
		else pre = p;
		//cout << p << endl;
	}
	if(pre==0)ans--;
	printf("%d\n",ans);
	return 0;
}