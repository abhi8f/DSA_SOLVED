#include<bits/stdc++.h>

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> alloc(n - 1, 0);
	priority_queue<pair<long double, int>> pq;
	for(int i=1; i<n; i++) pq.push({arr[i] - arr[i-1], i-1});
	
	while (k--) {
		pair<double, int>  mx = pq.top(); pq.pop();
		int i = mx.second;
		alloc[i]++;
		long double diff = arr[i + 1] - arr[i];
		pq.push({diff/(alloc[i] + 1), i});
	}
	return pq.top().first;
}

#include<bits/stdc++.h>

int getNumberOfGasStations(vector<int> &arr, long double dist) {
    int cnt = 0, n = arr.size(), inBetween;

    for(int i = 1; i < n; i++) {
        inBetween = (arr[i] - arr[i - 1])/dist;

        if ((arr[i] - arr[i - 1])/dist == inBetween*dist) inBetween--;

        cnt += inBetween;
    }
    return cnt;
}


double minimiseMaxDistance(vector<int> &arr, int k) {
	int n = arr.size(), cnt;
    long double low = 0, high = 0, diff = 1e-6, mid;
    for(int i=1; i<n; i++) high = max(high, (long double)(arr[i] - arr[i - 1]));

    while(high - low > diff) {
        mid = low + (high - low) / 2.0;
        cnt = getNumberOfGasStations(arr, mid);

        if (cnt <= k) high = mid;
        else low = mid;
    }
    return high;
}

