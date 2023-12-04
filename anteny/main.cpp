#include <iostream>


std::pair<int, int> findSpot(int** arr, int coorX, int coorY, int startRow, int endRow, int clmns, int rowsAmount) {
    int maxCoorX;
    int maxCoorY;
    int tmpMaxValue = 0;
    int middleRow = (endRow - startRow) / 2;
    if (endRow - startRow == 1) {
        return {coorX, coorY};
    }
    for (int i = 0; i < clmns; i++) {
        if (arr[middleRow][i] > tmpMaxValue) {
            tmpMaxValue = arr[middleRow][i];
            maxCoorX = middleRow;
            maxCoorY = i;
        }
    }
    std::cout << tmpMaxValue << "<- maks wartosc z rzedu: " << middleRow << std::endl;
    if (middleRow + 1 < rowsAmount && middleRow - 1 >= 0) {
        if (arr[middleRow + 1][maxCoorY] >= tmpMaxValue) {
            int newStartRows = middleRow + 1;
            findSpot(arr, maxCoorX, maxCoorY, newStartRows, endRow, clmns, rowsAmount);
        }
        else if (arr[middleRow - 1][maxCoorY] >= tmpMaxValue) {
            findSpot(arr, maxCoorX, maxCoorY, 0, middleRow, clmns, rowsAmount);
        }
    }

}

void displayArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int i, j;
    std::cin >> i >> j;
    int** dynamicArray = new int *[i];
    for (int y = 0; y < i; ++y) {
        dynamicArray[y] = new int[j];
    }

    for (int x = 0; x < i; ++x) {
        for (int y = 0; y < j; ++y) {
            dynamicArray[x][y] = x * j + y;
        }
    }
    displayArray(dynamicArray, i, j);

    std::pair<int, int> result = findSpot(dynamicArray, 0, 0, 0, i, j);
    std::cout << result.first << " " << result.second;

    for (int x = 0; x < i; ++x) {
        delete[] dynamicArray[x];
    }
    delete[] dynamicArray;
    return 0;
}
