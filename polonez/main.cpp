#include <iostream>

struct Student {
    std::string id;
    float avgGrade;
    long long distance;
    int monthOfBirth;
};

int biggerValue(const Student &student1, const Student &student2, char type) {
    if (type == 's') {
        if (student1.avgGrade > student2.avgGrade) {
            return 1;
        }
    } else if (type == 'm') {
        if (student1.monthOfBirth > student2.monthOfBirth) {
            return 1;
        }
    } else if (type == 'd') {
        if (student1.distance > student2.distance) {
            return 1;
    }
    return -1;
}

int equalValues(const Student &student1, const Student &student2, char type) {
    if (type == 's') {
        if (student1.avgGrade == student2.avgGrade) {
            return 1;
        } else {
            return 0;
        }
    } else if (type == 'm') {
        if (student1.monthOfBirth == student2.monthOfBirth) {
            return 1;
        } else {
            return 0;
        }
    } else if (type == 'd') {
        if (student1.distance == student2.distance) {
            return 1;
        } else {
            return 0;
        }
    }
    return -1;
}

int comparator(const Student &student1, const Student &student2, char ord1, char ord2, char ord3) {
    if (biggerValue(student1, student2, ord1)) {
        return 1;
    } else if (equalValues(student1, student2, ord1)) {
        if (biggerValue(student1, student2, ord2)) {
            return 1;
        } else if (equalValues(student1, student2, ord2)) {
            if (biggerValue(student1, student2, ord3)) {
                return 1;
            } else if (equalValues(student1, student2, ord3)) {
                return -1;
            }
        }
    }
    return 0;
}

void merge(Student arr[], int l, int m, int r, char ord1, char ord2, char ord3) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Student* L = new Student[n1];
    Student* R = new Student[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (comparator(L[i], R[j], ord1, ord2, ord3)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(Student array[], int const begin, int const end, char ord1, char ord2, char ord3) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, ord1, ord2, ord3);
    mergeSort(array, mid + 1, end, ord1, ord2, ord3);
    merge(array, begin, mid, end, ord1, ord2, ord3);
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
        std::cin >> tmpStudent.id >> tmpStudent.avgGrade >> tmpStudent.distance >> tmpStudent.monthOfBirth;
        boys[i] = tmpStudent;
        std::cin >> tmpStudent.id >> tmpStudent.avgGrade >> tmpStudent.distance >> tmpStudent.monthOfBirth;
        girls[i] = tmpStudent;
    }

    mergeSort(boys, 0, n-1, ord1, ord2, ord3);
    mergeSort(girls, 0, n-1, ord1, ord2, ord3);
    for (int i = 0; i < n; i++) {
        std::cout << boys[i].id << " " << girls[i].id << " ";
    }

    return 0;
}
