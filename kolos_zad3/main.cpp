#include <iostream>


struct Command {
    int priority;
    std::string text;
    int index;

    Command(int priority, std::string text, int index) {
        this->priority = priority;
        this->text = std::move(text);
        this->index = index;
    }
};

class Heap {
    Command** heap;
    unsigned long long capacity;
    int size;

    int getParent(int index) { return (index - 1) / 2; }

    int getRight(int index) { return 2 * index + 2; }

    int getLeft(int index) { return 2 * index + 1; }

    void heapifyDown(int index) {
        int l = getLeft(index);
        int r = getRight(index);
        int largest = index;
        if (l < size && (heap[l]->priority < heap[largest]->priority || (
                             heap[l]->priority == heap[largest]->priority && heap[l]->index < heap[largest]->index)))
            largest = l;
        if (r < size && (heap[r]->priority < heap[largest]->priority || (
                             heap[r]->priority == heap[largest]->priority && heap[r]->index < heap[largest]->index)))
            largest = r;
        if (largest != index) {
            std::swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }

    void heapiftyUp(int index) {
        if (index == 0) {
            return;
        }
        int parent = getParent(index);
        if (heap[parent]->priority > heap[index]->priority || (
                heap[parent]->priority > heap[index]->priority && heap[parent]->index > heap[index]->index)) {
            std::swap(heap[parent], heap[index]);
            heapiftyUp(parent);
        }
    }

public:
    Heap(unsigned long long capacity) {
        heap = new Command *[capacity];
        this->capacity = capacity;
        size = 0;
    }

    void insert(int index, int priority, std::string text) {
        if (size == capacity) {
            capacity *= 2;
            Command** temp = heap;
            heap = new Command*[capacity];

            for (int i = 0; i < capacity / 2; i++) {
                heap[i] = temp[i];
            }
        }
        heap[size] = new Command(priority, std::move(text), index);
        heapiftyUp(size);
        size++;
    }

    std::string pop() {
        if (size <= 0) {
            return "BRAK";
        }
        size--;
        std::string result = std::move(heap[0]->text);
        delete heap[0];
        heap[0] = new Command(*heap[size]);
        delete heap[size];
        heapifyDown(0);
        return result;
    }

    ~Heap() {
        for (int i = 0; i < size; i++) {
            delete heap[i];
        }
        delete[] heap;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned long long amountOfOperations;
    short typeOfOperation;
    int priority;
    std::string text;

    std::cin >> amountOfOperations;
    Heap heap(amountOfOperations / 4);
    for (unsigned long long i = 0; i < amountOfOperations; i++) {
        std::cin >> typeOfOperation;
        if (typeOfOperation == 1) {
            std::cin >> priority >> text;
            heap.insert(i, priority, text);
        }
        else if (typeOfOperation == 2) {
            std::cout << heap.pop() << " ";
        }
    }

    return 0;
}
