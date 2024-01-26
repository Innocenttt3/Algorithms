#include <iostream>

struct Place {
    int stepsNeeded;
    std::string name;

    Place(){};
};
bool sort(const Place& a, const Place& b) {
    return a.stepsNeeded > b.stepsNeeded;
}

int findMedian(std::vector<Place> arr, int startIndex, int endIndex) {
    int size = (endIndex - startIndex);
    int amountOfNeededArrs = size / 5;
    int smallArrSize = size % 5;
    return (arr[(size - 1) / 2].stepsNeeded + arr[size / 2].stepsNeeded) / 2;

    if(amountOfNeededArrs > 0 && smallArrSize == 0) {
        for(int i = 0; i < amountOfNeededArrs; i++) {
            startIndex += (4 * i);
            endIndex += (4 * i);
        }
    }
    if(amountOfNeededArrs > 0 && smallArrSize != 0) {

    }
    if(amountOfNeededArrs == 0) {
        std::sort(arr[startIndex] , arr[endIndex], sort);
        if (size % 2 != 0) return arr[size / 2].stepsNeeded;
    }

}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int amountOfPlaces;
    int amountToVist;
    int stepsLimit;
    int tmpIndex;
    std::string tmpName;
    int tmpSteps;


    std::cin >> amountOfPlaces;
    std::vector<Place> places(amountOfPlaces);
    for (int i = 0; i < amountOfPlaces; i++) {
        std::cin >> tmpName >> tmpSteps;
        places[i].name = tmpName;
        places[i].stepsNeeded = tmpSteps;
    }
    std::cin >> stepsLimit >> amountToVist;
    for (int i = 0; i < amountToVist; i++) {
        std::cin >> tmpIndex;
    }
    int amountOfNeededArrs = amountOfPlaces / 5 ;
    int smallArrSize = amountOfPlaces % 5;
    std::cout << amountOfNeededArrs << smallArrSize;


    return 0;
}
