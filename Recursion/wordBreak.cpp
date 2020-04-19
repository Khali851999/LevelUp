#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> umap;
int split(string s, vector<string> &res, string ans)
{
    if (s.size() == 0)
    {
        res.push_back(ans);
        return 1;
    }

    int c = 0;
    for (int len = 1; len <= s.size(); len++)
    {
        string t = s.substr(0, len);
        auto it = umap.find(t);
        if (it != umap.end())
        {
            c += split(s.substr(len), res, ans + t + " ");
        }
    }
    return c;
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<string> res;

    for (auto x : wordDict)
        umap[x] = 1;

    int ans = split(s, res, "");
    return res;
}
int main()
{
    string s = "catsanddog";
    vector<string> word = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = wordBreak(s, word);
    for (auto x : res)
        cout << x << endl;

    return 0;
}