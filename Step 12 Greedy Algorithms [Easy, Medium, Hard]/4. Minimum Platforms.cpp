class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int, int>> train;
    	for(int i = 0; i < n; i++) {
    	    train.emplace_back(arr[i], 0);
    	    train.emplace_back(dep[i], 1);
    	}
    	sort(train.begin(), train.end());

    	int count = 0;
    	int ans = 0;

    	for(int i = 0; i < 2*n; i++) {
    	    if (train[i].second == 0) {
    	        count++;
    	        ans = max(ans, count);
    	    } else {
    	        count--;
    	    }
    	}

    	return ans;

    }
};
