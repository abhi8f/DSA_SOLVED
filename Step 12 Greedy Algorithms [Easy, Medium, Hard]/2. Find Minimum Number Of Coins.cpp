vector<int> MinimumCoins(int n)
{
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    vector<int> ans;

    int i = 0;
	while ((n != 0) && (i < 9)) {
        int d = n/arr[i];
        if (d == 0) {
            i++;
            continue;
        }
        ans.insert(ans.end(), d, arr[i]);
        n = n%arr[i];
        i++;
    }

    return ans;
}
