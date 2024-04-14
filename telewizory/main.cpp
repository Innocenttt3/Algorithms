#include <iostream>
#include <vector>

struct Program {
    int startTime;
    int endTime;

    Program(){};

};

bool ProgramsCompare(Program& p1, Program& p2) {
    return p1.endTime < p2.endTime;
}

bool newTv(std::vector<Program> alreadyOnTV, Program& newProgram) {
    for(Program tmp: alreadyOnTV) {
        if(newProgram.startTime < tmp.endTime && newProgram.startTime > tmp.startTime) return false;
        if(newProgram.endTime < tmp.endTime && newProgram.endTime> tmp.startTime) return false;
    }
    return true;
}

int main() {
    int amountOfData;
    int amountOfPrograms;
    int firstMinute;
    int otherMinutes;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> amountOfData;
    for (int i = 0; i < amountOfData; i++) {
        std::cin >> amountOfPrograms >> firstMinute >> otherMinutes;
        std::vector<Program> tvPrograms;
        std::vector<Program> alreadyOnTv;
        for (int y = 0; y < amountOfPrograms; y++) {
            Program tmpProgram;
            std::cin >>  tmpProgram.startTime >> tmpProgram.endTime;
            tvPrograms.push_back(tmpProgram);
        }
        std::sort(tvPrograms.begin(), tvPrograms.end(), ProgramsCompare);
        for(Program tmp: tvPrograms) {
            // std::cout << tmp.startTime << " " << tmp.endTime << std::endl;
        }
        int totalCost = 0;
        int previousEndTime = 0;
        for(Program tmp: tvPrograms) {
            int currStartTime = tmp.startTime;
            int currEndTime = tmp.endTime;

            if(currStartTime >= previousEndTime) {
                int currentUnitCost = firstMinute + ((currEndTime - currStartTime) * otherMinutes);
                // std::cout << currentUnitCost << std::endl;
                totalCost += currentUnitCost;
                previousEndTime = currEndTime;
            } else if(currStartTime < previousEndTime) {
                int currentUnitCost =  ((currEndTime - currStartTime + 1) * otherMinutes);
                std::cout << currentUnitCost << std::endl;
                totalCost += currentUnitCost;
                previousEndTime = currEndTime;
            }

        }
        std::cout << totalCost;
    }
    return 0;
}
