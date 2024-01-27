#include <iostream>


struct Box {
    int index;
    int sumValue;
    int* values;
    bool printed;

    Box(int index, int sumValue, int* values, bool printed)
        : index(index), sumValue(sumValue), values(values), printed(printed) {
    }

    Box() {
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int packagesAmount;
    int bottlesAmount;
    int maxCapacity;
    float tmpValueToSum;
    int displayedAmount = 0;

    std::cin >> packagesAmount >> bottlesAmount >> maxCapacity;
    int sizeOfArrToSort = 1000 * bottlesAmount;

    Box* arrOfBoxes = new Box[packagesAmount];

    int* arrToSort = new int[sizeOfArrToSort];
    for (int i = 0; i < sizeOfArrToSort; i++) {
        arrToSort[i] = 0;
    }
    for (int i = 0; i < packagesAmount; i++) {
        int* arrOfValues = new int[bottlesAmount];
        int tmpValueTotal = 0;
        for (int j = 0; j < bottlesAmount; j++) {
            std::cin >> tmpValueToSum;
            arrOfValues[j] = 1000 * tmpValueToSum;
            tmpValueTotal += arrOfValues[j];
        }
        arrOfBoxes[i] = Box(i, tmpValueTotal, arrOfValues, false);
    }
    for (int i = 0; i < packagesAmount; i++) {
        arrToSort[arrOfBoxes[i].sumValue]++;
    }
    for (int i = sizeOfArrToSort; i >= 0; i--) {
        while (arrToSort[i] > 0 && maxCapacity > 0) {
            for (int j = 0; j < packagesAmount; j++) {
                if (arrOfBoxes[j].sumValue == i) {
                    for (int x = 0; x < bottlesAmount; x++) {
                        std::cout << (float)arrOfBoxes[j].values[x] / 1000 << " ";
                    }
                    std::cout << std::endl;
                    arrOfBoxes[j].sumValue = -1;
                    maxCapacity--;

                    std::cout << maxCapacity << std::endl;
                }
            }
            arrToSort[i]--;
        }
    }


    delete[] arrToSort;
    delete[] arrOfBoxes;
    /*
    6 5 3
    1 0 0.6 0.8 1
    1 1 1 1 1
    0 0 0 0 0.1
    0.5 0.5 0.5 0.5 0
    0.8 0.7 0.6 0.5 0.4
    0.4 0.5 0.6 0.7 0.8
    */

    return 0;
}
