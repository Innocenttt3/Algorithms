#include <iostream>

struct Command {
    int priority;
    std::string text;
};

class Heap {

    Command *heap;
    long capacity;
    int size;

    int getParent(int index) { return (index - 1) / 2; }

    int getRight(int index) { return 2 * index + 2; }

    int getLeft(int index) { return 2 * index + 1; }

    void swap(Command *x, Command *y) {
        Command tmp = *x;
        *x = *y;
        *y = tmp;
    }
public:
    Heap(long capacity) {
        heap = new Command[capacity];
        this->capacity = capacity;
        size = 0;
    }
    void insert(Command& newValue) {
        if (size == capacity) {
            return;
        }
        size++;
        int i = size - 1;
        heap[i] = newValue;

        while (i != 0 && heap[getParent(i)].priority > heap[i].priority) {
            swap(&heap[getParent(i)], &heap[i]);
            i = getParent(i);
        }
    }
    void heapifyDown(int index) {
        int l = getLeft(index);
        int r = getRight(index);
        int largest = index;
        if (l < size && heap[l].priority < heap[index].priority)
            largest = l;
        if (r < size && heap[r].priority < heap[largest].priority)
            largest = r;
        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            heapifyDown(largest);
        }
    }
    Command extractMax() {
        if(size <= 0) {
            std::cout << "BRAK";
        }
        if (size == 1)
        {
            size--;
            return heap[0];
        }

        Command root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }
    ~Heap() {
        delete[] heap;
    }
};

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long amountOfOperations;
    int typeOfOperation;
    std::string instruction;

    std::cin >> amountOfOperations;
    Heap heap(amountOfOperations);
    for (long i = 0; i < amountOfOperations; i++) {
        std::cin >> typeOfOperation;
        if(typeOfOperation == 1) {
            Command tmp;
            std::cin >> tmp.priority >> tmp.text;
            heap.insert(tmp);
        } else if(typeOfOperation == 2) {
            Command result = heap.extractMax();
            std::cout << result.text << std::endl;
        }
    }

    return 0;
}
