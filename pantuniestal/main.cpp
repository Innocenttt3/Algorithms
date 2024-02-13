#include <deque>
#include <iostream>
#include <vector>

struct Customer {
    int rate;
    std::deque<int> desiredProducts;
    int index;
    int valueOfBasket = 0;

    Customer(){};

    Customer(int rate, int index) {
        this->index = index;
        this->rate = rate;
    }
};

struct Product {
    int id;
    int amount;
    int price;

    Product() : id(0), amount(0), price(0) {
    }

    Product(int id, int amount, int price) : id(id), amount(amount), price(price) {
    }
};

class Heap {
    Customer** heap;
    int maxSize;
    int currentSize;

    int getParent(int index) { return (index - 1) / 2; }

    int getRight(int index) { return 2 * index + 2; }

    int getLeft(int index) { return 2 * index + 1; }


public:
    Heap(int capacity) {
        heap = new Customer*[capacity];
        this->maxSize = capacity;
        currentSize = 0;
    }

    void insert(Customer *newValue) {
        if (currentSize == maxSize) {
            maxSize *= 2;
            Customer** temp = heap;
            heap = new Customer*[maxSize];

            for (int i = 0; i < maxSize / 2; i++) {
                heap[i] = temp[i];
            }
        }
        currentSize++;
        int i = currentSize - 1;
        heap[i] = newValue;

        while (i != 0 && (heap[getParent(i)]->rate < heap[i]->rate || (
                              heap[getParent(i)]->rate == heap[i]->rate && heap[getParent(i)]->index > heap[i]->index))) {
            Customer *tmp = heap[getParent(i)];
            heap[getParent(i)] = heap[i];
            heap[i] = tmp;

            i = getParent(i);
        }
    }

    void heapifyDown(int index) {
        int l = getLeft(index);
        int r = getRight(index);
        int largest = index;
        if (l < currentSize && (heap[l]->rate > heap[index]->rate || (
                             heap[l]->rate == heap[index]->rate && heap[l]->index < heap[index]->index)))
            largest = l;
        if (r < currentSize && (heap[r]->rate > heap[largest]->rate || (
                             heap[r]->rate == heap[largest]->rate && heap[r]->index < heap[largest]->index)))
            largest = r;
        if (largest != index) {
            Customer *tmp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = tmp;
            heapifyDown(largest);
        }
    }
    void print() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << heap[i]->rate << " Desired Products: ";
            for (int j = 0; j < heap[i]->desiredProducts.size(); j++) {
                std::cout << heap[i]->desiredProducts[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void buyProducts(std::vector<Product>& arr) {
        for (int i = 0; i < currentSize; i++) {
            while (!heap[i]->desiredProducts.empty()) {
                int index = heap[i]->desiredProducts.front();
                heap[i]->desiredProducts.pop_front();
                if (index >= 0 && index < arr.size() && arr[index].amount > 0) {
                    arr[index].amount--;
                    heap[i]->valueOfBasket += arr[index].price;
                    break;
                }
            }
        }
    }

    void printBasketValues() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << heap[i]->valueOfBasket << " ";
        }
    }

    ~Heap() {
        for (int i = 0; i < currentSize; i++) {
            delete heap[i];
        }
        delete[] heap;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int amountOfEmployes;
    int varietyOfProducts;
    int amountOfTours;
    int desiredProduct;
    int amountOfType;
    int rate;
    std::cin >> amountOfEmployes >> varietyOfProducts >> amountOfTours;
    Heap heap(amountOfEmployes);
    std::vector<Product> productsTable(varietyOfProducts);
    std::vector<Customer> customerTable(amountOfEmployes);
    for (int i = 0; i < amountOfEmployes; i++) {
        std::cin >> rate >> amountOfType;
        customerTable[i].rate = rate;
        customerTable[i].index = i;
        for (int j = 0; j < amountOfType; j++) {
            std::cin >> desiredProduct;
           customerTable[i].desiredProducts.push_back(desiredProduct);
        }
        heap.insert(&customerTable[i]);
    }
    for (int i = 0; i < varietyOfProducts; i++) {
        productsTable[i].id = i;
        std::cin >> productsTable[i].amount >> productsTable[i].price;
    }
    for (int i = 0; i < amountOfTours; i++) {
        heap.buyProducts(productsTable);
    }
    for (const auto& customer : customerTable) {
        std::cout<< customer.valueOfBasket  << " ";
    }
    return 0;
}
