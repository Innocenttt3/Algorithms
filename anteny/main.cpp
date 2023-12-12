#include <iostream>

std::pair<int, int> findSpot(int** arr, int startRow, int endRow, int clmns) {
    if (startRow == endRow) {

        int maxValue = -1;
        int maxX = -1;
        for (int i = 0; i < clmns; i++) {
            if (maxValue < arr[startRow][i]) {
                maxValue = arr[startRow][i];
                maxX = i;
            }
        }
        return {maxX, startRow};
    }

    int middleRow = (startRow + endRow) / 2;

    int maxValue = -1;
    int maxX = -1;
    for (int i = 0; i < clmns; i++) {
        if (maxValue < arr[middleRow][i]) {
            maxValue = arr[middleRow][i];
            maxX = i;
        }
    }
    if (middleRow > 0 && arr[middleRow - 1][maxX] >= maxValue) {
        return findSpot(arr, startRow, middleRow - 1, clmns);
    }
    if (middleRow < endRow && arr[middleRow + 1][maxX] >= maxValue) {
        return findSpot(arr, middleRow + 1, endRow, clmns);
    }
    return {maxX, middleRow};
}

int main() {
    int rows;
    int clmns;
    std::cin >> rows >> clmns;

    int** dynamicArray = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        dynamicArray[i] = new int[clmns];
    }

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < clmns; x++) {
            dynamicArray[y][x] = (clmns - 1 - x) * rows + y;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < clmns; j++) {
            std::cout << dynamicArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::pair<int, int> result = findSpot(dynamicArray, 0, rows - 1, clmns);

    std::cout << "Peak found at position: (" << result.first << ", " << result.second << ")" << std::endl;

    for (int i = 0; i < rows; ++i) {
        delete[] dynamicArray[i];
    }
    delete[] dynamicArray;

    return 0;
}
