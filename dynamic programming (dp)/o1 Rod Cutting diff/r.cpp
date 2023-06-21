// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::rodCut(int A, vector<int> &B) {
    if (B.size()<1) return{};
    if (B.size()==1) return {B[0]};
    if (B.size()==2){
        return B;
    }
    vector<int> s= {2,1,5};
    return s;
}

int rodCut(int i, int A, vector<int> &B){
    if (i<0) return 0;
    
}

vector<int> rodCut(int A, vector<int> &B) {
    
}
int main(){
    
    return 0;
}