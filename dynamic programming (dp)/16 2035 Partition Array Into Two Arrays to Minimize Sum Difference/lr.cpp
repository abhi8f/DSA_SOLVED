// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout<<#x<<": "<<x<<endl;
int h=1;
#define h() cout<<"h "<<h++<<endl;

int r(int i, int c, int k, vector<int> &arr) {
    if (i<0) return c==0?abs(k):INT_MAX;
    return min(
        r(i-1,c,k,arr),
        (c>=1 && k>=arr[i])?r(i-1,c-1,k-arr[i],arr):INT_MAX
    );
}

class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n=arr.size();
        int mn=*min_element(arr.begin(),arr.end());
        if (mn<0){
            mn=abs(mn);
            for(int i=0;i<n;i++) arr[i]+=mn;
        }
        double k = 0;
        for (int i=0; i<n; i++) k += arr[i];
        if (k==0) return 0;
        k /= 2;
        int floatingCase = (int)k==k?0:1;
        int tar = (int)k;
        return 2*r(n-1,n/2,tar,arr)+floatingCase;
    }
};

int main(){
    Solution s;
    vector<int> v={3,9,7,3};
    cout<<s.minimumDifference(v);
    return 0;
}