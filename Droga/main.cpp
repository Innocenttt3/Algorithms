#include <iostream>
#include <vector>
#include <queue>

struct Point {
    int x;
    int y;
    char type;

    Point(int x, int y, char type) : x(x), y(y), type(type) {
    }

    Point() {
    }
};

struct Node {
    int distance;
    int mCount;

    Node(int dist, int count) : distance(dist), mCount(count) {
    }

    Node() {
    }
};

std::vector<Point> getNeighbours(int x, int y, const std::vector<Point>&points, int rows, int columns) {
    std::vector<Point> neighbours;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < rows && newY >= 0 && newY < columns && points[newX * columns + newY].type != '#') {
            neighbours.push_back(points[newX * columns + newY]);
        }
    }
    return neighbours;
}

void shortestPath(const std::vector<Point>&points, int rows, int columns, const Point&start, const Point&end) {
    std::vector<Node> distances(rows * columns, {1000000000, 0});
    distances[start.x * columns + start.y] = {0, 0};

    std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
    std::greater<>> pq;
    pq.push({0, {start.x, start.y}});

    while (!pq.empty()) {
        auto [dist, point] = pq.top();
        pq.pop();

        if (dist != distances[point.first * columns + point.second].distance) {
            continue;
        }

        for (auto neighbour: getNeighbours(point.first, point.second, points, rows, columns)) {
            int newDist = distances[point.first * columns + point.second].distance + 1;
            int newMCount = distances[point.first * columns + point.second].mCount + (neighbour.type == 'M' ? 1 : 0);

            if (newDist < distances[neighbour.x * columns + neighbour.y].distance || (
                    newDist == distances[neighbour.x * columns + neighbour.y].distance && newMCount < distances[
                        neighbour.x * columns + neighbour.y].mCount)) {
                distances[neighbour.x * columns + neighbour.y] = {newDist, newMCount};
                pq.push({newDist, {neighbour.x, neighbour.y}});
            }
        }
    }

    std::cout << distances[end.x * columns + end.y].distance << " " << distances[end.x * columns + end.y].mCount;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int rows, columns;
    std::cin >> rows >> columns;
    std::cin.ignore();

    Point start, end;
    std::vector<Point> points(rows * columns);

    for (int i = 0; i < rows; ++i) {
        std::string line;
        std::getline(std::cin, line);
        for (int y = 0; y < columns; ++y) {
            char pointType = line[y];
            points[i * columns + y] = {i, y, pointType};
            if (pointType == 'S') {
                start = {i, y, pointType};
            }
            else if (pointType == 'X') {
                end = {i, y, pointType};
            }
        }
    }

    shortestPath(points, rows, columns, start, end);

    return 0;
}
