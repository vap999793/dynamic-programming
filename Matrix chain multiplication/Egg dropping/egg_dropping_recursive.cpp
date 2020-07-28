#include<bits/stdc++.h>
using namespace std;

int eggDropping(int e, int f){
    if(f == 0 || f == 1) return f;
    if(e == 1) return f;

    int ans = INT_MAX;

    for(int k=1;k<f;k++){
        int temp = 1+max(eggDropping(e-1, k-1), eggDropping(e, f-k));
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    int egg, floor;
    cin >> egg >> floor;
    cout << eggDropping(egg, floor) << endl;
    return 0;
}
