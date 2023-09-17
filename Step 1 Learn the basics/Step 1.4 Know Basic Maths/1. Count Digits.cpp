int countDigits(int n){
	int c=0, md, nn=n;
	while(nn){
		md=nn%10;
		nn/=10;
		if (md!=0 && n%md==0) c++;
	}	
	return c;
}