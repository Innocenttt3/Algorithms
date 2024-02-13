#include <iostream>
#include <vector>
#include <cmath>

struct Dish {
    std::string name;
    int kcal;

};

void countSort(std::vector<Dish> &dishes, int size) {
    int maxKcal = pow(size, 2) - 1 ;

    std::vector<int> countArr(maxKcal, 0);

    for (int i = 0; i < size; i++) {
        countArr[dishes[i].kcal]++;
    }

    for (int i = 1; i <= maxKcal; i++) {
        countArr[i] += countArr[i - 1];
    }

}



int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int amountOfData;
    std::cin >> amountOfData;
    std::vector<Dish> dishes(amountOfData);
    int i = 0;
    while(i < amountOfData) {
        std::cin >> dishes[i].name >> dishes[i].kcal;
        i++;
    }
    countSort(dishes, amountOfData);
    return 0;
}