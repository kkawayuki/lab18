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
void nodeLoop(Node *&, int choice); // menu-driven program loop to assign nodes based on mode
void addHead(Node *&);
void addTail(Node *, int);
bool promptRepeat(); //checks if user wants to go again.

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    Node *head = nullptr;

    nodeLoop(head, getChoice()); // get user choice and loop based on it
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

void nodeLoop(Node *&head, int choice) // menu-driven program loop to assign nodes based on mode
{
    bool again;   // loop control
    int size = 0; // number in array

    do
    {
        if (choice = 1) // head
        {
            addHead(head);
        }

        else // add tail
        {
        }
    }
    while(promptRepeat())
}

void addHead(Node *&head) // modify where head pointer points, incremen
{
    int r;
    string buf;
    bool again;

    Node *temp = new Node;

    cout << "Enter review rating 0-5: ";
    cin >> r;
    temp->rating = r; // input validation needed

    cout << "Enter review comments: ";
    getline(cin, buf);
    temp->comment = buf;

    temp->next = head; // have new node point where head was pointing
    head = temp;       // have head point to next
}

void addTail(Node *head, int size)
{
}

bool promptRepeat()
{
    bool again = false;
    char buf;

    cout << "Enter another review? Y/N: ";
    cin >> buf;
    if(tolower())

}