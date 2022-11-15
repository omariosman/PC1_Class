/*
  Sheet 2
  Problem: G - Knight Moves
  Link: https://vjudge.net/problem/SPOJ-KNIGHTMV
  Algorithm: BFS
  Verdict: Accepted
*/

#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;


struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};


bool isInside(int x, int y, int N)
{
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    queue<cell> q;

    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    bool visit[N + 1][N + 1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;

    visit[knightPos[0]][knightPos[1]] = true;

    while (!q.empty()) {
        t = q.front();
        q.pop();


        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;

        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}



int main(){
    char str[6];
    char start_c,end_c;
    int start_i,end_i;
    while(cin.getline(str, sizeof(str))){
        start_c=str[0]; 
        int start_c_int = (int)start_c;

        start_i=str[1]-'0'; 
        end_c=str[3];

        int end_c_int = (int)end_c;

        end_i=str[4]-'0';
        int knight_pos[2];
        int target_pos[2];

        knight_pos[0] = start_c_int - 96;
        knight_pos[1] = start_i;

        target_pos[0] = end_c_int - 96;
        target_pos[1] = end_i;


    int N = 8;

    cout << "To get from " << str[0] << str[1] << " to " << str[3] << str[4] << " takes " << minStepToReachTarget(knight_pos, target_pos, N) << " knight moves.\n";

    }

    return 0;
} 
