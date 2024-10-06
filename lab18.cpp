// COMSC-210 | lab 18 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

// struct
struct Node
{
    double rating;
    string comment;
    Node *next; // pointer to next node in LL
};

// function prototypes
int getChoice();
void nodeLoop(Node *&, int choice); // menu-driven program loop to assign nodes based on mode
void addHead(Node *&);
void addTail(Node *&);
bool promptRepeat(); // checks if user wants to go again.
void averagePrintAll(Node *);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    Node *head = nullptr;
    nodeLoop(head, getChoice()); // get user choice and loop based on it
}

/************************************************
 * Function: Prompts and verifies, before returning
 * a user value corresponding to which linked list
 * method to use.
 *
 * Parameters: NONE
 * Return: choice, a 1 or 2 based on user preference
 * of adding to front/back
 ************************************************/
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

/************************************************
 * Function: Main control loop of the program,
 * facilitates calls to relevant functions.
 *
 * Parameters:
 * *&head, the pointer to the head of the
 * linked list, passed by reference because some
 * functions need to be able to alter the pointer.
 *
 * choice, integer value corresponding to method
 * preference
 *
 * Return: NONE
 ************************************************/
void nodeLoop(Node *&head, int choice) 
{
    do
    {
        if (choice == 1) // head
        {
            addHead(head);
        }

        else if (choice == 2) // add tail
        {
            addTail(head);
        }
    } while (promptRepeat()); 

    averagePrintAll(head); // output all at end
}

/************************************************
 * Function: adds a node to the front of the LL
 * defined in main()
 *
 * Parameters:
 * *&head, the pointer to the head of the
 * linked list, passed by reference so it can be
 * reassigned to point at the new head at the end
 * of the run.
 * Return: NONE
 ************************************************/
void addHead(Node *&head) 
{
    double r = -1;
    string buf;
    bool again;

    Node *temp = new Node;

    while (r < 0 || r > 5)
    {
        cout << "Enter review rating 0-5: ";
        cin >> r;
        if (r < 0 || r > 5)
            cout << "Please enter a valid rating (0-5, decimals okay)\n";
    }
    temp->rating = r;

    cin.ignore(100, '\n'); // clear input before getline
    cout << "Enter review comments: ";
    getline(cin, buf);
    temp->comment = buf;

    // assignment
    temp->next = head; // have new node point where head was pointing
    head = temp;       // have head point to next
}

/************************************************
 * Function: adds a node to the tail (end) of the LL
 * defined in main()
 *
 * Parameters:
 * *&head, the pointer to the head of the
 * linked list, passed by reference so it can be
 * reassigned to point at the new node (in the case
 * that there are no existing nodes.)
 * Return: NONE
 ************************************************/
void addTail(Node *&head)
{
    double r = -1;
    string buf;
    bool again;

    Node *temp = new Node;

    while (r < 0 || r > 5)
    {
        cout << "Enter review rating 0-5: ";
        cin >> r;
        if (r < 0 || r > 5)
            cout << "Please enter a valid rating (0-5, decimals okay)\n";
    }

    temp->rating = r;

    cin.ignore(100, '\n'); // clear input before getline
    cout << "Enter review comments: ";
    getline(cin, buf);
    temp->comment = buf;
    temp->next = nullptr;

    Node *current = head;

    if (head == nullptr) // case LL empty
        head = temp;
    else
    {
        while (current->next != nullptr)
        {
            current = current->next; // iterate through
        }
        current->next = temp; // make last one temp
    }
}

/************************************************
 * Function: asks user if they want to continue
 * looping or not, returning a boolean value based
 * on this.
 *
 * Parameters: NONE
 * Return: NONE
 ************************************************/
bool promptRepeat()
{
    string buf;

    while (true)
    {
        cout << "Enter another review? Y/N: ";
        cin >> buf;
        if (tolower(buf[0]) == 'y')
        {
            return (true);
            break;
        }
        else if (tolower(buf[0]) == 'n')
        {
            return (false);
            break;
        }
        else
        {
            cout << "Please enter a valid response, (Y/N).\n";
        }
    }
}

/************************************************
 * Function: loops through the linked list, averaging
 * and printing the values correspondent to the Nodes.
 *
 * Parameters: *head, pointer to the head of the LL
 * so that the function can iterate through, averaging
 * and printing the values correspondent to the Nodes.
 * Return: NONE
 ************************************************/
void averagePrintAll(Node *head)
{
    double avg;
    int i = 0;

    while (head) // while head not nullptr
    {
        cout << "\t> Review #" << i + 1 << ": " << head->rating << ": " << head->comment << '\n'; // i+1 for formatting, starts at 1 in output
        avg += head->rating;
        head = head->next; // go to next element in linked list
        i++;               // increment
    }
    cout << "\t> Average: " << (avg / i) << '\n';
}