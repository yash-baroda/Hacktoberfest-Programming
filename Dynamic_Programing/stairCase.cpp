#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;
int stairCase(int n){
    if(n==0) return 1;
    if(n==1 or n==2) return n;
    return stairCase(n-1) + stairCase(n-2) + stairCase(n-3);
}
int main()
{
    int n; cin>>n;
    cout<<stairCase(n)<<endl;
    return 0;
}