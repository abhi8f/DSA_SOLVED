class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        //iterating over each character of the string.
        for (auto i = 0; i < s.size(); ++i) {
            int cnt[26] = {}, max_f = 0, min_f = 0;

            //iterating over subarrays starting from i.
            for (auto j = i; j < s.size(); ++j) {
                int idx = s[j] - 'a';
                //updating maximum frequency.
                max_f = max(max_f, ++cnt[idx]);

                //updating minimum frequency.
                if (min_f >= cnt[idx] - 1) {
                    min_f = cnt[idx];
                    for (int k = 0; k < 26; ++k)
                        //finding minimum frequency of all characters.
                        min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
                }

                //adding the difference between maximum and minimum frequency.
                ans += max_f - min_f;
            }
        }

        //returning the beauty sum.
        return ans;
    }
};
