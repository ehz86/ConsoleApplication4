#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addElement(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    int searchByIndex(int index) {
        Node* curr = head;
        int count = 0;

        while (curr != nullptr) {
            if (count == index) {
                return curr->data;
            }
            count++;
            curr = curr->next;
        }

        // ≈сли индекс выходит за пределы списка, возвращаем -1 или бросаем исключение
        return -1;
    }

    void deleteByIndex(int index) {
        if (head == nullptr) {
            return;
        }

        Node* curr = head;
        if (index == 0) {
            head = head->next;
            delete curr;
            return;
        }

        Node* prev = nullptr;
        int count = 0;

        while (curr != nullptr && count != index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) {
            // ≈сли индекс выходит за пределы списка, ничего не удал€ем
            return;
        }

        prev->next = curr->next;
        delete curr;
    }
    int showlastanddelete() {
       

        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
    void showList() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};
