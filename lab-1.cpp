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
  bool removeFront(User*& head);
  bool removeByUsername(User*& head, const string& username);
  void clearList(User*& head);
  size_t size(User* head);
  void printUsers(User* head);

    int main() {

	return 0;
   }
// -----------------------------
// Core API — implement these
// -----------------------------

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {
    // TODO: implement
   
    return false;
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {
    // TODO: implement
    
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    // TODO: implement
   
    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // TODO: implement
    
    return false;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
    // TODO: implement
    
    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    // TODO: implement
    
}

// Returns number of nodes.
size_t size(User* head) {
    // TODO: implement
    
    return 0;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // TODO: implement
    
}


