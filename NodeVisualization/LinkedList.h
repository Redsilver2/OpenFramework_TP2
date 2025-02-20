#pragma once
#include "Node.h"

class LinkedList
{
    private:
       Node* head;

    public:
        LinkedList() {
            head = nullptr;
        }

        void insertHead(int value) {
            Node* node = new Node();
            node->data = value;
            node->next = head;
            head = node;
        }
       
        void insertAtTail(int value) {
            Node* node = new Node();
            node->data = value;

            if (head == nullptr)
            {
                head = node;
                return;
            }

            Node* temp = head;
           
            while (temp->next)
                temp = temp->next;

            temp->next = head;
        }
        
        void deleteHead() {
            if (!head) return;
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void deleteTail() {
            if (head == nullptr) return;
           
            if (head->next == nullptr) {
                Node* temp = head;
               
                while (temp->next->next) 
                    temp = temp->next;
                   
                delete temp->next;
                temp->next = nullptr;
                return;
            }

            delete head;
            head = nullptr;
        }
};

