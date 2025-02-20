#pragma once
#include "iostream"

class Node
{
    public:
        int data;
        Node* next;

        Node() {
            std::srand(time(0));
            data = (int)1 + (std::rand() % (1 - 50));
            next = nullptr;
        }
};

