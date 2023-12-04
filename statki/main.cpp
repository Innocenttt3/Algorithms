#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Ship {
    vector<pair<int, int>> connections;
};

int main() {
    int dataSets;
    cin >> dataSets;
    while (dataSets--) {
        int shipsAmount, teleportsAvailable, spockLocation;
        cin >> shipsAmount >> teleportsAvailable >> spockLocation;
        vector<Ship> ships(shipsAmount);
        for (int i = 0; i < teleportsAvailable; i++) {
            int ship1, ship2, travelTime;
            cin >> ship1 >> ship2 >> travelTime;
            ships[ship1].connections.push_back({ship2, travelTime});
            ships[ship2].connections.push_back({ship1, travelTime});
        }
        vector<int> blockedUntil(shipsAmount, 0);
        for (int i = 0; i < shipsAmount; i++) {
            int amount;
            cin >> amount;
            for (int j = 0; j < amount; j++) {
                int time;
                cin >> time;
                blockedUntil[i] = max(blockedUntil[i], time);
            }
        }
        vector<int> dist(shipsAmount, 2e9);
        dist[spockLocation] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, spockLocation});
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d != dist[u]) continue;
            for (auto &v : ships[u].connections) {
                if (dist[u] + v.second + blockedUntil[v.first] < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second + blockedUntil[v.first];
                    pq.push({dist[v.first], v.first});
                }
            }
        }
        cout << dist[0] << '\n';
    }
    return 0;
}
