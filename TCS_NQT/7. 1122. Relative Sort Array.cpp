class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> index;
        for(int i = 0; i<arr2.size(); i++) {
            index[arr2[i]] = i + 1;
        }

        auto cmp = [&index](int& a, int& b) {
            int ai = index[a];
            int bi = index[b];

            if (ai == bi) return a < b;
            if (ai == 0) return false;
            if (bi == 0) return true;
            return ai < bi;
        };

        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};
