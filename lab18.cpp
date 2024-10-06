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
void nodeLoop(Node *, int choice); // menu-driven program loop to assign nodes based on mode
void addHead(Node *&, int);
void addTail(Node *, int);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    int size = 0; 
    Node *head = nullptr;

    nodeLoop(head, getChoice()); //get user choice and loop based on it
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

void nodeLoop(Node *head, int choice) // menu-driven program loop to assign nodes based on mode
{
    bool again; //loop control

    if(choice = 1) // head
    {
        
    }

    else // add tail
    {

    }
}

void addHead(Node *&head, int size) //modify where head pointer points
{
    Node *temp = new Node;

    cout << "Enter review rating 0-5: ";
    cout << "Enter review comments: ";
    cout << "Enter another review? Y/N: ";
}

void addTail(Node *head, int size)
{

}
