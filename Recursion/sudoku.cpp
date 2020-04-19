#include <bits/stdc++.h>
using namespace std;
bool isSafe01(vector<vector<int>> &a, int i, int j, int num)
{
    int n = a.size();
    int m = a[0].size();

    //col
    for (int var = 0; var < n; var++)
    {
        if (a[var][j] == num || a[i][var] == num)
            return false;
    }

    int boxr = (i / 3) * 3;
    int boxc = (j / 3) * 3;

    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (a[boxr + r][boxc + c] == num)
                return false;
        }
    }

    return true;
}
//for all solutions
int sudoku01(vector<vector<int>> &a, int idx)
{

    if (idx == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return 1;
    }

    int count = 0;
    int r = idx % 9;
    int c = idx / 9;

    if (a[r][c] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafe01(a, r, c, num))
            {
                a[r][c] = num;
                count += sudoku01(a, idx + 1);
                a[r][c] = 0;
            }
        }
    }
    else
        count += sudoku01(a, idx + 1);

    return count;
}

//for 1 solution
bool sudoku01_(vector<vector<int>> &a, int idx)
{

    if (idx == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return 1;
    }

    bool res = 0;
    int r = idx % 9;
    int c = idx / 9;

    if (a[r][c] == 0)
    {
        for (int num = 1; num <= 9 && !res; num++)
        {
            if (isSafe01(a, r, c, num))
            {
                a[r][c] = num;
                res = res || sudoku01_(a, idx + 1);
                a[r][c] = 0;
            }
        }
    }
    else
        res = res || sudoku01_(a, idx + 1);

    return res;
}

//==========================================OPTIMIZATION USING BITS=======================================================================

vector<int> row(9, 0), col(9, 0);
vector<vector<int>> mat(3, vector<int>(3, 0));
// Optimized is safe by settings bits of all the numbers already present in sudoku
int sudoku02(vector<vector<int>> &a, int idx)
{

    if (idx == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return 1;
    }

    int count = 0;
    int r = idx % 9;
    int c = idx / 9;

    if (a[r][c] == 0)
    {
        for (int num = 1; num <= 9; num++)
        {
            int mask = (1 << num);

            //Optimized is safe using bits
            if (!(row[r] & mask) && !(col[c] & mask) && !(mat[r / 3][c / 3] & mask))
            {
                a[r][c] = num;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;

                count += sudoku02(a, idx + 1);

                a[r][c] = 0;
                row[r] ^= mask;
                col[c] ^= mask;
                mat[r / 3][c / 3] ^= mask;
            }
        }
    }
    else
        count += sudoku02(a, idx + 1);

    return count;
}

//now it only traverses the non-zero elements so extra calls are saved
int sudoku03(vector<vector<int>> &a, int idx, vector<int> &indicesWithZero)
{

    if (idx == indicesWithZero.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        return 1;
    }

    int count = 0;
    int r = indicesWithZero[idx] % 9;
    int c = indicesWithZero[idx] / 9;

    for (int num = 1; num <= 9; num++)
    {
        int mask = (1 << num);

        //Optimized is safe using bits
        if (!(row[r] & mask) && !(col[c] & mask) && !(mat[r / 3][c / 3] & mask))
        {
            a[r][c] = num;
            row[r] ^= mask;
            col[c] ^= mask;
            mat[r / 3][c / 3] ^= mask;

            count += sudoku03(a, idx + 1, indicesWithZero);

            a[r][c] = 0;
            row[r] ^= mask;
            col[c] ^= mask;
            mat[r / 3][c / 3] ^= mask;
        }
    }

    return count;
}

int main()
{
    vector<vector<int>> a = {{3, 1, 9, 0, 0, 0, 0, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    // cout << sudoku01(a, 0) << endl;
    // cout << sudoku01_(a, 0) << endl;

    vector<int> indicesWithZero;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != 0)
            {
                int mask = (1 << a[i][j]);
                row[i] ^= mask;
                col[j] ^= mask;
                mat[i / 3][j / 3] ^= mask;
            }
            else
            {
                //converting 2d array into 1d
                //original indices can be get by (value%9,value/9)
                indicesWithZero.push_back(9 * j + i);
            }
        }
    }

    // cout << sudoku02(a, 0) << endl;
    cout << sudoku03(a, 0, indicesWithZero) << endl;
}