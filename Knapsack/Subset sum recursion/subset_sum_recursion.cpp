#include<bits/stdc++.h>
using namespace std;

bool subset_exist(int set[], int n, int sum){
    if(sum == 0) return true;
    if(n == 0 && sum!=0) return false;

    if(set[n-1] > sum){
        return subset_exist(set, n-1, sum);
    } 
    else{
        return subset_exist(set, n-1, sum)||subset_exist(set, n-1, sum-set[n-1]);
    }
}

int main(){

    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);

    if(subset_exist(set, n, sum) == true){
        cout << "Subset exist"<<endl;
    }

    else{
        cout << "Subset does not exist" << endl;
    }

    return 0;
}