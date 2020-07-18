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

    node* first = head;
    node* premiddle = head;
    node* middle = head;
    bool move = false;
    int count = 0;
    while (first) {
        if (move) {
            premiddle = middle;
            middle = middle->next;
        }
        move = !move;
        first = first->next;
        count++;
    }
    cout << "Number of nodes: " << count << endl;

    if (count % 2) {
        cout << "Middle element: " << middle->data << endl;
    }
    else {
        cout << "The two central elements: " << premiddle->data << " and " << middle->data << endl;
    }

    node* insertion = new node;
    insertion->data = -1;
    insertion->next = premiddle->next;
    premiddle->next = insertion;

    display_list(head);

    destroy_list(head);
}
