#include <iostream>

struct City {
    std::string name;
    int activityLevel;
    int index;
};

class Heap {
    City* heap;
    int capacity;
    int size;

    int getParent(int index) { return (index - 1) / 2; }

    int getRight(int index) { return 2 * index + 2; }

    int getLeft(int index) { return 2 * index + 1; }

    void swap(City * x, City* y) {
        City tmp = *x;
        *x = *y;
        *y = tmp;
    }

public:
    Heap(int capacity) {
        heap = new City[capacity];
        this->capacity = capacity;
        size = 0;
    }

    void insert(City& newValue) {
        if (size == capacity) {
            return;
        }
        size++;
        int i = size - 1;
        heap[i] = newValue;

        while (i != 0 &&
            (heap[getParent(i)].activityLevel < heap[i].activityLevel ||
            (heap[getParent(i)].activityLevel == heap[i].activityLevel && heap[getParent(i)].index > heap[i].index))) {
            swap(&heap[getParent(i)], &heap[i]);
            i = getParent(i);
        }
    }

    void heapifyDown(int index) {
        int l = getLeft(index);
        int r = getRight(index);
        int largest = index;
        if (l < size && (heap[l].activityLevel > heap[index].activityLevel || (heap[l].activityLevel == heap[index].activityLevel && heap[l].index < heap[index].index)))
            largest = l;
        if (r < size && (heap[r].activityLevel > heap[largest].activityLevel || (heap[r].activityLevel == heap[largest].activityLevel && heap[r].index < heap[largest].index)))
            largest = r;
        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            heapifyDown(largest);
        }
    }

    City extractMax()
    {
        if (size == 1)
        {
            size--;
            return heap[0];
        }

        City root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            std::cout << heap[i].name << " " << heap[i].activityLevel << std::endl;
        }
    }

    ~Heap() {
        delete[] heap;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int amountOfData;
    int tmpValue;
    int maxLimit;
    std::string tmpName;
    std::cin >> amountOfData;
    Heap heap(amountOfData);
    for (int i = 0; i < amountOfData; i++) {
        std::cin >> tmpName >> tmpValue;
        City tmpCity;
        tmpCity.name = tmpName;
        tmpCity.activityLevel = tmpValue;
        tmpCity.index = i;
        heap.insert(tmpCity);
    }
    std::cin >> maxLimit;
    for (int i = 0; i < amountOfData; i++) {
        if(maxLimit > 0) {
            City tmp = heap.extractMax();
            if(tmp.activityLevel <= maxLimit) {
                std::cout << tmp.name << " ";
                maxLimit -= tmp.activityLevel;
            }
        }

    }
    return 0;
}
