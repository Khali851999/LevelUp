#include <iostream>
#include <vector>
using namespace std;
bool canPlaceH(vector<string> &board, string word, int i, int j)
{
    for (int c = 0; c < word.size() && j + c < board[0].size(); c++)
        if (board[i][j + c] != '-' && board[i][j + c] != word[c])

            return false;
    if (j - 1 >= 0 && board[i][j - 1] != '+')
        return false;
    if (j + word.size() < board[0].size() && board[i][j + word.size()] != '+')
        return false;
    return true;
}
int placeWordH(vector<string> &board, string word, int i, int j)
{
    int visited = 0;
    for (int c = 0; c < word.size() && c + j < board[0].size(); c++)
    {
        int mask = (1 << (j + c));
        visited ^= mask;
        board[i][j + c] = word[c];
    }
    return visited;
}
void unplaceWordH(vector<string> &board, int visited, string word, int i, int j)
{
    for (int c = 0; c < word.size() && j + c < board[0].size(); c++)
    {
        int mask = (1 << (j + c));
        if (visited & mask)
        {
            visited ^= mask;
            board[i][j + c] = '-';
        }
    }
}
bool canPlaceV(vector<string> &board, string word, int i, int j)
{
    for (int c = 0; c < word.size() && i + c < board.size(); c++)
        if (board[i + c][j] != '-' && board[i + c][j] != word[c])
            return false;
    if (i - 1 >= 0 && board[i - 1][j] != '+')
        return false;
    if (i + word.size() < board.size() && board[i + word.size()][j] != '+')
        return false;
    return true;
}
int placeWordV(vector<string> &board, string word, int i, int j)
{
    int visited = 0;
    for (int c = 0; c < word.size() && c + i < board.size(); c++)
    {
        int mask = (1 << (i + c));
        visited ^= mask;
        board[i + c][j] = word[c];
    }
    return visited;
}
void unplaceWordV(vector<string> &board, int visited, string word, int i, int j)
{
    for (int c = 0; c < word.size() && i + c < board[0].size(); c++)
    {
        int mask = (1 << (i + c));
        if (visited & mask)
        {
            visited ^= mask;
            board[i + c][j] = '-';
        }
    }
}
bool crosswordPuzzle(vector<string> &board, vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (auto x : board)
        {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool ans = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            string word = words[idx];
            if (board[i][j] == '-' || board[i][j] == word[0])
            {
                if (canPlaceH(board, word, i, j))
                {
                    int visited = placeWordH(board, word, i, j);
                    ans = ans || crosswordPuzzle(board, words, idx + 1);
                    unplaceWordH(board, visited, word, i, j);
                }

                if (canPlaceV(board, word, i, j))
                {
                    int visited = placeWordV(board, word, i, j);
                    ans = ans || crosswordPuzzle(board, words, idx + 1);
                    unplaceWordV(board, visited, word, i, j);
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<string> board{{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                         {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                         {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                         {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                         {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                         {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                         {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                         {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};
    // vector<string> words;
    // string w = "agra;norway;england;gwalior";

    // auto x = w.find(";");
    // while (x != string::npos)
    // {
    //     words.push_back(w.substr(0, x));
    //     w = w.substr(x);
    //     x = w.find(";");
    // }
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crosswordPuzzle(board, words, 0);
    return 0;
}