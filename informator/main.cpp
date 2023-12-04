#include <iostream>


struct Point{

    int x;
    int y;
    bool visited;
    char type;

    Point(int x, int y) : x(x), y(y) {}
};

void BFS(std::vector<std::vector<Point>>& points, int rowsMax, int columnsMax, Point start, Point end){

    int distance = 0;
    int monitoredVisited = 0;




}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int rows, columns;
    char pointType;
    std::cin >> rows >> columns;
    Point* start;
    Point* end;
    std::vector<std::vector<Point>> points(rows, std::vector<Point>(columns));
    for (int i = 1; i <= rows; i++){
        for(int y = 1; y <= columns; y++){
            std::cin>>pointType;
            if(pointType == 'S') {
                 start = new Point(i, y);
            } else if (pointType == 'X'){
                end = new Point(i, y);
            }
            points[i][y].type = pointType;
            points[i][y].visited = false;
        }
    }
    std::cout << "punkt startowy:" << start->x << " " << start->y << std::endl;
    std::cout << "koncowy:" << start->x << " " << start->y << std::endl;
    return 0;
}
