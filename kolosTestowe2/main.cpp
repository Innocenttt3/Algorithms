#include <deque>
#include <iostream>
#include <climits>
#include <vector>
#include <string>

struct Point {
    std::vector<std::pair<int, int>> neighbours;
    int cost;
    int totalCost;
    bool visited;
    bool desired;

    Point() {
        visited = false;
        desired = false;
        totalCost = INT_MAX;
    }
};

void BFS(int startIndex, std::vector<Point>&points) {
    std::deque<Point *> pointsQueue;
    points[startIndex].visited = true;
    points[startIndex].totalCost = 0;
    pointsQueue.push_back(&points[startIndex]);
    while (!pointsQueue.empty()) {
        Point* currentPoint = pointsQueue.front();
        pointsQueue.pop_front();
        currentPoint->visited = true;
        for (auto neighbour: currentPoint->neighbours) {
            if (!points[neighbour.first].visited) {
                pointsQueue.push_back(&points[neighbour.first]);
            }
            if (points[neighbour.first].totalCost == INT_MAX || points[neighbour.first].totalCost > currentPoint->
                totalCost + neighbour.second + points[neighbour.first].cost) {
                points[neighbour.first].totalCost =
                        currentPoint->totalCost + neighbour.second + points[neighbour.first].cost;
            }
        }
    }
}

void printResults(std::vector<Point>&points, std::vector<int>&index) {
    for(auto& tmpIndex: index) {
        std::string tmp = points[tmpIndex].totalCost == INT_MAX? "NIE": std::to_string(points[tmpIndex].totalCost);
        std::cout << tmp << std::endl;
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int amountOfVertices;
    int amountOfEdges;
    int tmpStart;
    int tmpDestination;
    int distance;
    int entryCost;
    int amountOfFinalDestinations;
    int startPoint;
    std::cin >> amountOfVertices >> amountOfEdges;
    std::vector<Point> points(amountOfVertices);
    for (int i = 0; i < amountOfEdges; i++) {
        std::cin >> tmpStart >> tmpDestination >> distance;
        points[tmpStart].neighbours.push_back(std::make_pair(tmpDestination, distance));
    }
    for (int i = 0; i < amountOfVertices; i++) {
        std::cin >> entryCost;
        points[i].cost = entryCost;
    }
    int index;
    std::cin >> amountOfFinalDestinations;
    std::vector<int> desiredIndexes;
    for (int i = 0; i < amountOfFinalDestinations; i++) {
        std::cin >> index;
        if(index < amountOfVertices) {
            desiredIndexes.push_back(index);
        }
    }
    std::cin >> startPoint;
    BFS(startPoint, points);
    printResults(points, desiredIndexes);
    return 0;
}
