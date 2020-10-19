#pragma once
#include <iostream>
#include <stdexcept>

class LinkedList{
    class Node {
    public:
        Node(int _data, Node *_next = nullptr) : data(_data), next(_next) {}
        ~Node() {}

        int data;
        Node *next;
    };

public:

    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        clear();    // Очищаем память
    }

    void push_back(int);
    void push_front(int);
    void pop_back();
    void pop_front();
    void insert(int, size_t);
    int at(size_t);
    void remove(size_t);
    size_t get_size();
    void print_to_console();
    void clear();
    void set(size_t, int);
    bool isEmpty();

    void reverse();

private:
    size_t size;
    Node *head;
    Node *tail;
};
