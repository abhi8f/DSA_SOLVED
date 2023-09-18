bool isPrime(int n)
{
	if (n==1) return false;
	int sr=ceil(sqrt(n));
	for(int i=2;i<sr;i++){
		if (n%i==0) return false;
	}
	return true;
}
