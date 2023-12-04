#include <iostream>
#include <queue>
#include <vector>


struct Harambe {
    char type;
    int max;
    Harambe *parent;
    std::vector<Harambe *> children;

    Harambe(char newType, int newMax, Harambe *newParent) {
        type = newType;
        max = newMax;
        parent = newParent;
    }

    Harambe() {
    }
};

void printTreePreorder(Harambe* node) {
    if (node == nullptr) {
        return;
    }

    std::cout << node->type;
    for (Harambe* child : node->children) {
        printTreePreorder(child);
    }
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int boxesAmount, harambesAmount, tmpValue;
    char singleLetter;
    std::cin >> boxesAmount;
    for (int i = 0; i < boxesAmount; i++) {
        std::cin >> harambesAmount;
        std::cin >> singleLetter >> tmpValue;
        auto* original = new Harambe(singleLetter, tmpValue, nullptr);
        std::queue<Harambe*> harambesQueue;
        harambesQueue.push(original);
        for (int j = 1; j < harambesAmount; j++) {
            std::cin >> singleLetter >> tmpValue;
            auto* newHarambe = new Harambe(singleLetter, tmpValue, nullptr);
            while (!harambesQueue.empty() && harambesQueue.front()->children.size() >= harambesQueue.front()->max) {
                harambesQueue.pop();
            }
            if (!harambesQueue.empty()) {
                newHarambe->parent = harambesQueue.front();
                harambesQueue.front()->children.push_back(newHarambe);
            }
            harambesQueue.push(newHarambe);
        }
        printTreePreorder(original);
        std::cout << std::endl;
    }

    return 0;
}

