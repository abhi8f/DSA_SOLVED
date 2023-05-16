// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int n){
    if (n<=2) return n;
    return r(n-1)+r(n-2);
}

int main(){
    int n; cin>>n;
    cout<<r(n)<<endl;
    return 0;
}