class Solution {
    private boolean isSubBoxValid(int x, char[][] board) {
        int iS = (x/3)*3;
        int jS = (x % 3)*3;
        ArrayList<Boolean> present = new ArrayList<>(Collections.nCopies(9, false));

        for(int i = 0; i <  3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if (board[i + iS][j + jS] == '.') continue;
                int val = board[i + iS][j + jS] - '0' -1;
                if (present.get(val)) {
                    return false;
                }
                present.set(val, true);
            }
        }
        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; ++i) {
            ArrayList<Boolean> present = new ArrayList<>(Collections.nCopies(9, false));

            for(int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0' -1;
                if (present.get(val)) {
                    return false;
                }
                present.set(val, true);
            }
        }

        for(int j = 0; j < 9; ++j) {
            ArrayList<Boolean> present = new ArrayList<>(Collections.nCopies(9, false));

            for(int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '0' -1;
                if (present.get(val)) {
                    return false;
                }
                present.set(val, true);
            }
        }

        for(int x = 0; x < 9; ++x) {
            if (!isSubBoxValid(x, board)) return false;
        }

        return true;

    }
}

import java.util.AbstractMap;
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int n = board.length;
        HashMap<Integer, HashSet<Character>> rows = new HashMap<>();
        HashMap<Integer, HashSet<Character>> cols = new HashMap<>();
        HashMap<AbstractMap.SimpleEntry<Integer, Integer>, HashSet<Character>> subMat = new HashMap<>();

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                HashSet<Character> curRowSet = rows.get(i);
                HashSet<Character> curColSet = cols.get(j);
                HashSet<Character> curSubMatSet = subMat.get(new AbstractMap.SimpleEntry<>(i/3, j/3));

                if ((curRowSet != null) && (curRowSet.contains(board[i][j]))) {
                    return false;
                }
                if ((curColSet != null) && (curColSet.contains(board[i][j]))) {
                    return false;
                }
                if ((curSubMatSet != null) && (curSubMatSet.contains(board[i][j]))) {
                    return false;
                }
                if (curRowSet == null) {
                    HashSet<Character> newRowSet = new HashSet<>();
                    newRowSet.add(board[i][j]);
                    rows.put(i, newRowSet);
                } else {
                    curRowSet.add(board[i][j]);
                }
                if (curColSet == null) {
                    HashSet<Character> newColSet = new HashSet<>();
                    newColSet.add(board[i][j]);
                    cols.put(j, newColSet);
                } else {
                    curColSet.add(board[i][j]);
                }
                if (curSubMatSet == null) {
                    HashSet<Character> newSubMatSet = new HashSet<>();
                    newSubMatSet.add(board[i][j]);
                    subMat.put(new AbstractMap.SimpleEntry<>(i/3, j/3), newSubMatSet);
                } else {
                    curSubMatSet.add(board[i][j]);
                }
            }
        }

        return true;
    }
}
