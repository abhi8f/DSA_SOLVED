class Solution
{
    private:
    static bool cmp(Item& a, Item& b) {
        double r1 = (double)a.value/a.weight;
        double r2 = (double)b.value/b.weight;

        if (r1 > r2) return true;
        return false;
    }

    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);

        double gain = 0;
        int i = 0;
        while((W != 0) && (i < n)) {
            double weight = arr[i].weight;
            if (weight <= W) {
                gain += arr[i].value;
                W -= weight;
            } else {
                double value = arr[i].value;
                gain += W*value/weight;
                W = 0;
            }
            i++;
        }
        return gain;
    }

};
