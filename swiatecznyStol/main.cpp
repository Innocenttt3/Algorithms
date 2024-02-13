#include <iostream>
#include <vector>
#include <cmath>

struct Dish {
    std::string name;
    long long kcal;
};


void countSort(std::vector<Dish>& dishes, long long n, int exp) {
    const int range = 10;
    int count[range] = {0};

    for (int i = 0; i < n; i++) {
        count[(dishes[i].kcal / exp) % range]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    std::vector<Dish> output(n);

    for (long long i = n - 1; i >= 0; i--) {
        output[count[(dishes[i].kcal / exp) % range] - 1] = dishes[i];
        count[(dishes[i].kcal / exp) % range]--;
    }
    dishes = output;

}


void radixSort(std::vector<Dish>&dishes, long long n) {
    long long maxKcal = 0;
    for (const auto& dish : dishes) {
        if (dish.kcal > maxKcal) {
            maxKcal = dish.kcal;
        }
    }

    int maxDigits = 0;
    while (maxKcal > 0) {
        maxKcal /= 10;
        maxDigits++;
    }
    for (int exp = 1; maxDigits > 0; exp *= 10, maxDigits--) {
        countSort(dishes, n, exp);
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long amountOfData;
    std::cin >> amountOfData;
    std::vector<Dish> dishes(amountOfData);
    for(long long i = 0; i < amountOfData; i++) {
        std::cin >> dishes[i].name >> dishes[i].kcal;
    }
    radixSort(dishes, amountOfData);
    for(auto & dishe : dishes) {
        std::cout << dishe.name << " ";
    }
    return 0;
}
