#include <iostream>

using namespace std;

struct Message {
    int priority;
    string content;

    Message(int priority, string content) {
        this->priority = priority;
        this->content = content;
    }
};

struct Heap {
    Message** heap;
    int currentSize = 0;
    int maxSize = 0;

    Heap(unsigned long long n) {
        this->heap = new Message*[n];
        this->maxSize = n;
    }

    void push(int priority, string content) {
        if (currentSize == maxSize) {
            maxSize *= 2;
            Message** temp = heap;
            heap = new Message*[maxSize];

            for (int i = 0; i < maxSize / 2; i++) {
                heap[i] = temp[i];
            }
        }

        heap[currentSize++] = new Message(priority, content);

        int k = currentSize - 1;
        while ((k - 1) / 2 >= 0) {
            if (heap[(k - 1) / 2]->priority > heap[k]->priority) {
                swap(heap[(k - 1) / 2], heap[k]);
                k = (k - 1) / 2;
            } else {
                break;
            }
        }
    }

    string pop() {
        if (currentSize > 0) {
            string res = heap[0]->content;
            delete heap[0];

            heap[0] = heap[--currentSize];

            int k = 0;
            while (2*k + 1 < currentSize) {
                int left, right;
                left = heap[2*k + 1]->priority;

                if (2*k + 2 < currentSize) {
                    right = heap[2*k + 2]->priority;
                } else {
                    right = -1;
                }

                int chosenIndex;
                if (right != -1 && left > right) {
                    chosenIndex = 2*k + 2;
                } else {
                    chosenIndex = 2*k + 1;
                }

                if (heap[chosenIndex]->priority <= heap[k]->priority) {
                    swap(heap[chosenIndex], heap[k]);
                    k = chosenIndex;
                } else break;
            }

            return res;
        } else {
            return "BRAK";
        }
    }

    ~Heap() {
        for (int i = 0; i < currentSize; i++) {
            delete heap[i];
        }

        delete[] heap;
    }
};

void print(Heap* heap) {
    for (int i = 0; i < heap->currentSize; i++) {
        cout << "k: " << i << " " << heap->heap[i]->priority << " " << heap->heap[i]->content << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    unsigned long long n;
    cin >> n;

    Heap* heap = new Heap(n / 4);

    for (unsigned long long i = 0; i < n; i++) {
        short isWrite;
        cin >> isWrite;

        if (isWrite == 1) {
            int priority;
            string content;

            cin >> priority >> content;

            heap->push(priority, content);
        } else if (isWrite == 2) {
            // print(heap);
            // cout << '\n';

            cout << heap->pop() << " ";
        }
    }

    return 0;
}