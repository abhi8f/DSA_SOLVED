// TC: O(2n) = O(n)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;


long long int houseRobber(vector<int>& valueInHouse){
    long long n=valueInHouse.size();
    long long pre2=0, pre=valueInHouse[0];
    for(long long i=1;i<n-1;i++){
        long long newPre=max(valueInHouse[i]+pre2,pre);
        pre2=pre;
        pre=newPre;
    }
    long long first=pre;

    pre2=0;
    pre=0;
    for(long long i=1;i<n;i++){
        long long newPre=max(valueInHouse[i]+pre2,pre);
        pre2=pre;
        pre=newPre;
    }
    long long second=pre;
    return max(first,second);
}

int main() {
    // 1 2 3 1 3 5 8 1 9
    vector<int> v = {1,5,1,2,6};
    cout << houseRobber(v) << endl;
    return 0;
}