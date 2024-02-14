#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        next = nullptr;
        prev = nullptr;
        data = value;
    }
};

class List {
    Node* head = nullptr;
    Node* tail = nullptr;

    long long numberOfElements = 0;

public:
    long long size() {
        return numberOfElements;
    }

    long long isEmpty() {
        return !numberOfElements;
    }

    Node* first() {
        if (isEmpty()) {
            std::cout << "PUSTA" << std::endl;
            return nullptr;
        }
        return head;
    }

    Node* last() {
        if (isEmpty()) {
            std::cout << "PUSTA" << std::endl;
            return nullptr;
        }
        return tail;
    }

    void pushFront(int value) {
        Node* node = new Node(value);

        if (head != nullptr) {
            head->prev = node;
        }

        node->next = head;
        head = node;

        if (isEmpty()) {
            tail = head;
        }
        numberOfElements++;
    }

    void pushBack(int value) {
        if (isEmpty()) {
            pushFront(value);
            tail = head;
        }
        else {
            Node* node = new Node(value);
            node->prev = tail;
            tail->next = node;
            tail = node;
            numberOfElements++;
        }
    }

    void popFront() {
        if (size() > 1) {
            Node* previousHead = head;
            head = head->next;
            head->prev = nullptr;
            numberOfElements--;
            delete previousHead;
        }
        else if (size() == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            numberOfElements--;
        }
        else {
            std::cout << "PUSTA" << std::endl;
        }
    }

    void popBack() {
        if (size() > 1) {
            Node* current = tail->prev;
            delete tail;
            current->next = nullptr;
            tail = current;
            numberOfElements--;
        }
        else if (size() == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            numberOfElements--;
        }
        else {
            std::cout << "PUSTA" << std::endl;
        }
    }

    ~List() {
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long amountOfData;
    std::cin >> amountOfData;
    List* list = new List();
    short command;
    int arg;
    Node* node;
    for (long long i = 0; i < amountOfData; i++) {
        std::cin >> command;

        switch (command) {
            case 1:
                node = list->first();
                if (node != nullptr) {
                    std::cout << node->data << std::endl;;
                }
                break;
            case 2:
                node = list->last();
                if (node != nullptr) {
                    std::cout << node->data << std::endl;
                }
                break;
            case 3:
                std::cout << list->size() << std::endl;
                break;
            case 4:
                std::cin >> arg;
                list->pushFront(arg);
                break;
            case 5:
                std::cin >> arg;
                list->pushBack(arg);
                break;
            case 6:
                list->popFront();
                break;
            case 7:
                list->popBack();
                break;
        }
    }


    delete list;
    return 0;
}
