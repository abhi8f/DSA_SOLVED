class Solution
{
    private:
    static bool cmp(Job& a, Job& b) {
        if (a.profit > b.profit) return true;
        if (b.profit > a.profit) return false;
        return a.dead < b.dead;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        vector<int> job(n + 1, -1);
        int gain = 0;
        int count = 0;
        for(int i = 0; i<n; i++) {
            int dead = arr[i].dead;

            while ((dead > 0) && (job[dead] != -1)) {
                dead--;
            }
            if (dead != 0) {
                job[dead] = arr[i].id;
                gain += arr[i].profit;
                count++;
            }
        }

        return {count, gain};
    }
};
