#include <iostream>
using namespace std;
int step[8][2] = {
    {0, 1},   //north
    {1, 0},   //east
    {-1, 0},  //west
    {0, -1},  //south
    {1, 1},   //northeast
    {1, -1},  //eastsouth
    {-1, -1}, //southwest
    {-1, 1},  //northwest;
};
string name[8] = {"N", "E", "W", "S", "ne", "es", "sw", "nw"};

int paths(bool maze[][5], int sr, int sc, int er, int ec, string ans)
{

    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    maze[sr][sc] = 1;
    for (int direc = 0; direc < 8; direc++)
    {

        int row = sr + step[direc][1];
        int col = sc + step[direc][0];

        if (row >= 0 && row <= er && col >= 0 && col <= ec && maze[row][col] == 0)
            count += paths(maze, row, col, er, ec, ans + name[direc]);
    }
    maze[sr][sc] = 0;

    return count;
}
int main()
{
    bool maze[5][5] = {0};
    cout << paths(maze, 0, 0, 3, 3, "");
}