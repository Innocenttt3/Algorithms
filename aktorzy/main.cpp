#include <iostream>
#include <string>


struct Actor {
    std::string name;
    long long fansNumber;
    Actor *nextActor;

    Actor();
};

Actor::Actor() {

}

struct listOfActors {
    Actor *firstActor{};

    listOfActors() {
        firstActor = nullptr;
    }


    bool addActor(std::string name, long long fansNumber) {

        Actor *currentActor = firstActor;
        while (currentActor != nullptr) {
            if (currentActor->name == name && currentActor->fansNumber == fansNumber) {
                return false;
            }
            currentActor = currentActor->nextActor;
        }

        Actor *newActor = new Actor();
        newActor->name = name;
        newActor->fansNumber = fansNumber;
        newActor->nextActor = nullptr;

        if (firstActor == nullptr) {
            firstActor = newActor;
        } else {
            currentActor = firstActor;
            while (currentActor->nextActor != nullptr) {
                currentActor = currentActor->nextActor;
            }
            currentActor->nextActor = newActor;
        }
        return true;
    }

    void removeActor(Actor *actorToRemove) {
        if (actorToRemove != nullptr) {
            Actor *current = firstActor;
            Actor *previous = nullptr;

            while (current != nullptr) {
                if (current == actorToRemove) {
                    if (previous != nullptr) {
                        previous->nextActor = current->nextActor;
                    } else {
                        firstActor = current->nextActor;
                    }

                    delete current;
                    return;
                }

                previous = current;
                current = current->nextActor;
            }
        }
    }

    void findMaxFansLowerThan(long long value) {
        Actor *maxActor = nullptr;
        long long maxFans = -1;

        Actor *currentActor = firstActor;

        while (currentActor != nullptr) {
            if (currentActor->fansNumber <= value && currentActor->fansNumber > maxFans) {
                maxActor = currentActor;
                maxFans = currentActor->fansNumber;
            } else if (currentActor->fansNumber <= value && currentActor->fansNumber == maxFans &&
                       maxActor != nullptr &&
                       currentActor->name < maxActor->name) {
                maxActor = currentActor;
            }
            currentActor = currentActor->nextActor;
        }
        if (maxActor == nullptr) {
            std::cout << "NIE" << std::endl;

        } else {
            std::cout << maxActor->name << std::endl;
            removeActor(maxActor);
        }
    }
};


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string tmpName, whichFunction;
    std::string trimmedInput;
    std::string line;
    long long tmpAmount, amountOfData, maxFans;

    listOfActors mainList;


    std::cin >> amountOfData;
    std::cin.ignore();

    for (int i = 0; i < amountOfData; i++) {
        std::getline(std::cin, whichFunction);
        long long whichFunctionTrim = std::stol(whichFunction);
        if (whichFunctionTrim == 1) {
            std::getline(std::cin, tmpName);
            std::cin >> tmpAmount;
            std::cin.ignore();
            if (mainList.addActor(tmpName, tmpAmount)) {
                std::cout << "TAK" << std::endl;
            } else {
                std::cout << "NIE" << std::endl;
            }
        } else if (whichFunctionTrim == 2) {
            std::cin >> maxFans;
            std::cin.ignore();
            mainList.findMaxFansLowerThan(maxFans);
        }
    }
    return 0;
}