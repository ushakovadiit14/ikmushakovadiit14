#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    Queue queue;
    Queue::printWelcomeMessage();


    string command;
    while (true) {
        cout << "\nВведите команду > ";
        getline(cin, command);
        Queue::processCommand(queue, command);
    }

    return 0;
}
