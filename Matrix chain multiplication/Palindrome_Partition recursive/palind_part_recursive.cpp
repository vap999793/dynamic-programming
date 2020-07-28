#include<bits/stdc++.h>
using namespace std;

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

    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = palindromePartition(s, i, k) + palindromePartition(s, k+1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    cout << palindromePartition(s, 0, n-1);
    return 0;
}