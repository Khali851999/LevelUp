#include <bits/stdc++.h>
using namespace std;
#define n 10
// int r[n], c[n], d1[2 * n - 1], d2[2 * n - 1];
bitset<n> r(0), c(0);
bitset<2 * n - 1> d1(0), d2(0);
int calls = 0;
//O(n)
bool isSafe01(vector<vector<int>> &v, int i, int j)
{
    int direction[4][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (int dir = 0; dir < 4; dir++)
    {
        for (int rad = 1; rad <= n; rad++)
        {
            int row = i + rad * direction[dir][0];
            int col = j + rad * direction[dir][1];

            if (row < 0 || row >= n || col < 0 || col >= n)
                break;
            if (v[row][col] == 1)
                return false;
        }
    }
    return true;
}

//O(1)
bool isSafe02(int i, int j)
{

    if (r[i] == 1 || c[j] == 1 || d1[i - j + (n - 1)] == 1 || d2[i + j] == 1)
        return false;

    return true;
}

//O(n)
int nqueens01(vector<vector<int>> &v, int idx, int q, string ans)
{
    if (idx == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;
    for (int i = idx; i < n * n; i++)
    {
        int row = i / n;
        int col = i % n;

        if (isSafe01(v, row, col))
        {
            v[row][col] = 1;

            count += nqueens01(v, i + 1, q - 1, ans + "Q" + to_string(q) + " (" + to_string(row) + "," + to_string(col) + ") ");

            v[row][col] = 0;
        }
    }

    return count;
}

//O(1)
int nqueens02(int idx, int q, string ans)
{
    if (idx == n * n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = idx; i < n * n; i++)
    {
        int row = i / n;
        int col = i % n;

        if (isSafe02(row, col))
        {
            r[row] = 1;
            c[col] = 1;
            d1[row - col + (n - 1)] = 1;
            d2[row + col] = 1;
            calls++;
            count += nqueens02(i + 1, q - 1, ans + "Q" + to_string(q) + " (" + to_string(row) + "," + to_string(col) + ") ");

            r[row] = 0;
            c[col] = 0;
            d1[row - col + (n - 1)] = 0;
            d2[row + col] = 0;
        }
    }

    return count;
}

//as subsequence
int nqueens03(int idx, int q, string ans)
{
    if (idx == n * n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    int row = idx / n;
    int col = idx % n;

    if (isSafe02(row, col))
    {
        r[row] = 1;
        c[col] = 1;
        d1[row - col + (n - 1)] = 1;
        d2[row + col] = 1;

        count += nqueens03(idx + 1, q - 1, ans + "Q" + to_string(q) + " (" + to_string(row) + "," + to_string(col) + ") ");

        r[row] = 0;
        c[col] = 0;
        d1[row - col + (n - 1)] = 0;
        d2[row + col] = 0;
    }
    count += nqueens03(idx + 1, q, ans);

    return count;
}

//most optimized solution O(n^q)
//assign each row to 1 queen
int nqueens04(int rowNo, int q, string ans)
{
    if (rowNo == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    //trying to put queen in every column
    for (int i = 0; i < n; i++)
    {
        int row = rowNo;
        int col = i;

        if (isSafe02(row, col))
        {
            r[row] = 1;
            c[col] = 1;
            d1[row - col + (n - 1)] = 1;
            d2[row + col] = 1;
            calls++;
            count += nqueens04(rowNo + 1, q - 1, ans + "Q" + to_string(q) + " (" + to_string(row) + "," + to_string(col) + ") ");

            r[row] = 0;
            c[col] = 0;
            d1[row - col + (n - 1)] = 0;
            d2[row + col] = 0;
        }
    }

    return count;
}

//if q queens are to be placed in N*M matrix
// first placing q queens in n rows with 1 in each row at max
// then looping through columns to place a queen in jth column
int nqueens05(int N, int M, int rowNo, int q, string ans)
{
    if (rowNo == N || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    //queen sits in rowNo
    //trying to put queen in every column
    for (int i = 0; i < M; i++)
    {
        int row = rowNo;
        int col = i;

        if (isSafe02(row, col))
        {
            r[row] = 1;
            c[col] = 1;
            d1[row - col + (n - 1)] = 1;
            d2[row + col] = 1;
            calls++;
            count += nqueens05(N, M, rowNo + 1, q - 1, ans + "Q" + to_string(q) + " (" + to_string(row) + "," + to_string(col) + ") ");

            r[row] = 0;
            c[col] = 0;
            d1[row - col + (n - 1)] = 0;
            d2[row + col] = 0;
        }
    }
    //queen doesnot sits in rowNo
    count += nqueens05(N, M, rowNo + 1, q, ans);

    return count;
}

int main()
{
    vector<vector<int>> v(n, vector<int>(n, 0));
    // cout << nqueens01(v, 0, n, "");
    // cout << nqueens02(0, n, "") << endl<<calls;
    // cout << nqueens03(0, n, "") << endl;
    // cout << nqueens04(0, n, "") << endl<<calls;
    int N = 10, M = 5, q = 4;
    cout << nqueens05(N, M, 0, q, "") << endl;
    return 0;
}