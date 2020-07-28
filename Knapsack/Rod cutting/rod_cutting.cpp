#include<bits/stdc++.h>
using namespace std;

int cut_rod(int price[], int length, int pieces[]){
    int dp[length+1][length+1];
    for(int i=0;i<length+1;i++){
        dp[i][0] = 0;
    }

    for(int i=0;i<length+1;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<length+1;i++){
        for(int j=1;j<length+1;j++){
            if(pieces[i-1] <= j){
                dp[i][j] = max(price[i-1]+dp[i][j-pieces[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[length][length];

}

int main(){
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int pieces[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(price)/sizeof(price[0]);
    cout << cut_rod(price, n, pieces);
    return 0;
}