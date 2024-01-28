#include <iostream>
#include <string>

struct City {
    std::string nameOfCity;
    long int valueNeeded;

    City() {}
};


void addToTree(std::string name, long int value, long int index, City arrOfCities[]) {
    arrOfCities[index].nameOfCity = name;
    arrOfCities[index].valueNeeded = value;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (arrOfCities[parentIndex].valueNeeded < arrOfCities[index].valueNeeded) {
            City temp = arrOfCities[parentIndex];
            arrOfCities[parentIndex] = arrOfCities[index];
            arrOfCities[index] = temp;
            index = parentIndex;
        } else {
            break;
        }
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long int amountOfData;
    long int maxValue;

    std::cin >> amountOfData;
    City* arrOfCities = new City[amountOfData];

    for (long int i = 0; i < amountOfData; ++i) {
        std::string tmpName;
        long int tmpValue;
        std::cin >> tmpName >> tmpValue;
        addToTree(tmpName, tmpValue, i, arrOfCities);
    }

    std::cin >> maxValue;

    for (long int i = 0; i < amountOfData; ++i) {
        if (maxValue > arrOfCities[i].valueNeeded) {
            maxValue -= arrOfCities[i].valueNeeded;
            std::cout << arrOfCities[i].nameOfCity << " ";
        }
    }

    delete[] arrOfCities;
    return 0;
}
