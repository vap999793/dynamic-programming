#include<bits/stdc++.h>
using namespace std;

int min_coin(int coin[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<sum+1;i++){
        dp[0][i] = INT_MAX-1;
    }

    for(int i=1;i<n+1;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<sum+1;i++){
        if(i%coin[0] == 0){
            dp[1][i] = i/coin[0];
        }
        else{
            dp[1][i] = INT_MAX-1;
        }
    }

    for(int i=2;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1] <= j){
                dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coin[i-1]]);
            }
            else{

                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int coin[] = {1,2,3};
    int sum = 12;
    int n = sizeof(coin)/sizeof(coin[0]);

    cout << min_coin(coin, n, sum);
    return 0;
}