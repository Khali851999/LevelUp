#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
vector<int> umap(26);
int usedNum = 0;
string s1, s2, s3;

int getNumber(string s)
{
    int res = 0;
    for (auto x : s)
        res = res * 10 + umap[x - 'a'];
    return res;
}

int solve(string s)
{
    if (s.size() == 0)
    {
        int num1 = getNumber(s1);
        int num2 = getNumber(s2);
        int num3 = getNumber(s3);

        if (num1 + num2 == num3)
        {
            cout << num1 << endl
                 << "+" << num2 << endl
                 << "--------" << endl
                 << num3 << endl<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int num = 0; num <= 9; num++)
    {
        int mask = (1 << num);
        char ch = s[0];

        if ((usedNum & mask) == 0)
        {
            usedNum ^= mask;
            umap[ch - 'a'] = num;

            count += solve(s.substr(1));

            usedNum ^= mask;
            umap[ch - 'a'] = 0;
        }
    }
    return count;
}

void crypto()
{

    s1 = "send";
    s2 = "more";
    s3 = "money";

    bitset<26> uniq;
    for (auto x : s1 + s2 + s3)
        uniq[x - 'a'] = 1;

    string s = "";
    for (int i = 0; i < 26; i++)
        if (uniq[i] == 1)
            s += (i + 'a');

    int ans = solve(s);
    cout << ans << endl;
}
int main()
{
    crypto();
}