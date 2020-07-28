#include<bits/stdc++.h>
using namespace std;
int dp[100][1000];

int eggDropping(int e, int f){
    if(f == 0 || f == 1) return f;
    if(e == 1) return f;

    if(dp[e][f] != -1) return dp[e][f];

    int ans = INT_MAX;
    int low = 0, high = 0;
    for(int k=1;k<f;k++){
        // int temp = 1+max(eggDropping(e-1, k-1), eggDropping(e, f-k));
        if(dp[e-1][k-1] != -1){
            low = dp[e-1][k-1];
        }
        else{
            low = eggDropping(e-1, k-1);
            dp[e-1][k-1] = low;
        }

        if(dp[e][f-k] != -1){
            high = dp[e][f-k];
        }
        else{
            high = eggDropping(e, f-k);
            dp[e][f-k] = high;
        }
        int temp = 1+max(low, high);
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    int egg, floor;
    cin >> egg >> floor;
    memset(dp, -1, sizeof(dp));
    cout << eggDropping(egg, floor) << endl;
    return 0;
}
