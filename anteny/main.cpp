#include <iostream>

std::pair<int, int> findSpot(int startRow, int endRow, int clmns, double (*P)(int, int)) {
    if (startRow == endRow) {
        double maxValue = -1;
        int maxX = -1;
        for (int i = 0; i < clmns; i++) {
            double height = P(startRow, i);
            if (maxValue < height) {
                maxValue = height;
                maxX = i;
            }
        }
        return {maxX, startRow};
    }

    int middleRow = (startRow + endRow) / 2;
    double maxValue = -1;
    int maxX = -1;
    for (int i = 0; i < clmns; i++) {
        double height = P(middleRow, i);
        if (maxValue < height) {
            maxValue = height;
            maxX = i;
        }
    }
    if ( P(middleRow - 1, maxX) > maxValue) {
        return findSpot(startRow, middleRow - 1, clmns, P);
    }
    if ( P(middleRow + 1, maxX) > maxValue) {
        return findSpot(middleRow + 1, endRow, clmns, P);
    }
    return {maxX, middleRow};
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int rows;
    int clmns;
    std::cin >> rows >> clmns;

    std::pair<int, int> result = findSpot(1, rows - 1, clmns, P);
    int peakHeight = P(result.second, result.first);
    std::cout << peakHeight;
    return 0;
}