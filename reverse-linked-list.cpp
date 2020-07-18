// Find the middle element of a linked list in a single pass.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node {
    int data;
    node* next;
};

node* create_list() {
    srand(time(NULL));
    const int nodes = 10 + rand() % 10;

    node* head = nullptr;
    node* prev = nullptr;

    for (int n = 0; n < nodes; n++) {
        node* curr = new node();
        curr->data = rand() % 100;
        if (prev) prev->next = curr;

        if (!head) head = curr;
        prev = curr;
    }
    prev->next = NULL;

    return head;
}

void display_list(node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << ", ";
        head = head->next;
    }
    cout << "." << endl;
}

void destroy_list(node* head) {
    while (head) {
        node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    node* head = create_list();
    display_list(head);

    // It is assumend that a list has at least two elements.

    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    do {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    } while (curr);
    head = prev;

    display_list(head);

    destroy_list(head);
}
