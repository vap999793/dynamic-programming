#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    for(int i=0;i<m+1;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(s1[i-1] == s2[j-1] and i!=j){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];

}

int main(){
    string s1, s2;
    cin >> s1;
    s2 = s1;
    int n = s1.size();
    // int m = s2.size();

    cout << lcs(s1, s2, n, n);
    return 0;
}