#include <iostream>

using namespace std;

class Actor {
public:
    string name;
    int f;
    Actor* next;
    Actor();
};

Actor::Actor() {
    next = nullptr;
}

struct List {
    Actor* first;
    void add_person(string name, int f);
    Actor* find_person(int p);
    void delete_person(Actor* actor_to_delete);
    void display_list();
    List();
};

List::List() {
    first = nullptr;
}

void List::delete_person(Actor* actor_to_delete) {
    if (actor_to_delete == first) {
        first = actor_to_delete->next;
        delete actor_to_delete;
    } else {
        Actor* current = first;
        while (current && current->next != actor_to_delete) {
            current = current->next;
        }
        if (current) {
            Actor* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
}

void List::add_person(string name, int f) {
    Actor* new_actor = new Actor;
    new_actor->name = name;
    new_actor->f = f;
    bool exist = false;

    Actor* ptr = first;

    while (ptr) {
        if (ptr->name == name && ptr->f == f) {
            exist = true;
            break;
        }
        ptr = ptr->next;
    }

    if (!exist) {
        if (first == nullptr) {
            first = new_actor;
        } else {
            ptr = first;
            while (ptr->next) {
                ptr = ptr->next;
            }
            ptr->next = new_actor;
        }
        new_actor->next = nullptr;
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
        delete new_actor;
    }
}

Actor* List::find_person(int p) {
    Actor* current = first;
    Actor* final = nullptr;
    bool find = false;
    while (current) {
        if (current->f <= p) {
            if (!final || current->name < final->name) {
                final = current;
                find = true;
            }
        }
        current = current->next;
    }
    if (find) {
        cout << final->name << endl;
        return final;
    } else {
        cout << "NIE" << endl;
        return nullptr;
    }
}

int main() {
    int n, f, p;
    List list;
    string name, op;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, op);
        if (stoi(op) == 1) {
            getline(cin, name);
            cin >> f;
            cin.ignore();
            list.add_person(name, f);
        } else if (stoi(op) == 2) {
            cin >> p;
            cin.ignore();
            Actor* selectedActor = list.find_person(p);
            if (selectedActor) {
                list.delete_person(selectedActor);
            }
        }
    }



    return 0;
}