// //339. Nested List Weight Sum

// /**
// Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
// Example 1:
// Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
// Example 2:
// Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
// */

// /**
//  *  This is the interface that allows for creating nested lists.
//  * You should not implement it, or speculate about its implementation**/

// #include <vector>
// #include <string>
// using namespace std;

// class NestedInteger
// {
// public:
//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;

//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;

//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

// class Solution
// {
// public:
//     int sum(vector<NestedInteger> &nestedList, int idx)
//     {
//         NestedInteger i = nestedList[idx];
//         int res = 0;
//         if (i.isInteger())
//             res += i.getInteger();
//         else
//         {
//             int depth = i.getList().size();
//             res += depth * sum(i.getList(), idx + 1);
//         }
//         int depthSum(vector<NestedInteger> & nestedList)
//         {
//         }
//     };

//     int main()
//     {
//         return 0;
//     }

//     int shortestPathBinaryMatrix(vector<vector<int>> &visited)
//     {
//         int n = visited.size();
//         queue<pair<int, int>> q;
//         int count = 1;
//         q.push({0, 0});
//         visited[0][0] = 1;
//         vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
//         while (q.size())
//         {

//             int size = q.size();

//             while (size--)
//             {
//                 pair p = q.front();
//                 int i = p.first;
//                 int j = p.second;
//                 q.pop();

//                 if (i == n - 1 && j == n - 1)
//                     return visited[i][j];

//                 for (auto t : directions)
//                 {

//                     int x = i + t[0];
//                     int y = j + t[1];

//                     if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0)
//                     {
//                         q.push({x, y});
//                         visited[x][y] = visited[i][j] + 1;
//                         count++;
//                     }
//                 }
//             }
//         }

//         return -1;
//     }

//     //Leetcode 663
//     /*
// You are given a m x n 2D grid initialized with these three possible values.

// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647
// to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate,
//  that room should remain filled with INF

// Have you met this question in a real interview?
// Example
// Example1

// Input:
// [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],
// [2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output:
// [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

// Explanation:
// the 2D grid is:
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
// the answer is:
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4
// Example2

// Input:
// [[0,-1],[2147483647,2147483647]]
// Output:
// [[0,-1],[1,2]]
// */

//     class Solution
//     {
//     public:
//         /**
//      * @param rooms: m x n 2D grid
//      * @return: nothing
//      */
//         void wallsAndGates(vector<vector<int>> &a)
//         {
//             int n = a.size();
//             if (n == 0 | a[0].size() == 0)
//                 return;
//             int m = a[0].size();
//             queue<int> q;
//             vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//             for (int i = 0; i < n; i++)
//                 for (int j = 0; j < m; j++)
//                     if (a[i][j] == 0)
//                         q.push(i * m + j);

//             int level = 1;
//             while (q.size())
//             {
//                 int size = q.size();
//                 while (size--)
//                 {
//                     int val = q.front();
//                     q.pop();

//                     int r = val / m;
//                     int c = val % m;

//                     for (auto x : dir)
//                     {
//                         int i = r + x[0];
//                         int j = c + x[1];

//                         if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == 2147483647)
//                         {
//                             q.push(i * m + j);
//                             a[i][j] = level;
//                         }
//                     }
//                 }
//                 level++;
//             }
//         }
//     };

//======================================+++SNAKES AND LADDER==========================================================


//===========LEETCODE 1061(SMALLEST LEXIOGRAPHICAL)======================================================
// #include <bits/stdc++.h>
// vector<int> par;
// int findPar(int vtx)
// {
//     if (par[vtx] == vtx)
//         return vtx;
//     par[vtx] = findPar(par[vtx]);
//     return par[vtx];
// }
// string solve(string a, string b, string c)
// {

//     for (int i = 0; i < 26; i++)
//         par.push_back(i);

//     for (int i = 0; i < a.size(); i++)
//     {
//         int p1 = findPar(a[i] - 'a');
//         int p2 = findPar(b[i] - 'a');
//         par[p1] = min(p1, p2);
//         par[p2] = min(p1, p2);
//     }
//     string ans = "";
//     for (int i = 0; i < c.size(); i++)
//     {
//         ans += findPar(c[i] - 'a') + 'a';
//     }
//     return ans;
// }

// //=============================================Leetcode 839=====================================================
// bool isSimilar(string s1, string s2)
// {
//     int count = 0;
//     for (int k = 0; k < s1.size(); k++)
//     {
//         if (s1[k] != s2[k] && ++count > 2)
//             return false;
//     }
//     return true;
// }
// int numSimilarGroups(vector<string> &a)
// {
//     int n = a.size();
//     for (int i = 0; i < n; i++)
//         par.push_back(i);
//     int count = n;
//     vector<vector<int>> g(n, vector<int>());
//     for (int i = 0; i < n; i++)
//     {
//         string s1 = a[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             if (isSimilar(s[i], s[j]))
//             {
//                 int p1 = findPar(i);
//                 int p2 = findPar(j);
//                 if (p1 != p2)
//                 {
//                     par[p2] = p1;
//                     count--;
//                 }
//             }
//         }
//     }
//     return count;
// }