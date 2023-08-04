// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
pair<int, int> r(int i, int j, vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    if (i >= rows || j >= cols) return {0, 0};
    if (matrix[i][j] == '0') {
        r(i + 1, j, matrix);
        r(i, j + 1, matrix);
        return {0, 0};
    }
    pair<int, int> down = r(i + 1, j, matrix), right = r(i, j + 1, matrix), z = {0, 0};
    if (down == z && right == z) {
        ans = max(ans, 1);
        return {1, 1};
    }
    pair<int, int> cur;
    if (down == z) {
        cur.first = right.first + 1;
        cur.second = 1;
        ans = max(ans, cur.first);
    } else if (right == 0) {
        cur.first = 1;
        cur.second = down.second + 1;
        ans = max(ans, cur.second);
    } else {
        cur.first = min(down.first, right.first) + 1;
        cur.second = min(down.second, right.second) + 1;
        ans = max(ans, cur.first * cur.second);
    }
    return cur;
}

class Solution {
   private:
    int ans = 0;
    pair<int, int> r(int i, int j, vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (i >= rows || j >= cols) return {0, 0};
        if (matrix[i][j] == '0') {
            r(i + 1, j, matrix);
            r(i, j + 1, matrix);
            return {0, 0};
        }
        pair<int, int> down = r(i + 1, j, matrix), right = r(i, j + 1, matrix), z = {0, 0};
        if (down == z && right == z) {
            ans = max(ans, 1);
            return {1, 1};
        }
        pair<int, int> cur;
        if (down == z) {
            cur.first = right.first + 1;
            cur.second = 1;
            ans = max(ans, cur.first);
        } else if (right == 0) {
            cur.first = 1;
            cur.second = down.second + 1;
            ans = max(ans, cur.second);
        } else {
            cur.first = min(down.first, right.first) + 1;
            cur.second = min(down.second, right.second) + 1;
            ans = max(ans, cur.first * cur.second);
        }
        return cur;
    }

   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        r(0,0,matrix);
        return ans;
    }
};

int main() {
    return 0;
}