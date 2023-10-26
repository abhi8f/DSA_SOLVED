void getSubsetSums(int i, int sum, vector<int> &num, vector<int> &ans) {
	if (i<0) {
		ans.push_back(sum);
		return;
	}
	getSubsetSums(i-1, sum, num, ans);
	getSubsetSums(i-1, sum + num[i], num, ans);
	return;
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	getSubsetSums(num.size()-1, 0, num, ans);
	sort(ans.begin(), ans.end());
	return ans;
}
