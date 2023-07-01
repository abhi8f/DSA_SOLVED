// TC: O(3^(m*n))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &str1, string &str2){
    if(i == 0) return j;
    if(j == 0) return i;
    if(str1[i-1] == str2[j-1]) return r(i-1, j-1, str1, str2);
    return 1 + min({r(i-1, j-1, str1, str2), r(i-1, j, str1, str2), r(i, j-1, str1, str2)});
}


int editDistance(string str1, string str2) {
    return r(str1.size(), str2.size(), str1, str2);
}

int main(){
    
    return 0;
}