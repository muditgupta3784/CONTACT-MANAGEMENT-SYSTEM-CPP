#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Contact {
public :
       string name;
       string phone;
       
       Contact(string n, string p) {
        name = n;
        phone = p;
       }
};
void InsertionSortEngine(vector<Contact>& directory) {
    int n = directory.size();
    if (n == 1) {
        cout << "\nContact added Sucessfully!\n";
        return;
    }

    bool WasAlreadySorted = true;
    for (int i = 1; i < n; i++) {
        Contact temp = directory[i];
        int j = i-1;
        while (j >= 0 && directory[j].name > temp.name) {
            directory[j+1] = directory[j];
            j--;
            WasAlreadySorted = false;
        }
        directory[j+1] = temp;
    }
    if (WasAlreadySorted) {
        cout << "\n[INFO] Contact added! Directory was already sorted.\n";
    } else {
        cout << "\n[SUCCESS] Contact added & directory auto-sorted successfully!\n";
    }
}
int binarySearchEngine(const vector<Contact>& directory, const string& targetName) {
    int low = 0;
    int high = directory.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (directory[mid].name == targetName) {
            return mid;
     } else if (directory[mid].name < targetName) {
            low = mid + 1;
     } else {
        high = mid - 1;
     }
    }
    return -1;
}
int searchByPhoneEngine(const vector<Contact>& directory, const string& targetPhone) {
    for (size_t i = 0; i < directory.size(); i++) {
        if (directory[i].phone == targetPhone) {
            return i;
        }
    }
    return -1;
}
void displayDirectory(const vector<Contact>& directory) {
    if (directory.empty()) {
        cout << "\n[!] Directory is currently empty! Please add contacts first.\n";
    } 
    else {
        cout << "\n--- CONTACT DIRECTORY ---\n";
        for (size_t i = 0; i < directory.size(); i++) {
            cout << i + 1 << ". Name: " << directory[i].name 
                 << " | Phone: " << directory[i].phone << "\n";
        }
        cout << "-------------------------\n";
    }
}
int main() {
    vector<Contact> directory;
    int choice;

    while (true) {
        cout << "\n=== CONTACT MANAGEMENT SYSTEM ===\n";
        cout << "1. Add New Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact (by Name or Phone)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        
        cin >> choice;

        if (choice == 1) {
            string name, phone;
            cout << "\nEnter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Phone: ";
            getline(cin, phone);

            directory.push_back(Contact(name, phone));
            InsertionSortEngine(directory);

        } 
        else if (choice == 2) {
            displayDirectory(directory);

        } 
        else if (choice == 3) {
            if (directory.empty()) {
                cout << "\n[!] Directory is empty! Please add contacts first.\n";
            } else {
                int searchChoice;
                cout << "\nSearch Options:\n";
                cout << "1. Search by Name (Binary Search - O(log n))\n";
                cout << "2. Search by Phone Number (Linear Search - O(n))\n";
                cout << "Enter search choice (1-2): ";
                cin >> searchChoice;

                if (searchChoice == 1) {
                    string searchName;
                    cout << "\nEnter Name to Search: ";
                    cin.ignore();
                    getline(cin, searchName);

                    int index = binarySearchEngine(directory, searchName);
                    if (index != -1) {
                        cout << "\n[MATCH FOUND] Name: " << directory[index].name 
                             << " | Phone: " << directory[index].phone << "\n";
                    } else {
                        cout << "\n[NOT FOUND] No contact matches name: " << searchName << "\n";
                    }
                } 
                else if (searchChoice == 2) {
                    string searchPhone;
                    cout << "\nEnter Phone Number to Search: ";
                    cin.ignore();
                    getline(cin, searchPhone);

                    int index = searchByPhoneEngine(directory, searchPhone);
                    if (index != -1) {
                        cout << "\n[MATCH FOUND] Name: " << directory[index].name 
                             << " | Phone: " << directory[index].phone << "\n";
                    } else {
                        cout << "\n[NOT FOUND] No contact matches phone: " << searchPhone << "\n";
                    }
                } 
                else {
                    cout << "\n[INVALID] Invalid search choice!\n";
                }
            }

        } 
        else if (choice == 4) {
            cout << "\nExiting Program... Thank you!\n";
            break;

        } 
        else {
            cout << "\n[INVALID] Please enter a valid choice (1-4).\n";
        }
    }

    return 0;
}
