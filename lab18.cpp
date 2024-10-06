// COMSC-210 | lab 17 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

// struct
struct Node
{
    int rating;
    string comment;
    Node *next; // pointer to next node in LL
};

// function prototypes
int getChoice();
void nodeLoop(int choice); // menu-driven program loop to assign nodes based on mode
void addHead(Node *);
void addTail(Node *);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    int size = 0; // initial number of items in linked list
    cout << getChoice(); //works as intended
}

// function definitions
int getChoice()
{
    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        cout << "Which linked list method should we use?\n\t[1] New nodes are added at the head of the linked list\n\t[2] New nodes are added at the tail of the linked list\n\tChoice: ";
        cin >> choice;
        if (choice != 1 && choice != 2)
            cout << "Please enter a valid value (1 or 2)\n";
    }
    return (choice);
}

void nodeLoop(int choice); // menu-driven program loop to assign nodes based on mode
void addHead(Node *);
void addTail(Node *);
