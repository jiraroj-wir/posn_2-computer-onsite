#include <bits/stdc++.h>
using namespace std;

int min_node(int n, int keyval[], bool mstset[]) {
    int mini = numeric_limits<int>::max();
    int mini_index;
 
    for (int i = 0; i < n; i++) {
        if (mstset[i] == false && keyval[i] < mini) {
        mini = keyval[i], mini_index = i;
        }
    }
    return mini_index;
}
 
void find_cost(int n, vector<vector<int>> city) {
    int parent[n];
    int keyval[n];
    bool mstset[n];
    for (int i = 0; i < n; i++) {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }
 
    parent[0] = -1;
    keyval[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = min_node(n, keyval, mstset);
        mstset[u] = true;
 
        for (int v = 0; v < n; v++) {
            if (city[u][v] && mstset[v] == false && city[u][v] < keyval[v]) {
                keyval[v] = city[u][v];
                parent[v] = u;
            }
        }
    }
 
    int cost = 0;
    for (int i = 1; i < n; i++) {
        cost += city[parent[i]][i];
    }
    cout << cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    cin >> V;
    cin.ignore();

    int a, b;
    vector<pair<int, int>> points;
    for (int i = 0; i < V; i++) {
        cin >> a >> b;
        points.push_back(make_pair(a, b));
    }

    vector<vector<int>> cost(V, vector<int>(V, 0));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cost[i][j] = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
        }
    }
    find_cost(V, cost);

    return 0;
}


/*#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int parent[MAX];
int ran[MAX];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void Union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (ran[xroot] < ran[yroot])
        parent[xroot] = yroot;
    else if (ran[xroot] > ran[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        ran[xroot]++;
    }
}

void kruskal_MST(int cost[][MAX], int V) {
    vector<pair<int, pair<int, int>>> edges;
    
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        ran[i] = 0;
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = i+1; j < V; j++) {
            if (cost[i][j] != 0) {
                edges.push_back({cost[i][j], {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    int mst_weight = 0;

    for (auto &edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            mst_weight += edge.first;
            Union(set_u, set_v);
        }
    }

    cout << mst_weight << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V;
    cin >> V;
    cin.ignore();

    int a, b;
    vector<pair<int, int>> points;
    for (int i=0; i<V; i++) {
        cin >> a >> b;
        points.push_back(make_pair(a, b));
    }

    int cost[MAX][MAX];
    for (int i=0; i<V; i++) {
        for (int j=0; j<V; j++) {
            cost[i][j] = (abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second));
        }
    }

    kruskal_MST(cost, V);

    return 0;
} */
