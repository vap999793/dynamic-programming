#include<bits/stdc++.h>
using namespace std;

vector<int>subsetSum(int set[], int sum, int n){

    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<sum+1;i++){
        dp[0][i] = false;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(set[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j]||dp[i-1][j-set[i-1]];
            }
        }
    }
    vector<int>v;
    for(int i=0;i<sum/2+1;i++){
        if(dp[n][i] == true){
            cout<<i<<" ";
            v.push_back(i);
        }
    }
    return v;
}

int main(){
    int set[] = {1, 6, 11, 5}; // Only given thing
    int n = sizeof(set)/sizeof(set[0]);
    int range = 0;
    for(int i=0;i<n;i++){
        range += set[i];
    }

    vector<int>v = subsetSum(set, range, n);
    int ans = INT_MAX;
    for(int i=0;i<v.size();i++){
        ans = min(ans, range-2*v[i]);
    }
    cout<<endl<<ans<<endl;

    return 0;

}