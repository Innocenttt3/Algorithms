#include <deque>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Point {
    vector<pair<int, int>> neighbours;
    int cost = INT_MAX;
    int totalCost = INT_MAX;
    bool visited = false;
    bool desired;
};

struct ComparePoints {
    bool operator()(Point* left, Point* right) {
        return left->totalCost > right->totalCost;
    }
};

void BFS(int startIndex, vector<Point>& points) {
    priority_queue<Point *, vector<Point *>, ComparePoints> pointsQueue;
    points[startIndex].visited = true;
    points[startIndex].totalCost = 0;
    pointsQueue.push(&points[startIndex]);
    while (!pointsQueue.empty()) {
        Point* currentPoint = pointsQueue.top();
        pointsQueue.pop();
        currentPoint->visited = true;
        for (auto neighbour : currentPoint->neighbours) {
            if (!points[neighbour.first].visited) {
                int value = currentPoint->totalCost + neighbour.second + points[neighbour.first].cost;
                if (value < points[neighbour.first].totalCost) {
                    points[neighbour.first].totalCost = value;
                    pointsQueue.push(&points[neighbour.first]);
                }
            }
        }
    }
}

void printResults(vector<Point>& points, vector<int>& index) {
    for (auto& tmpIndex : index) {
        string tmp = points[tmpIndex].totalCost == INT_MAX ? "NIE" : to_string(points[tmpIndex].totalCost);
        cout << tmp << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int amountOfVertices, amountOfEdges;
    cin >> amountOfVertices >> amountOfEdges;
    vector<Point> points(amountOfVertices);

    int tmpStart;
    int tmpDestination;
    int distance;
    int entryCost;
    int amountOfFinalDestinations;
    int startPoint;

    for (int i = 0; i < amountOfEdges; i++) {
        cin >> tmpStart >> tmpDestination >> distance;
        if (tmpStart < amountOfVertices && tmpDestination < amountOfVertices) {
            points[tmpStart].neighbours.emplace_back(tmpDestination, distance);
        }
    }
    for (int i = 0; i < amountOfVertices; i++) {
        cin >> entryCost;
        points[i].cost = entryCost;
    }
    int index;
    cin >> amountOfFinalDestinations;
    vector<int> desiredIndexes;
    for (int i = 0; i < amountOfFinalDestinations; i++) {
        cin >> index;
        if (index < amountOfVertices) {
            desiredIndexes.push_back(index);
        }
    }
    cin >> startPoint;
    BFS(startPoint, points);
    printResults(points, desiredIndexes);
    return 0;
}
