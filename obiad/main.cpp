#include <iostream>
#include <algorithm>

bool compareDescending(int a, int b) {
    return a > b;
}

void findSolutions(int caloriesLimit, int products[], int currentCalories, int index, int& solutions, int maxIndex) {
    if (currentCalories > caloriesLimit || index > maxIndex) {
        return;
    }
    if (currentCalories == caloriesLimit) {
        solutions++;
        return;
    }
    if (currentCalories + products[index] <= caloriesLimit) {
        findSolutions(caloriesLimit, products, currentCalories + products[index], index + 1, solutions, maxIndex);
    }
    findSolutions(caloriesLimit, products, currentCalories, index + 1, solutions, maxIndex);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int testAmount;
    int productsAmount;
    int tmpCalories;
    int caloriesLimit;
    std::cin >> testAmount;
    for (int i = 0; i < testAmount; i++) {
        std::cin >> productsAmount;
        int* foodProducts = new int[productsAmount];
        for (int j = 0; j < productsAmount; j++) {
            std::cin >> tmpCalories;
            foodProducts[j] = tmpCalories;
        }

        std::sort(foodProducts, foodProducts + productsAmount, compareDescending);

        std::cin >> caloriesLimit;
        int solutions = 0;
        findSolutions(caloriesLimit, foodProducts, 0, 0, solutions, productsAmount);
        std::cout << solutions << '\n';
    }
}