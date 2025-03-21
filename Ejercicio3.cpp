#include <iostream>
#include <memory>

using namespace std;

// Explicacion para correrlo:
/*
Escribir en la consola: 
        g++ -o Ejercicio3 Ejercicio3.cpp (enter)
         ./Ejercicio3(enter)
*/

struct Node{
    int value;
    shared_ptr<Node> next;
};

shared_ptr<Node> creat_node(int valor){
    shared_ptr<Node> new_Node = make_shared<Node>();
    new_Node -> value = valor;
    return new_Node;
}

void push_front(shared_ptr<Node> &head, int valor){
    shared_ptr<Node> new_node = creat_node(valor);
    new_node -> next = head;
    head = new_node;
}

void push_back(shared_ptr<Node> &tail, int valor){
    shared_ptr<Node> new_node = creat_node(valor);
    if(!tail){
        tail = new_node;
    } else{
        shared_ptr<Node> current = tail;
        while(current->next){
            current = current->next;
        }
        current->next = new_node;
    }
}
 
void insert(shared_ptr<Node> &head, int valor, int pos){
    shared_ptr<Node> new_node = creat_node(valor);

    if(pos <= 0 || !head){
        push_front(head, valor);
    } else{
        shared_ptr<Node> current = creat_node(valor);
        int index = 0;
        while (current->next && index < pos - 1) {
            current = current->next; 
            index++;
        }
        if(!current->next){
            push_back(head, valor);
        } else{
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

void erase(shared_ptr<Node> &head, int pos) {
    if (!head) return; 

    if (pos == 0) {
        head = head->next; 
    } else {
        shared_ptr<Node> current = head;
        int index = 0;
        while (current->next && index < pos - 1) {
            current = current->next; 
            index++;
        }

        if (current->next) {
            current->next = current->next->next; 
        } else {
            current->next = nullptr;
        }
    }
}

void print_list(const shared_ptr<Node> &head){
    shared_ptr<Node> current = head;
    while(current){
        cout << current->value;
        if(current->next){
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    shared_ptr<Node> head = nullptr;

    push_front(head, 1); // Inserto el primer elemento de la lista
    push_front(head, 20); // Inserto al frente del primero
    push_back(head, 99);  // Inserto al final de la lista
    insert(head, 25, 3);  // Inserto en la posición 3
    insert(head, 24, 4);  // Inserto en la posición 4
    insert(head, 5, 30);  // Insertar en una posición mayor al largo

    cout << "Lista después de inserciones: ";
    print_list(head);

    erase(head, 3);  // Borrar el nodo en la posición 3
    erase(head, 30); // Borrar en una posición mayor al largo de la lista

    cout << "Lista después de borrados: ";
    print_list(head);

    return 0;
}
