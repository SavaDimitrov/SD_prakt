#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class LinkedStack {
	Node<T>* top;

	Node<T>* copy(const Node<T>* other) {
		if (!other)
			return NULL;
		Node<T>* newNode = copy(other->next);
		return new Node<T>(n->data, newNode);
	}
	void clear(Node<T>* node) {
		if (!node) return;
		clear(node->next);
		delete node;
	}

public:
	bool empty();
	void push(T);
	void pop();
	T peek();

	LinkedStack();
	~LinkedStack();
	/*
	for copy and op= - need one more struct stack(tmp) ;(
	*/
	LinkedStack(const Node<T>* other);
	LinkedStack& operator=(const LinkedStack<T>& other);

};

template<typename T>
inline bool LinkedStack<T>::empty()
{
	return top == nullptr;
}

template<typename T>
inline void LinkedStack<T>::push(T _data) {
	Node<T>* newNode = new Node<T>();
	newNode->data = _data;
	newNode->next = top;

	top = newNode;
}

template<typename T>
inline void LinkedStack<T>::pop() {
	if (!empty()) {
		Node<T>* oldTop = top;
		top = top->next;
		delete oldTop;
	}
}

template<typename T>
inline T LinkedStack<T>::peek()
{
	if (!empty()) {
		return top->data;
	}
	return T();
}

template<typename T>
inline LinkedStack<T>::LinkedStack() {
	top = nullptr;
}

template<typename T>
inline LinkedStack<T>::~LinkedStack() {
	while (!empty()) {
		pop(); //this->
	}
}

template<typename T>
LinkedStack<T>::LinkedStack(const Node<T>* other) {
	copy(other);
}

template<typename T>
LinkedStack & LinkedStack<T>::operator=(const LinkedStack<T>& other) {
	if (this != &other) {
		copy(other);
	}
	return *this;
}

template<typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) {
	copy(other);
}
