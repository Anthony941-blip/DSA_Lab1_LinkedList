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
	User* temp = head;
        while(temp != nullptr) {
           if(temp->username == username) {
            return false;
         }
	 temp = temp->next;
      }

	User* newUser = new User(username, pasword);

	if(head == nullptr) {
		head = newUser;
	} else {
	   temp = head;
	   while (temp->next !=nullptr) {
		temp = temp->next;
       }
	temp->next = newUser;
    }
	return true;
  }

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {
    // TODO: implement
    User* temp = head;

    while(temp != nullptr) {
		if(temp->username == username) {
			return temp;
           }
            	temp = temp->next;
}
    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
    // TODO: implement

   User* user = findUser(head,username);
	if(user == nullptr) {
 	   return false;
	}
              if(user->password == password) {
		return true;
        }
		return false;
    }

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // TODO: implement
    if(head == nullptr) {
   	 return false;
   }else{
    User* temp = head;
    head = head->next;
    delete temp;
    return true;
  }
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
	if(head == nullptr) {
		return false;
       }
	if(head->username  == username) {
		return removeFront(head);
       }

      User* previous = head;
      User* current = head->next;

	while(current != nullptr) {

	  if(current->username == username) {

	   previous->next = current->next;
	   delete current;
	   return true;
        }
	  previous = current;
	  current = current->next;
      }

      return false;
}
// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    // TODO: implement

    while(head != nullptr) {
	User* temp = head;
	head = head->next;
	delete temp;
  }
	head = nullptr;
}

// Returns number of nodes.
size_t size(User* head) {
    // TODO: implement
    User* temp = head;
    size_t counter = 0;
	while(temp != nullptr) {
		counter++;
		temp = temp->next;
     }
    return counter;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // TODO: implement
    User* temp = head;
    cout << "Head: " << head << " -> ";
	while(temp != nullptr) {
		cout << temp->username << " -> ";
		temp = temp->next;
      }
		cout << " NULL";
}


