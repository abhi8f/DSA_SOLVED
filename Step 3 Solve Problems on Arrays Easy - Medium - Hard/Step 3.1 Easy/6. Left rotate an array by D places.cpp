vector<int> rotateArray(vector<int>arr, int k) {
    k=k%arr.size();
    if (k==0) return arr;
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
    return arr;
}
