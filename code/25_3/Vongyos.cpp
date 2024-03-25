#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> make_graph(int n) {
    vector<vector<int>> adj(n, vector<int>(n));
    int num;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> num;
            adj[i][j] = num;
        }
    }

    return adj;
}

void print_graph(vector<vector<int>> adj, int n) {
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }

    return;
}

bool is_direct_graph(vector<vector<int>> adj, int n) {
    bool dg = false;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (adj[i][j] == adj[j][i]) {
                continue; 
            }
            dg = true;
            goto END;
        }
    }

END:
    return dg;
}

int degree(vector<vector<int>> adj, int n, int node) {
    int deg = 0;
    if (is_direct_graph(adj, n) || node >= n) {
        return -1;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == node || j == node) {
                if (adj[i][j] != 0) {
                    deg++;
                }
            }
        }
    }
    
    return deg/2; 
}

int in_degree(vector<vector<int>> adj, int n, int node) {
    int in_deg = 0;
    if (!(is_direct_graph(adj, n)) || node >= n) {
        return -1;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == node) {
                if (adj[i][j] != 0) {
                    in_deg++;
                }
            }
        }
    }
    
    return in_deg; 
}

int out_degree(vector<vector<int>> adj, int n, int node) {
    int out_deg = 0;
    if (!(is_direct_graph(adj, n)) || node >= n) {
        return -1;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j == node) {
                if (adj[i][j] != 0) {
                    out_deg++;
                }
            }
        }
    }
    
    return out_deg; 
}

int get_edge(vector<vector<int>> adj, int n) {
    int edge_sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (adj[i][j] != 0) {
                edge_sum++; 
            }
        }    
    }

    return edge_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> adj = make_graph(n);
    //print_graph(adj, n);

    cout << ((is_direct_graph(adj, n) == true) ? "YES" : "NO") << endl;
    cout << (degree(adj, n, 2)) << endl;
    cout << (degree(adj, n, 0)) << endl;
    
    cout << (in_degree(adj, n, 2)) << endl;
    cout << (in_degree(adj, n, 0)) << endl;

    cout << (out_degree(adj, n, 2)) << endl;
    cout << (out_degree(adj, n, 0)) << endl;
    
    cout << (get_edge(adj, n)) << endl;

    return 0;
}
