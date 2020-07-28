#include<bits/stdc++.h>
using namespace std;

int lps(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    for(int i=0;i<m+1;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){

            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];

}

string reverse(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s1;
    cin >> s1;
    int n = s1.size();
    string s2 = reverse(s1);

    int lps_length = lps(s1, s2, n, n);
    int insertion = n-lps_length;
    int deletion = n-lps_length;

    //  Minimum number of insertion and deletion will be equal
    cout << "Minimum insertion required is :" << insertion << endl;
    cout << "Minimum deletion required is :" << deletion << endl;
    return 0;
}