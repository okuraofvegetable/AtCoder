#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
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
int N;
P ball[55];
int f(ll dx,ll dy){
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((ball[i].fi-ball[j].fi==dx)&&(ball[i].sec-ball[j].sec==dy))cnt++;
        }
    }
    return N-cnt;
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> ball[i].fi >> ball[i].sec;
    }
    int ans = INF;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            ll dx = ball[i].fi - ball[j].fi;
            ll dy = ball[i].sec - ball[j].sec;
            ans = min(ans,f(dx,dy));
        }
    }
    if(N==1)ans = 1;
    cout << ans << endl;
    return 0;
}