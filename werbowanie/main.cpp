#include <iostream>
#include <string>

struct People {
    std::string name;
    long long time;
};

void insertionSort(People arr[], int n)
{
    int i, j;
    People key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while ((j >= 0 && arr[j].time < key.time) || (j >= 0 && arr[j].time == key.time && arr[j].name > key.name)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

long long timeTakerCalc(People arr[], int size, int sizeOUT) {
    long long resultTime = 0;
    insertionSort(arr, size);
    for (int y = 0; y < sizeOUT; y++){
        std::cout << arr[y].name << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            resultTime += 1;
        } else {
            resultTime += (arr[i].time * i) + 1;
        }
    }
    return resultTime % 1000003;
}

int main() {

    int setsOfData;
    int amountIN, amountOUT;

    std::cin >> setsOfData;

    for(int i = 0; i < setsOfData; i++){
    std::cin >> amountIN >> amountOUT;
    People *tmpPeople = new People[amountIN];
    for (int j = 0; j < amountIN; j++) {
        std::cin >> tmpPeople[j].name >> tmpPeople[j].time;
    }
    std::cout << timeTakerCalc(tmpPeople, amountIN, amountOUT);
    std::cout << std::endl;
    delete[] tmpPeople;
    }
    return 0;
}
