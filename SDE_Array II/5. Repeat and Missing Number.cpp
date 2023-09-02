vector<int> Solution::repeatedNumber(const vector<int> &arr){
    int n=arr.size();
	int xorArrAndN=0;
	for(int i=0;i<n;i++) xorArrAndN^=arr[i]^(i+1);

	int diffBit=1;
	while((xorArrAndN&diffBit)!=diffBit) diffBit<<=1;

	int group0=0, group1=0;

	for(int i=0;i<n;i++) {
		if (diffBit&arr[i]) group1^=arr[i];
		else group0^=arr[i];
		if (diffBit&(i+1)) group1^=(i+1);
		else group0^=(i+1);
	}
	
	for(int i=0;i<n;i++) if (arr[i]==group0) return {group0, group1};
	return {group1,group0};
}