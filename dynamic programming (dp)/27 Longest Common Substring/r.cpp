// TC: O(2^(m+n))))
// SC: O(m+n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int j, string &s1, string &s2){
    if (i<0 || j<0) return 0;
    int ans = 0;
    int i2 = i, j2 = j;
    while(i2>=0 && j2>=0 && s1[i2]==s2[j2]) ans++, i2--, j2--;
    return max({ans, r(i-1, j, s1, s2), r(i, j-1, s1, s2)});
}

int lcs(string &str1, string &str2){
    int m = str1.size(), n = str2.size();
    return r(m-1, n-1, str1, str2);
}

int main(){
    
    return 0;
}