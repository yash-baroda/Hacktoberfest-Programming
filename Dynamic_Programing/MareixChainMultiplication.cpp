#include<bits/stdc++.h>
#include<numeric>
#include<math.h>
using namespace std;
int main()
{
    int n = 4;
    int m[4][4];
    int p[] = {1, 2, 3, 4};
    int s[4][4];
    int j, min, q;
    for (int i = 1; i < n; i++)
        m[i][i]  = 0;

    for(int d=1; d<n; d++)
    {
        for(int i=1; i<n-d; i++)
        {
            j = i+d;
            m[i][j] = INT_MAX;
            for(int k = i; k<=j-1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    cout<<m[1][n-1]<<" ";

    return 0;
}