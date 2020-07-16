// Find the middle element of a linked list in a single pass.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* create_list() {
    srand(time(NULL));
    const int nodes = 10 + rand() % 10;

    Node* first = nullptr;
    Node* prev = nullptr;

    for (int n = 0; n < nodes; n++) {
        Node* curr = new Node();
        curr->value = rand() % 100;
        if (prev) prev->next = curr;

        if (!first) first = curr;
        prev = curr;
    }
    prev->next = NULL;

    return first;
}

void display_list(Node* first) {
    while (first) {
        cout << first->value;
        if (first->next) cout << ", ";
        first = first->next;
    }
    cout << "." << endl;
}

int main() {
    Node* first = create_list();
    display_list(first);

    Node* middle = first;
    bool move = false;
    while (first) {
        if (move) middle = middle->next;
        move = !move;
        first = first->next;
    }

    cout << middle->value << endl;
}
