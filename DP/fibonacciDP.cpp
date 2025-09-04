#include<bits/stdc++.h>
using namespace std;

//memoization
int fibDp(int n , vector<int> &dp){
    if(n == 0 || n== 1) return n;

    if(dp[n]!=-1) return dp[n];

    dp[n] = fibDp(n-1 ,dp) + fibDp(n-2,dp);

    return dp[n];
}

//using tabulation

int fibTabu(int n){
    vector<int> fib(n+1 , 0);
    if(n==0 || n==1) return n;

    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}

int main(){
    int n = 7;
    vector<int> dp(n+1 ,-1);

    //int ans = fibDp(n,dp);

    //cout<<ans<<endl;

    cout<<fibTabu(n);

    return 0;
}

