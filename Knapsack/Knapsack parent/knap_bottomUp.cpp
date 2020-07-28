#include<bits/stdc++.h>
using namespace std;

int knapsack(int profit[], int weight[], int cap, int n){
    int knap[n+1][cap+1];
    for(int i=0;i<n+1;i++){
        knap[i][0] = 0;
    }
    for(int i=0;i<cap+1;i++){
        knap[0][i] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<cap+1;j++){

            if(weight[i-1] <= cap){
                knap[i][j] = max(profit[i-1]+knap[i-1][j-weight[i-1]], knap[i-1][j]);
            }
            else{
                knap[i][j] = knap[i-1][j];
            }
        }
    }
    return knap[n][cap];
}

int main(){
    int profit[] = {60,100,120};
    int weight[] = {10,20,30};
    int capacity = 50;

    cout << knapsack(profit, weight, capacity, sizeof(profit)/sizeof(profit[0]));

    return 0;
}