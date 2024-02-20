#include <iostream>
#include <string>
#include <vector>


struct Person{
    int values[4];
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int amountOfPeople, amountOfFirstGeneration;
    std::cin >> amountOfPeople >> amountOfFirstGeneration;

    Person arr[1500];

    std::vector<std::string> surnames(amountOfFirstGeneration);
    for (int i = 0; i < amountOfFirstGeneration; i++) {
        std::cin >> surnames[i];
        arr[i].values[0] = i;
        arr[i].values[1] = i;
        arr[i].values[2] = i;
        arr[i].values[3] = i;
    }

    

    for (int i = amountOfFirstGeneration; i < amountOfPeople; i++) {
        int tmp1, tmp2, tmp3, tmp4;
        std::cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
        arr[i % 1500].values[0] = arr[tmp1 % 1500].values[0];
        arr[i % 1500].values[1] = arr[tmp2 % 1500].values[1];
        arr[i % 1500].values[2] = arr[tmp3 % 1500].values[2];
        arr[i % 1500].values[3] = arr[tmp4 % 1500].values[3];
    }
    amountOfPeople--;
    std::cout << surnames[arr[amountOfPeople % 1500].values[0]].substr(0, 3);
    std::cout << surnames[arr[amountOfPeople % 1500].values[1]].substr(3, 3);
    std::cout << surnames[arr[amountOfPeople % 1500].values[2]].substr(6, 3);
    std::cout << surnames[arr[amountOfPeople % 1500].values[3]].substr(9, 3);

    return 0;
}
