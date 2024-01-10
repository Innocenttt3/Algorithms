#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int packagesAmount;
    int bottlesAmount;
    int maxCapacity;
    float tmpValue;
    std::cin >> packagesAmount >> bottlesAmount >> maxCapacity;
    int** arr = new int *[packagesAmount];

    for (int i = 0; i < bottlesAmount; ++i) {
        arr[i] = new int[bottlesAmount];
    }

    for (int i = 0; i < packagesAmount; i++) {
        for (int j = 0; j < bottlesAmount; j++) {
            std::cin >> tmpValue;
            tmpValue *= 100;
            arr[packagesAmount][bottlesAmount] = tmpValue;
            std::cout << arr[packagesAmount][bottlesAmount] << std::endl;
        }
    }
    //verify
    int arrToSort[1000];
    for (int i = 0; i < 1000; i++) {
        arrToSort[i] = 0;
        int tmpIndex = 0;
        for (int j = 0; j < bottlesAmount; j++) {
            if (i == arr[0][bottlesAmount]) {
                tmpIndex++;
            }
        }
        arrToSort[i] = tmpIndex;
    }
    for (int i = 0; i < 1000; i++) {
        if (arrToSort[i] != 0) {
            std::cout << arrToSort[i] << std::endl;
        }
    }
    //to do
    for (int i = 0; i < packagesAmount; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
