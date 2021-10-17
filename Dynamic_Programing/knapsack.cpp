#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;

int Knapsack(int W, int wt[], int p[], int n){
    int dp[n+][w+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(w[i-1] > j)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + p[i]);
        }
    }
    cout<<dp[n][w]<<endl;
}

int main()
{
    int p[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int n = 3, W = 50;
    int i, w;
    int K[n + 1][W + 1];
    cout<<Knapsack(W, wt, p, n);
    return 0;
}