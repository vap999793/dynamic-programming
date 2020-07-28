#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

bool isPalindrome(string s, int l, int r){
    while(l<r){
        if(s[l] != s[r]) return false;
        else{
            l++;
            r--;
        }
    }
    return true;
}

int palindromePartition(string s, int i, int j){
    if(i >= j){
        return 0;
    }

    if(isPalindrome(s, i, j) == true) return 0;

    if(t[i][j] != -1){
        return t[i][j];
    }

    int ans = INT_MAX;
    int left = 0, right = 0;
    for(int k=i;k<=j-1;k++){
        // int temp = palindromePartition(s, i, k) + palindromePartition(s, k+1, j) + 1;

        if(t[i][k] != -1){
            left = t[i][k];
        }
        else{
            left = palindromePartition(s, i, k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1){
            right = t[k+1][j];
        }
        else{
            right = palindromePartition(s, k+1, j);
            t[k+1][j] = right;
        }
        int temp = 1+left+right;
        ans = min(ans, temp);
        t[i][j] = ans;
    }
    
    return ans;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    memset(t, -1, sizeof(t));

    cout << palindromePartition(s, 0, n-1);
    return 0;
}