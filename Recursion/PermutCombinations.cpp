#include <iostream>
using namespace std;
int permute(bool box[], int n, int q, string ans)
{
    if (q == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (box[i] == 0)
        {
            box[i] = 1;
            count += permute(box, n, q - 1, ans + " B" + to_string(i) + "Q" + to_string(q));
            box[i] = 0;
        }
    }
    return count;
}

int combi(int n, int index, int q, string ans)
{
    if (index == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;
    for (int i = index + 1; i < n; i++)
    {

        count += combi(n, i, q - 1, ans + " B" + to_string(i) + "Q" + to_string(q));
    }
    return count;
}

int permuteAsSubs(bool box[], int n, int index, int q, string ans)
{
    if (index == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    if (box[index] == 0)
    {
        box[index] = 1;
        count += permuteAsSubs(box, n, 0, q - 1, ans + " B" + to_string(index) + "Q" + to_string(q));
        box[index] = 0;
    }
    count += permuteAsSubs(box, n, index + 1, q, ans);

    return count;
}

int combiAsSubs(int n, int index, int q, string ans)
{
    if (index == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;
    count += combiAsSubs(n, index + 1, q - 1, ans + " B" + to_string(index) + "Q" + to_string(q));
    count += combiAsSubs(n, index + 1, q, ans);

    return count;
}

int permute2d(bool box[], int n, int q, string ans)
{
    if (q == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int r = i / n;
        int c = i % n;

        if (box[i] == 0)
        {
            box[i] = 1;
            count += permute2d(box, n, q - 1, ans + " Q" + to_string(q) + " (" + to_string(r) + "," + to_string(c) + ")");
            box[i] = 0;
        }
    }

    return count;
}

int combi2D(int n, int index, int q, string ans)
{
    if (index == n || q == 0)
    {
        if (q == 0)
        {
            cout << ans << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;
    for (int i = index + 1; i < n; i++)
    {
        int r = i / n;
        int c = i % n;
        count += combi2D(n, i, q - 1, ans + " Q" + to_string(q) + " (" + to_string(r) + "," + to_string(c) + ")");
    }
    return count;
}

int main()
{
    int n = 5, q = 3;
    bool box[n * n] = {0};
    // cout << "Permutations" << endl
    //      << permute(box, n, q, "") << endl;
    // cout << "Combinations" << endl
    //      << combi(n, -1, q, "") << endl;
    // cout << "PermutationsAsSubs" << endl
    //      << permuteAsSubs(box, n, 0, q, "") << endl;
    // cout << "CombinationsAsSubs" << endl
    //      << combiAsSubs(n, 0, q, "") << endl;
    // cout << "PermutationsIn2D" << endl
    //      << permute2d(box, n * n, q, "") << endl;
    cout << "CombinationsIn2D" << endl
         << combi2D(n*n, -1, q, "") << endl;
}