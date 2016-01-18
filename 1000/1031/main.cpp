#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int INF = 999999;
int G[201][201];
int dis[201];
bool is_visited[201];
string src, dst;
int road_length;

int dijkstra(int src, int dst) {
    memset(is_visited, 0, sizeof(is_visited));
    for (int i = 0; i < 201; i++) {
        if (i == src) dis[i] = 0;
        else dis[i] = INF;
    }

    for (int i = 0; i < 201; i++) {
        int min_load = INF;
        int current_place = src;
        for (int j = 0; j < 201; j++) {
            if (dis[j] < min_load && !is_visited[j]) {
                min_load = dis[j];
                current_place = j;
            }
        }
        is_visited[current_place] = true;
        for (int j = 0; j < 201; j++) {
            dis[j] = min(dis[j], dis[current_place] + G[j][current_place]);
        }

        if (is_visited[dst]) return dis[dst];
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int N, n;
    cin >> N;
    while (N--) {
        for(int i = 0; i < 201; ++i) {
            for(int j = 0; j < 201; ++j) {
                if (i != j) G[i][j] = INF;
                else G[i][j] = 0;
            }
        }
        map<string, int> edge_map;
        cin >> n;
        int place_size = 0;
        for (int i = 0; i < n; i++) {
            cin >> src >> dst >> road_length;
            if (!edge_map.count(src)) edge_map[src] = place_size++;
            if (!edge_map.count(dst)) edge_map[dst] = place_size++;
            G[edge_map[src]][edge_map[dst]] = G[edge_map[dst]][edge_map[src]] = road_length;
        }

        cin >> src >> dst;
        if (src == dst) cout << 0 << endl;
        else if (!edge_map.count(src) || !edge_map.count(dst)) cout << -1 << endl;
        else cout << dijkstra(edge_map[src], edge_map[dst]) << endl;
    }
    return 0;
}