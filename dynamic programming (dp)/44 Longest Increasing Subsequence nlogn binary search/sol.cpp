// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n) {
    vector<int> v;
    v.push_back(arr[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if (arr[i]>v[len-1]){
            v.push_back(arr[i]);
            len++;
        } else {
            int index=lower_bound(v.begin(), v.end(), arr[i]) -v.begin();
            v[index]=arr[i];
        }
        
    }
    return len;
}

int main(){
    int arr[]={1, 2, 3, 4, 5};
    cout<<endl<<longestIncreasingSubsequence(arr,5)<<endl;
    return 0;
}