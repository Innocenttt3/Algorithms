#include <iostream>
#include <vector>
#include <string>
struct Dish {
    std::string name;
    long long kcal;
};

std::vector<Dish> countSortMOD(std::vector<Dish>& inputArray) {
    int N = inputArray.size();

    long long M = 0;
    for (int i = 0; i < N; i++)
        M = std::max(M, inputArray[i].kcal % 10);

    std::vector<int> countArray(M + 1, 0);

    for (int i = 0; i < N; i++)
        countArray[inputArray[i].kcal % 10]++;

    for (long long i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    std::vector<Dish> outputArray(N);

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i].kcal % 10] - 1] = inputArray[i];
        countArray[inputArray[i].kcal % 10]--;
    }

    return outputArray;
}

std::vector<Dish> countSortDIV(std::vector<Dish>& inputArray) {
    int N = inputArray.size();

    long long M = 0;
    for (int i =  0; i < N; i++) {
        M = std::max(M, inputArray[i].kcal /  10);
    }

    std::vector<int> countArray(M +  1,  0);

    for (int i =  0; i < N; i++) {
        countArray[inputArray[i].kcal /  10]++;
    }

    for (long long i =  1; i <= M; i++) {
        countArray[i] += countArray[i -  1];
    }
    std::vector<Dish> outputArray(N);

    for (int i = N -  1; i >=  0; i--) {
        outputArray[countArray[inputArray[i].kcal /  10] -  1] = inputArray[i];
        countArray[inputArray[i].kcal /  10]--;
    }

    return outputArray;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int amountOfData;
    std::cin >> amountOfData;
    std::vector<Dish> dishes(amountOfData);
    std::vector<Dish> result(amountOfData);
    std::vector<Dish> result2(amountOfData);

    for (int i = 0; i < amountOfData; i++) {
        std::cin >> dishes[i].name >> dishes[i].kcal;
    }

    result = countSortMOD(dishes);
    result2 = countSortDIV(result);

    for (const Dish& dish : result2) {
        std::cout << dish.name << " ";
    }

    return 0;
}
