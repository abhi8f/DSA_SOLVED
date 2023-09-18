void rec(int i, vector<string> &ans){
	if (i==0) return;
	ans.push_back("Coding Ninjas");
	rec(i-1, ans);
}

vector<string> printNTimes(int n) {
	vector<string> ans;
	rec(n, ans);
	return ans;
}