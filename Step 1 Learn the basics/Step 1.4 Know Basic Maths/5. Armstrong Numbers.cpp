bool checkArmstrong(int n){
	int p=log10(n) + 1, nn=n, as=0;
	while(nn){
		as+=pow(nn%10, p);
		nn/=10;
	}
	return n==as;
}
