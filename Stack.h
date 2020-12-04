#pragma once

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
struct Node {
    T value;
    int next;
    Node();
    Node(const int& value_, const int& next_);
};

template<typename T>
Node<T>::Node() {
    value = 0;
    next = -1;
}

template<typename T>
Node<T>::Node(const int &value_, const int &next_) {
    value = value_;
    next = next_;
}


template <typename T>
class Stack{
private:
    Node<T>* stack;
    int n;
    int b;
    int bFree;
    int size;
public:
    explicit Stack(const int& n_) {
        n = n_;
        stack = new Node<T>[n];
        size = 0;
        b = -1;
        bFree = 0;
        for (int i = 0; i < n; i++)
            stack[i].next = i + 1;
        stack[n - 1].next = -1;
    }

    void Extend() {
        Node<T>* new_stack = new Node<T>[2 * n];
        for (int i = 0; i < n; i++) {
            new_stack[i] = stack[i];
        }
        delete[] stack;
        stack = new_stack;
        bFree = n;
        for (int i = n; i < 2 * n; i++) {
            stack[i].next = i + 1;
        }
        stack[2 * n - 1].next = -1;
        n *= 2;
    }

    void Push(const T& value) {
        int nextFree = stack[bFree].next;
        stack[bFree].value = value;
        stack[bFree].next = b;
        b = bFree;
        bFree = nextFree;
        size++;
        if (bFree == -1)
            Extend();
    }

    T Pop() {
        T del = stack[b].value;
        int nextB = stack[b].next;
        stack[b].next = bFree;
        bFree = b;
        b = nextB;
        size--;
        return del;
    }

    void Print() const {
        int p = b;
        while (p != -1) {
            cout << stack[p].value << " ";
            p = stack[p].next;
        }
        cout << endl;
    }

    void operator<< (const int& value) {
        Push(value);
    }

    void operator>> (int& del) {
        del = Pop();
    }

    void operator=(vector<T>& r){
        for(int i = 0; i < n; i++){
            stack[i].value = r[i];
        }
    }

    T operator[] (const int& index) {
        int p = b;
        int idx = 0;
        while (p != -1) {
            if (idx == index)
                break;
            p = stack[p].next;
            idx++;
        }
        return stack[p].value;
    }

    vector <T> ToVector() const {
        vector <T> ans;
        int p = b;
        while (p != -1) {
            ans.push_back(stack[p].value);
            p = stack[p].next;
        }
        return ans;
    }

    bool operator== (const Stack<T>& r) {
        return ToVector() == r.ToVector();
    }

    bool operator<(const Stack<T>& r){
        if (ToVector() < r.ToVector()){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator>(const Stack<T>& r){
        if (ToVector() > r.ToVector()){
            return true;
        }
        else{
            return false;
        }
    }
};
