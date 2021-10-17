#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;
int main()
{
    int n; cin>>n;
    vector<int> dp(n, N);
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 3; 
    for(int i=1; i<=n; i++){
        for(int j=0; i*i+j <= n; j++){
            dp[i*i+j] = min(dp[i*i+j], 1+dp[j]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}