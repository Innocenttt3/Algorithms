#include <deque>
#include <iostream>
#include <vector>

struct Customer {
    int rate;
    std::deque<int> desiredProducts;
    int index;
    int valueOfBasket = 0;

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
    int capacity;
    int size;

    int getParent(int index) { return (index - 1) / 2; }

    int getRight(int index) { return 2 * index + 2; }

    int getLeft(int index) { return 2 * index + 1; }

    void swap(Customer* x, Customer* y) {
        Customer tmp = *x;
        *x = *y;
        *y = tmp;
    }

public:
    Heap(int capacity) {
        heap = new Customer*[capacity];
        this->capacity = capacity;
        size = 0;
    }

    void insert(Customer *newValue) {
        if (size == capacity) {
            return;
        }
        size++;
        int i = size - 1;
        heap[i] = newValue;

        while (i != 0 && (heap[getParent(i)]->rate < heap[i]->rate || (
                              heap[getParent(i)]->rate == heap[i]->rate && heap[getParent(i)]->index > heap[i]->index))) {
            swap(heap[getParent(i)], heap[i]);
            i = getParent(i);
        }
    }

    void heapifyDown(int index) {
        int l = getLeft(index);
        int r = getRight(index);
        int largest = index;
        if (l < size && (heap[l]->rate > heap[index]->rate || (
                             heap[l]->rate == heap[index]->rate && heap[l]->index < heap[index]->index)))
            largest = l;
        if (r < size && (heap[r]->rate > heap[largest]->rate || (
                             heap[r]->rate == heap[largest]->rate && heap[r]->index < heap[largest]->index)))
            largest = r;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    Customer* extractMax() {
        if (size == 1) {
            size--;
            return heap[0];
        }

        Customer *root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i]->rate << " Desired Products: ";
            for (int j = 0; j < heap[i]->desiredProducts.size(); j++) {
                std::cout << heap[i]->desiredProducts[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void buyProducts(std::vector<Product>& arr) {
        for (int i = 0; i < size; i++) {
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
        for (int i = 0; i < size; i++) {
            std::cout << heap[i]->valueOfBasket << " ";
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

    int amountOfEmployes;
    int varietyOfProducts;
    int amountOfTours;
    int desiredProduct;
    int amountOfType;
    int rate;
    std::cin >> amountOfEmployes >> varietyOfProducts >> amountOfTours;
    Heap heap(amountOfEmployes);
    std::vector<Product> productsTable(varietyOfProducts);
    std::deque<Customer *> customerTable;
    for (int i = 0; i < amountOfEmployes; i++) {
        std::cin >> rate >> amountOfType;
        Customer *tmp = new Customer(rate, i);
        for (int j = 0; j < amountOfType; j++) {
            std::cin >> desiredProduct;
            tmp->desiredProducts.push_back(desiredProduct);
        }
        heap.insert(tmp);
        customerTable.push_back(tmp);
    }
    for (int i = 0; i < varietyOfProducts; i++) {
        productsTable[i].id = i;
        std::cin >> productsTable[i].amount >> productsTable[i].price;
    }
    heap.print();
    for (int i = 0; i < amountOfTours; i++) {
        heap.buyProducts(productsTable);
    }
    for (const auto& customer : customerTable) {
        std::cout << customer->rate << " " << customer->valueOfBasket << std::endl;
    }
    return 0;
}
