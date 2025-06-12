#pragma once
#include <string>

using namespace std;

class Queue {
private:
    struct Node { // Собственная структура узла
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* head;  // Первый элемент очереди
    Node* tail;  // Последний элемент очереди
    int length;  // Текущий размер очереди

public:
    Queue();
    ~Queue();

    // Основные операции
    void push(int value);// Добавление элемента в конец очереди
    int pop(); // Удаление первого элемента
    int front() const;//Вывести первый элемент
    int size() const; //Вывести размер очереди
    void clear();// Очистка очереди
    bool isEmpty() const; // Проверка на пустоту

    // Вспомогательные методы
    static bool isNumber(const string& str); // Проверка на число
    static void printWelcomeMessage();// Вывод приветствия
    static void printHelp(); // Вывод списка команд
    static void processCommand(Queue& queue, const string& command); // Реализация команд
};
