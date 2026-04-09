#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};

void addFirst(Node *&head, int data) {
    Node *nodeBaru = new Node;
    cout << nodeBaru->data << endl;
    nodeBaru->data = data;
    cout << nodeBaru->data << endl;
    //
    nodeBaru->next = head;
    cout << nodeBaru->next << endl;
    head = nodeBaru;
}

// Fungsi transversal (menampilkan isi list)
void transversal(Node *head) {
    if (head == nullptr) {
        cout << "Linked list kosong" << endl;
        return;
    }
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next; //memori temp saat ini menuju node selanjutnya
    }
    cout << "nullptr" << endl;
}

void addMiddle(Node *&head, int databaru, int posisi) {
    if (posisi <= 1) {
        addFirst(head, databaru);
        return;
    }
    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1) {
        temp = temp->next;
        hitung++;
    }
    if (temp == nullptr) {
        cout << ">> Posisi tidak boleh melebihi panjang list <<" << endl;
        return;
    } else {
        Node *nodeBaru = new Node;
        nodeBaru->data = databaru;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void addLast(Node *&head, int databaru) {
    Node *nodeBaru = new Node;
    nodeBaru->data = databaru;
    nodeBaru->next = nullptr; //tail
    // jika linked list kosong
    if (head == nullptr){
        head = nodeBaru;
        return;
    }
    // jika tidak, traversal ke node terakhir
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void deleteFirst(Node *&head) {
    if (head == nullptr){
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    }

int main(){
    Node*head=nullptr;
    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);
    addMiddle(head, 25, 3);
    transversal(head);

    return 0;
}
