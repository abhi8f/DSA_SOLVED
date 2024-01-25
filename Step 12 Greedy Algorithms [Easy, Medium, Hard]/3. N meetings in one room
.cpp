class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meet;
        for(int i = 0; i < n; i++) {
            meet.emplace_back(end[i], start[i]);
        }
        sort(meet.begin(), meet.end());

        int count = 1;
        int preEnd = meet[0].first;
        int i = 1;
        while (i < n) {
            if (meet[i].second > preEnd) {
                count++;
                preEnd = meet[i].first;
            }
            i++;
        }
        return count;
    }
};
