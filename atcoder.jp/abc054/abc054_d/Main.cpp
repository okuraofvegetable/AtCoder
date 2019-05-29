#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
#define mod 1e9+7
#define ll long long int
#define epsilon 1e-7
 
ll min(ll x, ll y){
    if(x < y)return x;
    else return y;
}
 
int main(void){
    int n, ma, mb;
    scanf("%d %d %d", &n, &ma, &mb);
    int ab[n], c[n];
    for(int i = 0;i < n;i++){
        int a, b;
        scanf("%d %d %d", &a, &b, &c[i]);
        ab[i] = b * ma - a * mb;
    }
    int dp[n][8000];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 8000;j++){
            dp[i][j] = mod;
        }
    }
    dp[0][4000+ab[0]] = c[0];
    for(int i = 1;i < n;i++){
        for(int j = 0;j < 8000;j++){
            if(dp[i-1][j]!=mod || j == 4000){
                dp[i][j] = min(dp[i-1][j], dp[i][j]);
                int plus;
                if(j==4000)plus = c[i];
                else plus = dp[i-1][j] + c[i];
                dp[i][j + ab[i]] = min(dp[i][j + ab[i]], plus);
            }
        }
    }
    if(dp[n-1][4000] != mod)printf("%d\n", dp[n-1][4000]);
    else printf("-1\n");
    return 0;
}