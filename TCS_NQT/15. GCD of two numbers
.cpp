class Solution
{
	public:
    int gcd(int A, int B)
	{
	    if (A == 0) return B;

	    if (A > B) return gcd(A%B, B);
	    else return gcd(B%A, A);

	}
};
