#include <iostream>
#include <string>

struct Dish {
    std::string name;
    long long kcal;
};

void countSortMOD(Dish inputArray[], int size) {
    long long M = 0;
    for (int i = 0; i < size; i++)
        M = std::max(M, inputArray[i].kcal % size);

    int countArray[M + 1];
    for(int i = 0; i < M + 1; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < size; i++)
        countArray[inputArray[i].kcal % size]++;

    for (long long i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    Dish outputArray[size];

    for (int i = size - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i].kcal % size] - 1] = inputArray[i];
        countArray[inputArray[i].kcal % size]--;
    }

    for (int i = 0; i < size; i++) {
        inputArray[i] = outputArray[i];
    }
}

void countSortDIV(Dish inputArray[], int size) {
    long long M = 0;
    for (int i = 0; i < size; i++)
        M = std::max(M, inputArray[i].kcal / size);

    int countArray[M + 1];
    for(int i = 0; i < M + 1; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < size; i++)
        countArray[inputArray[i].kcal / size]++;

    for (long long i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    Dish outputArray[size];

    for (int i = size - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i].kcal / size] - 1] = inputArray[i];
        countArray[inputArray[i].kcal / size]--;
    }

    for (int i = 0; i < size; i++) {
        inputArray[i] = outputArray[i];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int amountOfData;
    std::cin >> amountOfData;
    Dish *dishes = new Dish[amountOfData];

    for (int i = 0; i < amountOfData; i++) {
        std::cin >> dishes[i].name >> dishes[i].kcal;
    }

    countSortMOD(dishes, amountOfData);
    countSortDIV(dishes, amountOfData);

    for(int i = 0; i < amountOfData; i++) {
        std::cout << dishes[i].name << " ";
    }

    delete[] dishes;

    return 0;
}
