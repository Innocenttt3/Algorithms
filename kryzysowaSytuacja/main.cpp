#include <iostream>

struct Box {
    int index;
    int sumValue;
    int* values;

    Box(int index, int sumValue, int* values)
        : index(index), sumValue(sumValue), values(values) {}

    Box() {}
};

void countSort(Box* inputArray, int N) {

    int maxSumValue = 0;
    for (int i = 0; i < N; ++i)
        maxSumValue = std::max(maxSumValue, inputArray[i].sumValue);

    int* countArray = new int[maxSumValue + 1]{0};

    for (int i = 0; i < N; ++i)
        countArray[inputArray[i].sumValue]++;

    for (int i = maxSumValue - 1; i >= 0; --i)
        countArray[i] += countArray[i + 1];

    Box* outputArray = new Box[N];

    for (int i = N - 1; i >= 0; --i) {
        int pos = countArray[inputArray[i].sumValue]--;
        outputArray[pos - 1] = inputArray[i];
    }

    for (int i = 0; i < N; ++i)
        inputArray[i] = outputArray[i];

    delete[] countArray;
    delete[] outputArray;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int packagesAmount;
    int bottlesAmount;
    int maxCapacity;
    double tmpValueToSum;

    std::cin >> packagesAmount >> bottlesAmount >> maxCapacity;

    Box* arrOfBoxes = new Box[packagesAmount];

    for (int i = 0; i < packagesAmount; i++) {
        int* arrOfValues = new int[bottlesAmount];
        int tmpValueTotal = 0;
        for (int j = 0; j < bottlesAmount; j++) {
            std::cin >> tmpValueToSum;
            arrOfValues[j] = 1000 * tmpValueToSum;
            tmpValueTotal += arrOfValues[j];
        }
        arrOfBoxes[i] = Box(i, tmpValueTotal, arrOfValues);
    }

    countSort(arrOfBoxes, packagesAmount);

    for(int i = 0; i < maxCapacity; i++) {
        for(int j = 0; j < bottlesAmount; j++) {
            std::cout << (double)arrOfBoxes[i].values[j] / 1000  << " ";
        }
        std::cout << std::endl;
    }

    delete[] arrOfBoxes;
    return 0;
}