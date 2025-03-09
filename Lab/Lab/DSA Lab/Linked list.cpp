#include <iostream>
using namespace std;

struct Node
{
    int age;
    float grade;
    Node *next;
};
struct DNode{
    int age;
    float grade;
    Node *next;
    Node *prev;
}
class LinkedList
{
    // Pointer to the first node in the list
    Node *head;

public:
    // Constructor initializes head to NULL (everytime an object is instantiated)
    LinkedList() : head(NULL) {}

    void insert_beg(int age_val, float gpa)
    {
        Node *node = new Node();
        node->age = age_val;
        (*node).grade = gpa;
        node->next = NULL; // intially points to nosino
        if (head == NULL)
        {
            head = node; // both are pointers of type "node"
        }
        else
        {
            node->next = head; // new node points to what ever the head is pointing to (first node)
            head = node;       // start pointer (head) pointed to node (first one)
        }
    }

    void insert_end(int age_val, float gpa)
    {
        Node *newNode = new Node();
        newNode->age = age_val;
        newNode->grade = gpa;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp;
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertRpos(int age_val, float gpa, int pos)
    {
        Node *newNode = new Node();
        newNode->age = age_val;
        newNode->grade = gpa;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            int count = 1;
            Node *temp;
            temp = head;
            while (count != pos && temp->next != NULL)
            {
                count++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void insert_pos(int age_val, float gpa, int pos)
    {
        Node *newNode = new Node();
        newNode->age = age_val;
        newNode->grade = gpa;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else if (pos == 1)
        {
            insert_beg(age_val, gpa);
        }
        else
        {
            int count=1;
            Node *curr, *prev;
            curr = head;
            while (curr->next != NULL && count != pos)
            {
                count++;
                prev = curr;
                curr = curr->next;
            }
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }

    void delete_beg()
    {
        Node *currN;
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }
        else if (head->next == NULL)
        {
            currN = head;
            head = NULL;
            delete currN;
        }
        else
        {
            currN = head;
            head = head->next;
            delete currN;
        }
    }

    void delete_end()
    {
        Node *curr, *prev;
        if (head == NULL)
        {
            cout << "List is empty!";
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            curr = head;
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
        }
    }

    void delete_pos(int pos)
    {
        Node *curr, *prev;
        if (head == NULL)
        {
            cout << "List empty!";
            return;
        }
        else if (pos == 1)
        {
            delete_beg();
            return;
        }
        else
        {
            int count;
            curr = head;
            while (curr->next != NULL && count != pos - 1)
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
            prev->next = curr->next;
            delete curr;
        }
    }

    void display()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp)
        {
            cout << "(" << temp->age << "|" << temp->grade << ")" << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list1;
    list1.display();
    list1.insert_beg(20, 3.5);
    list1.display();
    list1.insert_beg(22, 3.9);
    list1.display();
    list1.insertRpos(21, 3.6, 2);
    list1.display();
    list1.insertRpos(21, 3.9, 2);
    list1.display();
    list1.insert_pos(22, 4.0, 2);
    list1.display();
    list1.delete_beg();
    list1.display();
    list1.delete_end();
    list1.display();
    list1.delete_pos(3);
    list1.display();

    list1.display();

    return 0;
}