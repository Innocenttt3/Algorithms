#include <iostream>
#include <string>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string lyrics;
    char sign;
    char signLower;
    std::map<char, int> amount;

    while (std::cin.get(sign) && sign != '^') {
        char singLower = tolower(sign);
        if (singLower >= 'a' && singLower <= 'z') {
            lyrics += singLower;
            amount[singLower]++;
        }
    }

    int maxCount = -1;
    int minCount = 1410065408;
    char maxChar = '\0';
    char minChar = '\0';

    for (std::map<char, int>::iterator it = amount.begin(); it != amount.end(); ++it) {
        const std::pair<char, int>& pair = *it;
        if (pair.second > maxCount || (pair.second == maxCount && pair.first < maxChar)) {
            maxCount = pair.second;
            maxChar = pair.first;
        }
        if (pair.second < minCount || (pair.second == minCount && pair.first < minChar)) {
            minCount = pair.second;
            minChar = pair.first;
        }
    }
    std::cout << maxChar << " " << minChar;
    return 0;
}
