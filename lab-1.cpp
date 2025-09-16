#include <iostream>
using namespace std;

struct User {
    string username;
    string password;
    User* next;

    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

bool insertUser(User*& head, const string& username, const string& password);
User* findUser(User* head, const string& username);
bool authenticate(User* head, const string& username, const string& password);
bool removeFront(User*& head);
bool removeByUsername(User*& head, const string& username);
void clearList(User*& head);
size_t size(User* head);
void printUsers(User* head);

int main() {
    User* head = nullptr;
    int choice;
    string username, password;

    do {
        cout << "\nContact List Menu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Find User\n";
        cout << "3. Remove front\n";
        cout << "4. Remove by Username\n";
        cout << "5. Clear the list\n";
        cout << "6. List Size\n";
        cout << "7. Print Users\n";
        cout << "8. Authenticate\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                insertUser(head, username, password);
                break;
            }
            case 2: {
                cout << "Enter username: ";
                getline(cin, username);
                User* user = findUser(head, username);
                if (user) {
                    cout << "User found: " << user->username << endl;
                } else {
                    cout << "User not found.\n";
                }
                break;
            }
            case 3: {
                removeFront(head);
                break;
            }
            case 4: {
                cout << "Enter username to remove: ";
                getline(cin, username);
                removeByUsername(head, username);
                break;
            }
            case 5: {
                clearList(head);
                break;
            }
            case 6: {
                cout << "List size: " << size(head) << endl;
                break;
            }
            case 7: {
                printUsers(head);
                break;
            }
            case 8: {
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                if (authenticate(head, username, password)) {
                    cout << "Authentication successful\n";
                } else {
                    cout << "Authentication failed! \n";
                }
                break;
            }
        }
    } while (choice != 9);

    clearList(head);
    return 0;
}

// -----------------------------
// Core API Implementation
// -----------------------------

bool insertUser(User*& head, const string& username, const string& password) {
    User* temp = head;
    while (temp != nullptr) {
        if (temp->username == username) {
            return false; // no duplicates
        }
        temp = temp->next;
    }

    User* newUser = new User(username, password);

    if (head == nullptr) {
        head = newUser;
    } else {
        temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newUser;
    }
    return true;
}

User* findUser(User* head, const string& username) {
    User* temp = head;
    while (temp != nullptr) {
        if (temp->username == username) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

bool authenticate(User* head, const string& username, const string& password) {
    User* user = findUser(head, username);
    return (user != nullptr && user->password == password);
}

bool removeFront(User*& head) {
    if (head == nullptr) {
        return false;
    }
    User* temp = head;
    head = head->next;
    delete temp;
    return true;
}

bool removeByUsername(User*& head, const string& username) {
    if (head == nullptr) return false;

    if (head->username == username) {
        return removeFront(head);
    }

    User* previous = head;
    User* current = head->next;

    while (current != nullptr) {
        if (current->username == username) {
            previous->next = current->next;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

void clearList(User*& head) {
    while (head != nullptr) {
        User* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

size_t size(User* head) {
    size_t counter = 0;
    User* temp = head;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

void printUsers(User* head) {
    User* temp = head;
    while (temp != nullptr) {
        cout << temp->username << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
