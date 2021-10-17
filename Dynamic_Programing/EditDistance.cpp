#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;

int min(int a, int b, int c){
    if(a<b and a<c)
        return a;
    else if(b<a and b<c)
        return b;
    return c;
}

// SIMPLE RECURSIVE SOLUTION
int EditDistance(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (s1[m - 1] == s2[n - 1])
        return EditDistance(s1, s2, m - 1, n - 1);
    else
        return 1 + min(EditDistance(s1, s2, m, n - 1), EditDistance(s1, s2, m - 1, n), EditDistance(s1, s2, m - 1, n - 1));
}

// DYNAMIC SOLUTION
int EditDistance(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        dp[i][0] = i;
    }for(int i=0; i<=n; i++){
        dp[0][i] = i;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<EditDistance(s1, s2, s1.length(), s2.length())<<endl;
    cout<<EditDistance(s1, s2)<<endl;
    return 0;
}