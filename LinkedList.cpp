#include "pch.h"
#include "LinkedList.h"

using namespace std;

// Add to the end of the list
void LinkedList::push_back(int _data) {
    if (size == 0) {
        head = new Node(_data);
        tail = head;
    } else {
        tail = tail->next = new Node(_data);
    }

    size++;
}

// Add to the head of the list
void LinkedList::push_front(int _data) {
    if (size == 0) {
        head = new Node(_data);
        tail = head;
    } else {
        Node *head_saved = head;
        head = new Node(_data, head_saved);
    }

    size++;
}

// Delete the last element of the list
void LinkedList::pop_back() {
    if (size == 0) throw logic_error("can't pop the empty list");

    if (size == 1) {
        // If we have only one element
        delete head;

        head = nullptr;
        tail = nullptr;
    } else {
        Node *current = head;

        while (current->next != tail) {
            current = current->next;
            if (current == nullptr) throw runtime_error("An empty element in list");
        }

        delete tail;
        tail = current;                 // set new tail
        tail->next = nullptr;           // free our next pos.
    }

    size--;

}

// Delete the head of the list
void LinkedList::pop_front() {
    if (size == 0) throw logic_error("can't pop the empty list");      // Do not delete the empty list.

    if (size == 1) {
        // If we have only one element
        delete head;

        head = nullptr;
        tail = nullptr;
    } else {
        Node *new_head = head->next;
        delete head;
        head = new_head;    // even if we have a nullptr "next"
    }

    size--;
}

// Insert the element by index (before)
void LinkedList::insert(int _data, size_t index) {
    if (index > size)  throw out_of_range("Index in insert() is greater than a list size");
    else if (index == 0 || size == 0) {
        push_front(_data);
    } else if (index == size) {
        push_back(_data);
    } else {
        size_t counter = 0;
        Node *current = head;

        // There is no error in unsigned int, because value of size of '0' was checked in 'if' above.
        while (counter != index - 1 && counter < size) {
            current = current->next;
            counter++;
        }
        if (index - 1 != counter || current == nullptr) throw runtime_error("Cannot find the right element in insert()");

        Node *old_next = current->next;
        current->next = new Node(_data);
        current->next->next = old_next;

        size++;
    }
}

// Getter by the index
int LinkedList::at(size_t index) {
    if (index == 0) return head->data;
    else if (index >= size) throw out_of_range("Index in at() is greater than a list size");

    Node *current = head;
    size_t counter = 0;
    while (current != nullptr && counter != index) {
        current = current->next;
        counter++;
    }
    if (index != counter || current == nullptr) throw out_of_range("Cannot find the right element in at()");

    return current->data;

}

// Delete the element by index
void LinkedList::remove(size_t index) {
    if (index >= size)  throw out_of_range("Index in remove() is greater than a list size");
    else if (index == 0) {
        pop_front();
    } else if (index == size - 1) {
        pop_back();
    } else {
        Node *current = head;
        size_t counter = 0;
        while (counter != index - 1) {
            current = current->next;
            counter++;
        }
        if (current == nullptr) throw runtime_error("Cannot find the right element in remove()");

        // delete the element (not the tail or the head)
        Node *old_next = current->next->next;
        delete current->next;
        current->next = old_next;

        size--;
    }
}

// Get the list's size
size_t LinkedList::get_size() {
    return size;
}

// Print the list to the console using separator (don't use the "at()")
void LinkedList::print_to_console() {
    if (size == 0) {
        cout << "List is empty.\n";
    } else {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }
}

//Remove all list's elements
void LinkedList::clear() {
    while (size != 0) {
        pop_front();        // the fastest remove function
    }
}

// Swap the element by the index
void LinkedList::set(size_t index, int _data) {
    if (size == 0) throw logic_error("There are no elements to swap in the list.");

    if (index == 0) head->data = _data;
    else if (index >= size) throw out_of_range("Index in at() is greater than a list size");
    else if (index == size - 1) tail->data = _data;
    else {
        Node *current = head;
        size_t counter = 0;
        while (counter != index) {
            current = current->next;
            counter++;
        }
        if (current == nullptr) throw out_of_range("Cannot find the right element in set()");
        current->data = _data;
    }
}

// Check for empty list
bool LinkedList::isEmpty() {
    return size == 0;
}

// Reverse the list
void LinkedList::reverse() {
    for (size_t i = 0; i < size / 2; i++) {
        int temporary = at(i);
        size_t index_of_swappable = (size - 1) - i;
        set(i, at(index_of_swappable));
        set(index_of_swappable, temporary);
    }
}
