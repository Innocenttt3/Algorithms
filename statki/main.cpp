#include <iostream>
#include <queue>
#include <vector>

struct Connection {
    int travelTime;
    int destinationShipId;

    Connection(int shipID, int travelTime) : travelTime(travelTime), destinationShipId(shipID) {}
};

struct Ship {
    bool visited;
    int id;
    std::vector<Connection> connectedShips;
    std::vector<int> secondsToStop;
};

void Dijkstra(std::vector<Ship>& ships,int startShipId, int endShipId) {
    std::vector distances(ships.size(), 2147483647);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;
    queue.push({0, startShipId});
    distances[startShipId] = 0;

    while (!queue.empty()) {
        int currentShipId = queue.top().second;
        queue.pop();

        if (ships[currentShipId].visited) continue;
        ships[currentShipId].visited = true;

        if (currentShipId == endShipId) break;

        int tmpTravel = 0;

        for (int tmpShip : ships[0].secondsToStop) {
            if(tmpShip == 1) {
                tmpTravel++;
            }
        }
        for (Connection& connection : ships[currentShipId].connectedShips) {
            int destinationShipId = connection.destinationShipId;
            int travelTime = connection.travelTime;
            int newDistance = distances[currentShipId] + travelTime;

            for (int stopTime : ships[destinationShipId].secondsToStop) {
                if (newDistance == stopTime) {
                    newDistance++;
                }
            }

            if (newDistance < distances[destinationShipId]) {
                distances[destinationShipId] = newDistance;
                queue.push({newDistance, destinationShipId});
            }
        }
    }

    std::cout << distances[endShipId] << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int dataSets;
    int shipsAmount;
    int teleportsAvailable;
    int spockLocation;
    int amount;

    int tmpShip1id, tmpShip2id;
    int tmpTravelTime;

    std::cin >> dataSets;
    for (int y = 0; y < dataSets; y++) {
        std::cin >> shipsAmount >> teleportsAvailable >> spockLocation;
        std::vector<Ship> ships(shipsAmount);
        for (int i = 0; i < teleportsAvailable; i++) {
            std::cin >> tmpShip1id >> tmpShip2id >> tmpTravelTime;
            ships[tmpShip1id].connectedShips.push_back(Connection(tmpShip2id, tmpTravelTime));
            ships[tmpShip2id].connectedShips.push_back(Connection(tmpShip1id, tmpTravelTime));
            ships[tmpShip1id].id = tmpShip1id;
        }
        for (int j = 0; j < shipsAmount; j++) {
            std::cin >> amount;
            for (int x = 0; x < amount; x++) {
                int num;
                std::cin >> num;
                ships[j].secondsToStop.push_back(num);
            }
        }
        Dijkstra(ships, spockLocation, 0);
    }

    return 0;
}