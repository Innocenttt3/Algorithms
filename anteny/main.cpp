#include <iostream>


double P(int i, int j) {
    double result = 30 - std::sqrt(std::pow(i - 5, 2) + std::pow(j - 5, 2));
    return result;
}

std::pair<int, int>findPoint(int rows, int cols, int** arr, int maxCoorX, int maxCoorY) {
    int maxValue = -1;
    if(rows >= cols) {
        int newRows = rows / 2;
        int newMaxValue = maxValue;
        for ( int i = 0; i < cols; i++) {
            if (newMaxValue < arr[newRows][i]) {
                newMaxValue = arr[newRows][i];
                maxCoorX = newRows;
                maxCoorY = i;
            }
        }
        if (arr[maxCoorX + 1][maxCoorY] > arr[maxCoorX][maxCoorY]) {
            findPoint(rows - maxCoorX + 1, cols, arr, maxCoorX, maxCoorY);
        } else if (arr[maxCoorX - 1][maxCoorY] > arr[maxCoorX][maxCoorY]) {
            findPoint(rows - maxCoorX - 1, cols, arr, maxCoorX, maxCoorY);
        }
    } else if (rows < cols) {

    } else if ( rows == 1 && cols == 1) {
        return std::make_pair(maxCoorX, maxCoorY);
    }

}

int main() {
    int i, j;
    int** dynamicArray = new int *[i];
    for (int y = 0; y < i; ++y) {
        dynamicArray[y] = new int[j];
    }

    findPoint(i, j, dynamicArray);


    for (int x = 0; x < i; ++x) {
        delete[] dynamicArray[x];
    }
    delete[] dynamicArray;
    return 0;
}
