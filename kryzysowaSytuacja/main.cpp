#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int packagesAmount;
    int bottlesAmount;
    int maxCapacity;
    float tmpValue;

    int arrToSort[1001];
    int tmpIndex;
    int sortedArrSum;
    std::cin >> packagesAmount >> bottlesAmount >> maxCapacity;

    // Array to store the boxes
    int** arr = new int *[packagesAmount];
    for (int i = 0; i < packagesAmount; ++i) {
        arr[i] = new int[bottlesAmount];
    }

    // Array to store the fill percentages
    float* fillPercentage = new float[packagesAmount];

    // Read the boxes
    for (int i = 0; i < packagesAmount; i++) {
        float total = 0;
        for (int j = 0; j < bottlesAmount; j++) {
            std::cin >> tmpValue;
            tmpValue *= 1000;
            arr[i][j] = tmpValue;
            total += tmpValue;
        }
        fillPercentage[i] = total / (float)(bottlesAmount * maxCapacity);
    }

    // Sort the boxes based on the fill percentages
    for (int i = 0; i < packagesAmount - 1; i++) {
        for (int j = i + 1; j < packagesAmount; j++) {
            if (fillPercentage[i] < fillPercentage[j]) {
                // Swap fillPercentage[i] and fillPercentage[j]
                float temp = fillPercentage[i];
                fillPercentage[i] = fillPercentage[j];
                fillPercentage[j] = temp;

                // Also swap the corresponding boxes
                int* tempBox = arr[i];
                arr[i] = arr[j];
                arr[j] = tempBox;
            }
        }
    }

    // Print the boxes
    for (int i = 0; i < maxCapacity; i++) {
        for( int j = 0; j < bottlesAmount; j++) {
            std::cout << arr[i][j] / 1000.0 << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < packagesAmount; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] fillPercentage;

    return 0;
}


/*
6 5 3
1 0 0.6 0.8 1
1 1 1 1 1
0 0 0 0 0.1
0.5 0.5 0.5 0.5 0
0.8 0.7 0.6 0.5 0.4
0.4 0.5 0.6 0.7 0.8
*/
