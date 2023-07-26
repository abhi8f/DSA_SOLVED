// TC: O(log(n))
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	int l=0, u=n -1, m, lb=n;

    while(l<=u){
        m=l+(u-l)/2;
        if (arr[m]>=x) lb=m, u=m-1;
        else l=m+1;
    }
    return lb;
}


int upperBound(vector<int> &arr, int x, int n) {
    int l=0, u=n-1, m, ub=n;
    while(l<=u){
        m=l+(u-l)/2;
        if (arr[m]>x) ub=m, u=m-1;
        else l=m+1;
    }
    return ub;
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main(){
    
    return 0;
}