#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct City {
    bool visited;
    int id;
    int entryCost;
    std::string name;
    std::vector<int> connectedCitiesID;

    City(int id, std::string name) {
        this->id = id;
        this->name = name;
        this->visited = false;
    }
};

void BFS(std::vector<City>& cities, int startCityId, int endCityId) {
    std::queue<int> q;
    cities[startCityId].visited = true;
    q.push(startCityId);

    while (!q.empty()) {
        int currentCityId = q.front();
        q.pop();

        std::cout << cities[currentCityId].name << " ";

        if (currentCityId == endCityId)
            return;

        for (int neighborId : cities[currentCityId].connectedCitiesID) {
            if (!cities[neighborId].visited) {
                cities[neighborId].visited = true;
                q.push(neighborId);
            }
        }
    }
}

void DFS(std::vector<City>& cities, int startCityId, int endCityId) {
    std::stack<int> s;
    s.push(startCityId);
    cities[startCityId].visited = true;

    while (!s.empty()) {
        int currentCityId = s.top();
        s.pop();

        if (currentCityId == endCityId) {
            std::cout << cities[currentCityId].name << " ";
            return;
        }

        if (!cities[currentCityId].visited) {
            cities[currentCityId].visited = true;
            std::cout << cities[currentCityId].name << " ";
        }

        for (int neighborId : cities[currentCityId].connectedCitiesID) {
            if (!cities[neighborId].visited) {
                s.push(neighborId);
            }
        }
    }
}


int main() {
    std::vector<City> citiesForBfs;
    City gdansk(0, "Gdansk");
    citiesForBfs.push_back(gdansk);
    City poznan(1, "Poznan");
    citiesForBfs.push_back(poznan);
    City warszawa(2, "Warszawa");
    citiesForBfs.push_back(warszawa);
    City lodz(3, "Lodz");
    citiesForBfs.push_back(lodz);
    City wroclaw(4, "Wroclaw");
    citiesForBfs.push_back(wroclaw);
    City czestochowa(5, "Czestochowa");
    citiesForBfs.push_back(czestochowa);
    City opole(6, "Opole");
    citiesForBfs.push_back(opole);
    City paryz(7, "Paryz");
    citiesForBfs.push_back(paryz);


    citiesForBfs[0].connectedCitiesID = {1, 2, 3, 7};
    citiesForBfs[1].connectedCitiesID = {0, 2, 3, 4};
    citiesForBfs[2].connectedCitiesID = {0, 1, 3, 5};
    citiesForBfs[3].connectedCitiesID = {0, 1, 2, 4, 5};
    citiesForBfs[4].connectedCitiesID = {1, 3, 5, 6};
    citiesForBfs[5].connectedCitiesID = {2, 3, 4, 6};
    citiesForBfs[6].connectedCitiesID = {4, 5};
    citiesForBfs[7].connectedCitiesID = {0, 6};

    for (City& city : citiesForBfs) {
        city.visited = false;
    }


    std::vector<City> citiesForDfs;
    City gdansk2(0, "Gdansk");
    citiesForDfs.push_back(gdansk);
    City poznan2(1, "Poznan");
    citiesForDfs.push_back(poznan);
    City warszawa2(2, "Warszawa");
    citiesForDfs.push_back(warszawa);
    City lodz2(3, "Lodz");
    citiesForDfs.push_back(lodz);
    City wroclaw2(4, "Wroclaw");
    citiesForDfs.push_back(wroclaw);
    City czestochowa2(5, "Czestochowa");
    citiesForDfs.push_back(czestochowa);
    City opole2(6, "Opole");
    citiesForDfs.push_back(opole);
    City paryz2(7, "Paryz");
    citiesForDfs.push_back(paryz);


    citiesForDfs[0].connectedCitiesID = {1, 2, 3, 7};
    citiesForDfs[1].connectedCitiesID = {0, 2, 3, 4};
    citiesForDfs[2].connectedCitiesID = {0, 1, 3, 5};
    citiesForDfs[3].connectedCitiesID = {0, 1, 2, 4, 5};
    citiesForDfs[4].connectedCitiesID = {1, 3, 5, 6};
    citiesForDfs[5].connectedCitiesID = {2, 3, 4, 6};
    citiesForDfs[6].connectedCitiesID = {4, 5};
    citiesForDfs[7].connectedCitiesID = {0, 6};

    for (City& city : citiesForDfs) {
        city.visited = false;
    }
    int startCityId = 0;
    int endCityId = 6;


    std::cout << "BFS traversal from " << citiesForBfs[startCityId].name << " to " << citiesForBfs[endCityId].name << ": ";
    BFS(citiesForBfs, startCityId, endCityId);
    std::cout << std::endl;

    std::cout << "DFS traversal from " << citiesForBfs[startCityId].name << " to " << citiesForBfs[endCityId].name << ": ";
    DFS(citiesForDfs, startCityId, endCityId);
    std::cout << std::endl;

    return 0;
}
