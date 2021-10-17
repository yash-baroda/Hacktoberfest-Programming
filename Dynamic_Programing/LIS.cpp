#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
const int INF = 1e9;
const int N = 1e7+3;
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int lis[n];
    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++){
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    for(int i: lis) cout<<i<<" ";
    cout<<*max_element(lis, lis+n)<<endl;
    return 0;
}