class Solution
{
public:
    string getNumber(int B, int N)
    {
        unordered_map<int, char> mp = {
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'A'},
            {11, 'B'},
            {12, 'C'},
            {13, 'D'},
            {14, 'E'},
            {15, 'F'}
        };
        string ans = "";
        while (N) {
            int rem = N % B;
            ans.push_back(mp[rem]);
            N /= B;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
