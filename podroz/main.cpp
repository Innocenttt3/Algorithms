#include <iostream>
#include <string>

struct City {
    std::string nameOfCity;
    int valueNeeded;

    City() {
    };
};

void addToTree(std::string name, int value, int index, City arr[]) {
    int tmpValue;
    int parentIndex = 0;
    std::string tmpName;

    if (index % 2 == 0) {
        parentIndex = (index - 2) / 2;
    }
    else if (index % 2 == 1) {
        parentIndex = (index - 1) / 2;
    }

    if (index > 0) {
        if (value > arr[parentIndex].valueNeeded) {
            tmpValue = value;
            value = arr[parentIndex].valueNeeded;
            arr[index].valueNeeded = tmpValue;
            tmpName = name;
            name = arr[parentIndex].nameOfCity;
            arr[index].nameOfCity = tmpName;
        }
        else if (value == arr[parentIndex].valueNeeded && name > arr[parentIndex].nameOfCity) {
            tmpValue = value;
            value = arr[parentIndex].valueNeeded;
            arr[index].valueNeeded = tmpValue;
            tmpName = name;
            name = arr[parentIndex].nameOfCity;
            arr[index].nameOfCity = tmpName;
        }
        else {
            arr[index].nameOfCity = name;
            arr[index].valueNeeded = value;
        }
        addToTree(arr[parentIndex].nameOfCity, arr[parentIndex].valueNeeded, parentIndex, arr);
    }
    else if (index == 0) {
        arr[index].nameOfCity = name;
        arr[index].valueNeeded = value;
    }
    else {
        std::cout << "out of index" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int amountOfData;
    int tmpValue;
    std::string tmpName;
    std::cin >> amountOfData;
    City arr *[amountOfData];
    for (int i = 0; i < amountOfData; i++) {
        std::cin >> tmpName >> tmpValue;
        addToTree(tmpName, tmpValue, i, *arr);
    }

    return 0;
}
