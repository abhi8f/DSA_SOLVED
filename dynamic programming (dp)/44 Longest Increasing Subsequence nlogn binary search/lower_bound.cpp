// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> v, int val){
    int l=0, u=v.size() -1, m, lb;

    while(l<=u){
        m=l+(u-l)/2;
        if (v[m]>=val) lb=m, u=m-1;
        else l=m+1;
    }
    return lb;
}

int main(){
    vector<int> v={3,5,8,15,19};
    cout<<lowerBound(v,17);
    return 0;
}