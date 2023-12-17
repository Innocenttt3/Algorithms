#include <iostream>

struct Point {
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point() {
    };
};

struct building {
    int x;
    building (int x) {this->x = x;}
};

std::vector<Point> findPoints(int x, int y, int n, int addX, int addY) {
    std::vector<Point> results;
    Point middle(n / 2, n / 2);

    std::cout << "weszlo" << std::endl;
    if (x >= middle.x && y >= middle.y) { //czwarta
        results.push_back(Point(middle.x - 1 + addX, middle.y - 1  + addY));
        results.push_back(Point(middle.x - 1 + addX, middle.y + addY));
        results.push_back(Point(middle.x + addX, middle.y - 1 + addY));
    }
    else if (x >= middle.x && y < middle.y) { //druga
        results.push_back(Point(middle.x - 1 + addX, middle.y - 1 + addY));
        results.push_back(Point(middle.x - 1 + addX, middle.y + addY));
        results.push_back(Point(middle.x + addX, middle.y + addY));
    }
    else if (x < middle.x && y < middle.y) { //pierwsza
        results.push_back(Point(middle.x + addX, middle.y - 1 + addY));
        results.push_back(Point(middle.x - 1 + addX, middle.y  + addY));
        results.push_back(Point(middle.x + addX, middle.y + addY));
    }
    else if (x < middle.x && y >= middle.y) { //trzecia
        results.push_back(Point(middle.x - 1 + addX, middle.y - 1 + addY));
        results.push_back(Point(middle.x + addX, middle.y - 1 + addY));
        results.push_back(Point(middle.x + addX, middle.y + addY));
    }
    return results;
}


int findPow(int liczba) {
    if (liczba <= 0 || (liczba & (liczba - 1)) != 0) {
        return -1;
    }

    int potega = 0;
    while (liczba > 1) {
        liczba /= 2;
        potega++;
    }

    return potega;
}

int fillBoard(int boardSize, Point&L, int preAdded) {
    if(boardSize == 1) {
        return 0;
    }
    std::vector<Point> main = findPoints(L.x, L.y, boardSize, 0, 0);
    for (int i = 0; i < 3; i++) {
        std::cout << main[i].x << " " << main[i].y << std::endl;
    }
    int boardSize2 = boardSize / 2;
    for (Point&tmpPoint: main) {
        std::cout << "nowy glowny: " << tmpPoint.x << " " << tmpPoint.y << std::endl;
        if (tmpPoint.x >= boardSize2 && tmpPoint.y >= boardSize2) { //czwarta
            std::vector<Point> fourth = findPoints(tmpPoint.x, tmpPoint.y, boardSize2, preAdded, preAdded);
            for(int i = 0; i < 3; i++){
                std::cout << fourth[i].x << " " << fourth[i].y << std::endl;
            }
        }
        else if (tmpPoint.x >= boardSize2 && tmpPoint.y < boardSize2) { //druga
            std::vector<Point> fourth = findPoints(tmpPoint.x, tmpPoint.y, boardSize2, preAdded, 0);
            for(int i = 0; i < 3; i++){
                std::cout << fourth[i].x << " " << fourth[i].y << std::endl;
            }
        }
        else if (tmpPoint.x < boardSize2 && tmpPoint.y < boardSize2) { //pierwsza
            std::vector<Point> fourth = findPoints(tmpPoint.x, tmpPoint.y, boardSize2, 0, 0);
            for(int i = 0; i < 3; i++){
                std::cout << fourth[i].x << " " << fourth[i].y << std::endl;
            }
        }
        else if (tmpPoint.x < boardSize2 && tmpPoint.y >= boardSize2) { //trzecia
            std::vector<Point> fourth = findPoints(tmpPoint.x, tmpPoint.y, boardSize2, 0, preAdded);
            for(int i = 0; i < 3; i++){
                std::cout << fourth[i].x << " " << fourth[i].y << std::endl;
            }
        }
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int districtSize;
    int coorX;
    int coorY;
    std::cin >> districtSize >> coorX >> coorY;
    Point L = Point(coorX, coorY);
    fillBoard(districtSize, L, 2);

    return 0;
}
