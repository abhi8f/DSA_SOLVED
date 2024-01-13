// Function to find the minimum and second minimum elements in the array.
vector<int> minAnd2ndMin(int a[], int n) {
    int min1 = a[0], min2 = INT_MAX;

    // Traverse the array to find the minimum and second minimum elements.
    for (int i = 1; i < n; i++) {
        // Update min1 and min2 if a[i] is smaller than both.
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        }
        // Update min2 if a[i] is smaller than min2 but greater than min1.
        else if (a[i] < min2 && a[i] != min1)
            min2 = a[i];
    }

    // If there is only one element in the array or second minimum is not found, return {-1, -1}.
    if (n == 1 || min2 == INT_MAX)
        return {-1, -1};
    // Otherwise, return the minimum and second minimum elements.
    else
        return {min1, min2};
}
