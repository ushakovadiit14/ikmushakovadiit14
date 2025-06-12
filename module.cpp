#include "Header.h"
#include <iostream>
#include <cctype>

using namespace std;

Queue::Queue() : head(nullptr), tail(nullptr), length(0) {}

Queue::~Queue() {
    clear();
}

void Queue::push(int value) { // Добавление элемента в конец очереди
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

int Queue::pop() { // Удаление первого элемента
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }

    Node* temp = head;
    int value = temp->value;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    length--;
    return value;
}

int Queue::front() const { //Вывести первый элемент
    if (isEmpty()) {
        throw runtime_error("Очередь пуста");
    }
    return head->value;
}

int Queue::size() const { //Вывести размер очереди
    return length;
}

void Queue::clear() { // Очистка очереди
    while (!isEmpty()) {
        pop();
    }
}

bool Queue::isEmpty() const { // Проверка на пустоту
    return length == 0;
}

bool Queue::isNumber(const string& str) { // Проверка на число
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-') {
        if (str.length() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void Queue::printWelcomeMessage() { // Вывод приветствия
    cout << "Добро пожаловать в программу 'Очередь'\n";
    cout << "Введите 'help' для списка команд\n";
}

void Queue::printHelp() { // Вывод списка команд
    cout << "\nДоступные команды:\n";
    cout << "  push N   - Добавить число N в очередь\n";
    cout << "  pop      - Извлечь первый элемент\n";
    cout << "  front    - Показать первый элемент\n";
    cout << "  size     - Показать размер очереди\n";
    cout << "  clear    - Очистить очередь\n";
    cout << "  help     - Показать эту справку\n";
    cout << "  exit     - Выйти из программы\n\n";
}

void Queue::processCommand(Queue& queue, const string& command) { // Реализация команд
    try {
        if (command == "exit") {
            cout << "bye  (До свидания! )\n";
            exit(0);
        }
        else if (command == "help") {
            Queue::printHelp();
        }
        else if (command == "clear") {
            queue.clear();
            cout << "ok ( Очередь очищена. Текущий размер: " << queue.size() << " )\n";
        }
        else if (command == "size") {
            cout << "Текущий размер очереди: " << queue.size() << "\n";
        }
        else if (command == "front") {
            cout << "Первый элемент: " << queue.front() << "\n";
        }
        else if (command == "pop") {
            cout << "Извлечённый элемент: " << queue.pop() << "\n";
        }
        else if (command.find("push ") == 0) {
            string numStr = command.substr(5);
            if (Queue::isNumber(numStr)) {
                int num = stoi(numStr);
                queue.push(num);
                cout << "ok ( Добавлено число " << num << ". Текущий размер: " << queue.size() << " )\n";
            }
            else {
                cout << "error: '" << numStr << "' не является числом!\n";
            }
        }
        else {
            cout << "Неизвестная команда. Введите 'help' для справки.\n";
        }
    }
    catch (const exception& e) {
        cout << "error: " << e.what() << "\n";
    }
}
