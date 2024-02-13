#include <iostream>

struct Command {
    unsigned long priority;
    std::string text;
    unsigned long index;
};

class Heap {

    Command *heap;
    unsigned long capacity;
    unsigned long size;

    unsigned long getParent(unsigned long index) { return (index - 1) / 2; }

    unsigned long getRight(unsigned long index) { return 2 * index + 2; }

    unsigned long getLeft(unsigned long index) { return 2 * index + 1; }

    void heapifyDown(unsigned long index) {
        unsigned long l = getLeft(index);
        unsigned long r = getRight(index);
        unsigned long largest = index;
        if (l < size && (heap[l].priority < heap[largest].priority || (heap[l].priority == heap[largest].priority && heap[l].index < heap[largest].index )))
            largest = l;
        if (r < size && (heap[r].priority < heap[largest].priority || (heap[r].priority == heap[largest].priority && heap[r].index < heap[largest].index )))
            largest = r;
        if (largest != index) {
            std::swap(heap[largest], heap[index]);
            heapifyDown(largest);
        }
    }

    void heapiftyUp(unsigned long index) {
        if(index == 0) {
            return;
        }
        unsigned long parent = getParent(index);
        if(heap[parent].priority > heap[index].priority || (heap[parent].priority > heap[index].priority && heap[parent].index > heap[index].index)) {
            std::swap(heap[parent], heap[index]);
            heapiftyUp(parent);
        }
    }
public:
    Heap(unsigned long capacity) {
        heap = new Command[capacity];
        this->capacity = capacity;
        size = 0;
    }
    void insert(Command& newValue) {
        if (size == capacity) {
            return;
        }
        heap[size] = newValue;
        heapiftyUp(size);
        size++;
    }

    void pop() {
        if(size <= 0) {
            return;
        }
        size--;
        heap[0] = heap[size];
        heapifyDown(0);
    }

    ~Heap() {

        delete[] heap;
    }

    std::string top() {
        if(size == 0) {
            return "BRAK";
        }
        return heap[0].text;
    }
};

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned long amountOfOperations;
    unsigned long typeOfOperation;
    std::string instruction;

    std::cin >> amountOfOperations;
    Heap heap(amountOfOperations);
    Command tmp;
    for (long i = 0; i < amountOfOperations; i++) {
        std::cin >> typeOfOperation;
        if(typeOfOperation == 1) {
            tmp.index = i;
            std::cin >> tmp.priority >> tmp.text;
            heap.insert(tmp);
        } else if(typeOfOperation == 2) {
            std::cout << heap.top() << " ";
            heap.pop();
        }
    }

    return 0;
}
