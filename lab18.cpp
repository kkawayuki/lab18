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
void addTail(Node *);
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

    do
    {
        if (choice == 1) // head
        {
            addHead(head);
        }

        else // add tail
        {
            addTail(head);
        }
    } 
    while (promptRepeat()); //works? 

    averagePrintAll(head); //output all at end
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

    cin.ignore(100, '\n'); //clear input before getline
    cout << "Enter review comments: ";
    getline(cin, buf);
    temp->comment = buf;

    //assignment
    temp->next = head; // have new node point where head was pointing
    head = temp;       // have head point to next
}

void addTail(Node *head)
{
    int r;
    string buf;
    bool again;

    Node *temp = new Node;

    cout << "Enter review rating 0-5: ";
    cin >> r;
    temp->rating = r; // input validation needed

    cin.ignore(100, '\n'); //clear input before getline
    cout << "Enter review comments: ";
    getline(cin, buf);
    temp->comment = buf;

    //position in linked list
    Node *temp = head;

    while(temp->next != nullptr)
        temp = temp->next; //iterate thorugh linked list

    temp->next = nullptr; //as last member in linked list
}

bool promptRepeat()
{
    bool again = false;
    char buf;

    while (true)
    {
        cout << "Enter another review? Y/N: ";
        cin >> buf;
        if (tolower(buf) == 'y')
        {
            return (true);
            break;
        }
        else if(tolower(buf) == 'n')
        {
            return(false);
            break;
        }
        else
        {
            cout << "Please enter a valid response, (Y/N).\n";
        }
    }
}

void averagePrintAll(Node *head)
{
    double avg;
    int i = 0;

    while(head->next != nullptr)
    {
        cout << "\t> Review #" << i << ": " << head->rating << ": " << head->comment << '\n'; 
        avg += head->rating;
        head = head->next; // go to next element in linked list
        i++; //increment
    }
    cout << "\t> Average: " << (avg/i) << '\n';
}