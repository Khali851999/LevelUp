#include <bits/stdc++.h>
using namespace std;
class LinkedList
{
public:
    class Node
    {
    public:
        int data = 0;
        Node *next = nullptr;

        Node(int data)
        {
            this->data = data;
        }
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void addFirst(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        size++;
    }

    int removeFirst()
    {
        if (size == 0)
        {
            cout << "Underflow " << endl;
            return -1;
        }

        Node *temp = head;
        head = head->next;

        delete (temp);
        size--;
        return 1;
    }

    void addLast(int data)
    {
        Node *node = new Node(data);

        if (size == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
        size++;
    }

    int removeLast()
    {
        if (size == 0)
        {
            cout << "Underflow " << endl;
            return -1;
        }
        else if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *secondLastNode = getNodeAt(size - 2);
            delete (tail);
            tail = secondLastNode;
        }
        size--;
        return 1;
    }

    Node *getNodeAt(int pos)
    {
        if (pos < 0 || pos > size - 1)
        {
            cout << "Invalid Position" << endl;
            return nullptr;
        }
        else if (pos == 0)
            return head;
        else if (pos == size - 1)
            return tail;
        else
        {
            Node *temp = head;
            while (temp != nullptr && pos-- > 0)
                temp = temp->next;

            return temp;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
            cout << temp->data << "->";
        cout << endl;
    }
};

int main()
{

    LinkedList linkedlist;
    linkedlist.addFirst(5);
    cout<<linkedlist.getSize()<<linkedlist.;
    // linkedlist.print();
    return 0;
}