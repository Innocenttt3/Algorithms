#include <iostream>

struct Student {
    std::string id;
    float avgGrade;
    int distance;
    int monthOfBirth;
};

bool comparator(Student &student1, Student &student2, char ord1, char ord2, char ord3) {
    for (char ord: {ord1, ord2, ord3}) {

        if (student1.avgGrade > student2.avgGrade && ord == 's') {
            return false;
        } else if (student1.avgGrade < student2.avgGrade && ord == 's') {
            return true;
        } else if (student1.monthOfBirth > student2.monthOfBirth && ord == 'm') {
            return false;
        } else if (student1.monthOfBirth < student2.monthOfBirth && ord == 'm') {
            return true;
        } else if (student1.distance > student2.distance && ord == 'd') {
            return false;
        } else if (student1.distance < student2.distance && ord == 'd') {
            return true;
        }
    }
    return false;
}

void insertionSort(Student *arr, int n, char ord1, char ord2, char ord3) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && comparator(arr[j], key, ord1, ord2, ord3)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    char ord1, ord2, ord3;

    std::cin >> n;
    std::cin >> ord1 >> ord2 >> ord3;

    Student *boys = new Student[n];
    Student *girls = new Student[n];
    Student tmpStudent;

    for (int i = 0; i < n; i++) {
        std::cin >> boys[i].id >> boys[i].avgGrade >> boys[i].distance >> boys[i].monthOfBirth;
        std::cin >> girls[i].id >> girls[i].avgGrade >> girls[i].distance >> girls[i].monthOfBirth;
    }

    insertionSort(boys, n, ord1, ord2, ord3);
    insertionSort(girls, n, ord1, ord2, ord3);
    for (int i = 0; i < n; i++) {
        std::cout << boys[i].id << " " << girls[i].id << " ";
    }

    delete[] boys;
    delete[] girls;
    return 0;
}