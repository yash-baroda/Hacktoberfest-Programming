#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;

// NORMAL RECURSIVE SOLUTION
int LCS(string s1, string s2, int m, int n){
    if(m==0 or n==0)
        return 0;
    if(s1[m-1] == s2[n-1])
        return 1 + LCS(s1, s2, m-1, n-1);
    else
        return max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
}

// TABULATION SOLUTION {DYNAMIC PROGRAMMING}
int LCS2(string s1, string s2){
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1] = {0};
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin>>s1 >> s2;
    int m = s1.length(), n = s2.length();
    // cout<<LCS(s1, s2, m, n)<<endl;
    cout<<LCS2(s1, s2)<<endl;
    return 0;
}