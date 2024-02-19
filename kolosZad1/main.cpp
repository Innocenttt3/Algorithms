#include <iostream>

struct Sensor {
    std::string id;
    signed int index;
    signed int value;
};


void countSortByValue(Sensor input[], Sensor result[], int size) {
    int* countArr;
    int countSize = 0;
    countArr = new int[51] {0};
    countSize = 51;

    for(int i = 0; i < size; i++) {
        countArr[input[i].value + 25]++;
    }

    for(int i = 0; i < countSize; i++) {
        countArr[i] += countArr[i - 1];
    }

    for(int i = size - 1; i >= 0; i--) {
        int value = 0;
        int index = 0;
        value = input[i].value + 25;
        index = size + 1 - countArr[value]; //sortowanie malejaco
        result[index - 1] = input[i];
        countArr[value]--;
    }

    delete[] countArr;
}

void countSortByIndex(Sensor input[], Sensor result[], int size) {
    int* countArr;
    int countSize = 0;
    countArr = new int[10] {0};
    countSize = 10;

    for(int i = 0; i < size; i++) {
        countArr[input[i].index]++;
    }

    for(int i = 0; i < countSize; i++) {
        countArr[i] += countArr[i - 1];
    }

    for(int i = size - 1; i >= 0; i--) {
        int value = 0;
        int index = 0;
        value = input[i].index;
        index = countArr[value];
        result[index - 1] = input[i];
        countArr[value]--;
    }

    delete[] countArr;
}

void countSortByLetters(Sensor input[], Sensor result[], int size, int which) {
    int* countArr;
    int countSize = 0;
    countArr = new int[26] {0};
    countSize = 26;

    for(int i = 0; i < size; i++) {
        countArr[input[i].id[which] - 65]++;
    }

    for(int i = 0; i < countSize; i++) {
        countArr[i] += countArr[i - 1];
    }

    for(int i = size - 1; i >= 0; i--) {
        int value = 0;
        int index = 0;
        value = input[i].id[which] - 65;
        index = countArr[value];
        result[index - 1] = input[i];
        countArr[value]--;
    }

    delete[] countArr;
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Sensor* sensors = new Sensor[n];
    Sensor* result = new Sensor[n];
    for(int i = 0; i < n; i++) {
        std::cin >> sensors[i].id >> sensors[i].index >> sensors[i].value;
    }

    countSortByValue(sensors, result, n);
    countSortByIndex(result, sensors, n);
    countSortByLetters(sensors, result, n, 1);
    countSortByLetters(result, sensors, n, 0);

    long sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += sensors[i].value * i;
    }
    std::cout << sum << '\n';

    delete[] sensors;
    delete[] result;
    return 0;
}
