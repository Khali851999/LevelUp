public class floodFillVariation {

    public static void main(String[] args) {

        boolean[][] board = new boolean[4][4];
        pair ans = ffHeight(board, 0, 0);
        // pair ans = ffMinPath(board, 0, 0);
        System.out.println(ans.str + "-" + ans.len);

    }

    static int[][] step = { { 0, 1 }, // north
            { 1, 0 }, // east
            { -1, 0 }, // west
            { 0, -1 }, // south
            { 1, 1 }, // northeast
            { 1, -1 }, // eastsouth
            { -1, -1 }, // southwest
            { -1, 1 }, // northwest;
    };

    static String[] name = { "N", "E", "W", "S", "ne", "es", "sw", "nw" };

    static class pair {
        int len = 0;
        String str = "";

        pair(int len, String str) {
            this.len = len;
            this.str = str;
        }
    }

    public static pair ffMinPath(boolean[][] board, int i, int j) {

        if (i == board.length - 1 && j == board[0].length - 1) {
            return new pair(0, "");
        }

        board[i][j] = true;
        pair ans = new pair((int) 1e7, "");

        for (int dir = 0; dir < 8; dir++) {
            int r = i + step[dir][1];
            int c = j + step[dir][0];

            if (r >= 0 && r < board.length && c >= 0 && c < board[0].length && board[r][c] == false) {
                pair recans = ffMinPath(board, r, c);

                if (recans.len + 1 < ans.len) {
                    // System.out.println("hit");
                    ans.len = recans.len + 1;
                    ans.str = name[dir] + recans.str;
                }
            }

        }

        board[i][j] = false;
        return ans;
    }

    public static pair ffHeight(boolean[][] board, int i, int j) {

        if (i == board.length - 1 && j == board[0].length - 1) {
            return new pair(0, "");
        }

        board[i][j] = true;
        pair ans = new pair(0, "");

        for (int dir = 0; dir < 8; dir++) {
            int r = i + step[dir][1];
            int c = j + step[dir][0];

            if (r >= 0 && r < board.length && c >= 0 && c < board[0].length && board[r][c] == false) {
                pair recans = ffHeight(board, r, c);

                if (recans.len + 1 > ans.len) {
                    ans.len = recans.len + 1;
                    ans.str = recans.str + name[dir];
                }
            }

        }

        board[i][j] = false;
        return ans;
    }
}