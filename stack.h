#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    T* s;
    int e = 0;
    int n = 0;

    void Extend();
    void Swap(Stack<T>& r);

public:
    Stack();
    explicit Stack(const int& n_);
    Stack(std::initializer_list<T> l);
    Stack(const Stack<T>& st);
    Stack(Stack<T>&& st) noexcept;

    void Push(const T& value);
    Stack<T>& operator<< (const T& value);

    T Pop();
    Stack<T>& operator>> (T& value);

    Stack<T>& operator= (const Stack<T>& st);
    Stack<T>& operator= (Stack<T>&& st) noexcept;

    T& operator[] (size_t index);
    const T& operator[] (size_t index) const;

    std::vector<T> ToVector() const;

    T& Top();
    const T& Top() const;
    bool isEmpty() const;

    bool operator< (const Stack<T>& r) const;
    bool operator>= (const Stack<T>& r) const;
    bool operator> (const Stack<T>& r) const;
    bool operator<= (const Stack<T>& r) const;
    bool operator== (const Stack<T>& r) const;
    bool operator!= (const Stack<T>& r) const;

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack) {
        std::vector <T> a = stack.ToVector();
        for (auto& i : a)
            os << i << " ";
        return os;
    }

    ~Stack();
};

template <typename T>
void Stack<T>::Extend() {
    T* new_s = new T[2 * n];
    for (int i = 0; i < n; i++)
        new_s[i] = s[i];
    delete[] s;
    s = new_s;
    n *= 2;
}

template <typename T>
void Stack<T>::Swap(Stack<T> &r) {
    std::swap(r.s, s);
    std::swap(r.n, n);
    std::swap(r.e, e);
}

template <typename T>
Stack<T>::Stack(const int& n_) : n(n_) {
    s = new T[n];
}

template <typename T>
Stack<T>::Stack() : Stack(10) {}

template <typename T>
Stack<T>::Stack(std::initializer_list<T> l) : Stack(l.size() + 1) {
    for (const T& i : l)
        Push(i);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& st) : Stack(st.n) {
    e = st.e;
    for (int i = 0; i < n; i++)
        s[i] = st.s[i];
}

template <typename T>
Stack<T>::Stack(Stack<T>&& st) noexcept {
    s = st.s;
    e = st.e;
    n = st.n;
    st.s = nullptr;
    st.e = st.n = 0;
}

template <typename T>
void Stack<T>::Push(const T& value) {
    if (e == n)
        Extend();
    s[e++] = value;
}

template <typename T>
Stack<T>& Stack<T>::operator<< (const T& value) {
    Push(value);
    return *this;
}

template <typename T>
T Stack<T>::Pop() {
    if (e == 0)
        throw std::exception();
    return s[--e];
}

template <typename T>
Stack<T>& Stack<T>::operator>> (T& value) {
    value = Pop();
    return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> &st) {
    if (&st == this)
        return *this;
    Stack<T> t(st);
    Swap(t);
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator= (Stack<T>&& st) noexcept {
    if (&st == this)
        return *this;
    Stack<T> t(move(st));
    Swap(t);
    return *this;
}

template <typename T>
T& Stack<T>::operator[] (size_t index) {
    if (index >= e)
        throw std::exception();
    return s[index];
}

template <typename T>
const T& Stack<T>::operator[] (size_t index) const {
    if (index >= e)
        throw std::exception();
    return s[index];
}

template <typename T>
std::vector<T> Stack<T>::ToVector() const {
    std::vector<T> v(e);
    for (int i = 0; i < e; i++)
        v[i] = s[i];
    return v;
}

template <typename T>
T& Stack<T>::Top() {
    if (e == 0)
        throw std::exception();
    return s[e - 1];
}

template <typename T>
const T& Stack<T>::Top() const {
    if (e == 0)
        throw std::exception();
    return s[e - 1];
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return e == 0;
}

template <typename T>
bool Stack<T>::operator< (const Stack<T>& r) const {
    return ToVector() < r.ToVector();
}
template <typename T>
bool Stack<T>::operator>= (const Stack<T>& r) const {
    return !operator<(r);
}
template <typename T>
bool Stack<T>::operator> (const Stack<T>& r) const {
    return ToVector() > r.ToVector();
}
template <typename T>
bool Stack<T>::operator<= (const Stack<T>& r) const {
    return !operator>(r);
}
template <typename T>
bool Stack<T>::operator== (const Stack<T>& r) const {
    return ToVector() == r.ToVector();
}
template <typename T>
bool Stack<T>::operator!= (const Stack<T>& r) const {
    return !operator==(r);
}

template <typename T>
Stack<T>::~Stack() {
    delete[] s;
}

