/*
    Sheet 2
    Problem: B - Is it a tree
    Link: https://vjudge.net/problem/CodeChef-PD31
    Algorithm: DFS
    Status: Accepted

    Notes:
    In order for the graph to be a tree, 2 conditions need to be fulfilled:
    1- Number of nodes = Number of edges - 1
    2- The graph is connected (ya3ni we can reach all the nodes from root node)
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector <int>> G;
int visited[10000];

int DFS(int U){
    if (visited[U]){
        return 0;
    }
    visited[U] = 1;
    int ret = 1;
    for (int v: G[U]){
        ret += DFS(v);
    }
    return ret;

}

int main(){


    int n, m;
    cin >> n >> m;

    if (m + 1 != n) {
        cout << "NO";
        return 0;
    }

    G.resize(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int number_of_visited_nodes = DFS(0);
    if (number_of_visited_nodes == n){
        cout << "YES";
    } else {
        cout << "NO";
    }




    return 0;
}
