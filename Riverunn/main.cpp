#include <iostream>
#include <queue>

struct Castle {
    int id;
    int distance;
    bool visited;
    std::vector<int> connectedCastle;
    Castle() : distance(0), visited(false) {}
};

void BFS(Castle &castle, int maxDays, std::vector<Castle> &castles) {
    int maxDistance = 0;
    int willCastleMakeIt = 0;
    std::deque<Castle *> castlesQueue;
    castle.visited = true;
    castle.distance = 0;
    castlesQueue.push_back(&castle);
    while (!castlesQueue.empty()) {
        Castle* currentCastle = castlesQueue.front();
        castlesQueue.pop_front();
        for (int connectedCastleId : currentCastle->connectedCastle) {
            Castle &connectedCastle = castles[connectedCastleId];
            if (!connectedCastle.visited) {
                castlesQueue.push_back(&connectedCastle);
                connectedCastle.distance = currentCastle->distance + 1;
                connectedCastle.visited = true;
                maxDistance = std::max(maxDistance, connectedCastle.distance);
                if (connectedCastle.distance*2 <= maxDays) {
                    willCastleMakeIt++;
                }
            }
        }
    }
    std::cout << maxDistance << " " << willCastleMakeIt;
}




int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int castlesAmount, streetsAmount, attackedCastle, daysNeeded;
    std::cin >> castlesAmount >> streetsAmount >> attackedCastle >> daysNeeded;
    std::vector<Castle> castles(castlesAmount);
    for (int i = 0; i < castlesAmount; i++) {
        castles[i].id = i;
    }
    int con1, con2;
    for (int i = 0; i < streetsAmount; i++) {
        std::cin >> con1 >> con2;
        castles[con1].connectedCastle.push_back(con2);
        castles[con2].connectedCastle.push_back(con1);
    }
    BFS(castles[attackedCastle], daysNeeded, castles);

    return 0;
}

