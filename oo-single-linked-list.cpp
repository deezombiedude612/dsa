#ifndef OO_SINGLE_LINKED_LIST_CPP
#define OO_SINGLE_LINKED_LIST_CPP

#include <iostream>
#include <string>
using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int d, Node* n) {
            data = d;
            next = n;
        }
        Node(int d) {
            data = d;
            next = NULL;
        }

        ~Node() {
            next = NULL;
            delete next;
        }

        int getData() {
            return data;
        }
        void setData(int d) {
            data = d;
        }
        Node *getNext() {
            return next;
        }
        void setNext(Node* n) {
            next = n;
        }
};

Node *createList(Node *);
void displayList(Node *);
int listSize(Node *);
void addNode(Node *, int);

int menu_option() {
    int option;

    cout << "\nOO SINGLE-LINKED LIST";
    cout << "\n****************************************";
    cout << "\n1.\tCreate a list";
    cout << "\n2.\tDisplay List";
    cout << "\n3.\tCount List Elements";
    cout << "\n4.\tAdd Node at the End";

    cout << "\n\nEnter an option (-1 to exit) >> ";
    cin >> option;

    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 0;
    }

    return option;
}

int main(int argc, char **argv) {
    Node *head = NULL;
    int option, data, pos;

    do {
        option = menu_option();
        switch(option) {
            case 1:
                head = createList(head);
                cout << "\n***** SINGLE LINKED LIST CREATED *****\n";
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                cout << "\nList size: " << listSize(head) << endl;
                break;

            case 4:
                if(!head) cout << "Create a list first!\n";
                else {
                    while(true) {
                        cout << "\nEnter data >> ";
                        cin >> data;

                        if(cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        } else break;
                    } 
                    addNode(head, data);
                }
                break;
            
            default:
                if(option != -1) printf("\nInvalid option entered. Try again.\n");
        }
    } while(option != -1);

    cout << "\nGOODBYE\n\n";

    return 0;
}

Node *createList(Node *head) {
    Node *newNode;
    string cont;
    int data;

    cin.get();
    do {
        cout << "\nDo you wish to continue? (Y/N) >> ";
        getline(cin, cont);
    } while(cont != "Y" && cont != "y" && cont != "N" && cont != "n");

    while(cont != "N" && cont != "n") {
        while(true) {
            cout << "Enter data >> ";
            cin >> data;

            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }

        newNode = new Node(data);
        if(!head) head = newNode;
        else {
            Node *ptr = head;
            while(ptr->getNext()) ptr = ptr->getNext();
            ptr->setNext(newNode);
            ptr = NULL;
            delete ptr;
        }

        cout << "\nList now: ";
        displayList(head);

        cin.get();
        do {
            cout << "\nDo you wish to continue? (Y/N) >> ";
            getline(cin, cont);
        } while(cont != "Y" && cont != "y" && cont != "N" && cont != "n");
    }

    return head;
}

void displayList(Node *cur) {
    if(!cur) cout << "\nList is empty.\n";
    else {
        while(cur) {
            cout << cur->getData() << " ";
            cur = cur->getNext();
        }
    }
    cout << endl;
}

int listSize(Node *cur) {
    int size;
    for(size = 0; cur != NULL; cur = cur->getNext()) size++;

    return size;
}

void addNode(Node *cur, int n) {
    Node *newNode = new Node(n);
    while(cur->getNext()) cur = cur->getNext();
    cur->setNext(newNode);
}

#endif  // OO_SINGLE_LINKED_LIST_CPP