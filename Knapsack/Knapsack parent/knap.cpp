#include<bits/stdc++.h>
using namespace std;

int knapsack(int profit[], int weight[], int cap, int n){
    if(cap == 0 || n == 0) return 0;

    if(weight[n-1] <= cap){
        return max(profit[n-1] + knapsack(profit, weight, cap-weight[n-1], n-1), knapsack(profit, weight, cap, n-1));
    }
    else{
        return knapsack(profit, weight, cap, n-1);
    }
}

int main(){
    int profit[] = {60,100,120};
    int weight[] = {10,20,30};
    int capacity = 50;

    cout << knapsack(profit, weight, capacity, sizeof(profit)/sizeof(profit[0]));

    return 0;
}