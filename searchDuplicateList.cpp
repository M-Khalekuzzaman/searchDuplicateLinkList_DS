#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;

    //Constructor declare
    Node(int data)
    {
        this -> data = data;
        this -> Next = NULL;
    }
};
struct Test
{
    int position[1000];
};
//function declare part
void printLinkList();
void insertionAtHead();
void insertionAtTail();
void insertionAtPosition();

void insertionAtHead(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *save_previous_node = head;
    newNode->Next = save_previous_node;
    head = newNode;
}
void insertionAtTail(Node* &head,int value)
{
    Node *newNode = new Node(value);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->Next != NULL)
    {

        temp = temp->Next;
    }
    temp->Next = newNode;
}
void insertionAtPosition(Node* &head,int value,int pos)
{
    Node *newNode = new Node(value);
    if(pos == 1)
    {
        Node *save_node = head;
        newNode->Next = save_node;
        head = newNode;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1; i<pos; i++)
    {
        temp = temp->Next;
    }
    Node *save = temp->Next;
    temp->Next = newNode;
    newNode->Next = save;
}
void deletionAtPosition(Node* &head,int pos)
{
    if(pos == 1)
    {
        Node *save_node = head;
        Node *save = save_node->Next;
        head = save;
        delete save_node;
        return;
    }
    pos--;
    Node *temp = head;
    for(int i = 1; i<pos; i++)
    {
        temp = temp->Next;
    }
    temp->Next = temp->Next->Next;
}
int countLength(Node* &head)
{
    int count = 1;
    Node *temp = head;
    while(temp->Next != NULL)
    {
        temp = temp->Next;
        count++;
    }

    return count;
}
void searchAtDuplicatePosition(Node* &head,int searchVal)
{
    if(head == NULL)
    {
        cout<<"Search value is not yet at the list"<<endl;
        return;
    }
    int size = countLength(head);
    int keepPosition[size+1],k = 1,count = 1;
    Node *temp = head;
    bool found = false;
    while(temp != NULL)
    {
        int val = temp->data;
        if(val == searchVal)
        {
            keepPosition[k] = count;
            found = true;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    keepPosition[0] = k;
    if(found == false)
    {
        cout<<"Search value is not yet at the list"<<endl;
    }
    else
    {
        cout<<"Find at position : ";
        for(int i = 1; i<keepPosition[0]; i++)
        {
            cout<<keepPosition[i]<<" ";
        }
        cout<<endl;
    }

}
struct Test searchValueAtPositionReturn(Node* &head,int searchVal)
{

    int k = 1,count = 1;
    struct Test T;
    Node *temp = head;
    while(temp != NULL)
    {
        int val = temp->data;
        if(val == searchVal)
        {
            T.position[k] = count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0] = k;

    return T;

}
void insertAfterSpecificValue(Node* &head,int value,int insert_value)
{
    Node *temp = head;
    int count = 1,save;
    while(temp->Next != NULL)
    {
        int val = temp->data;
        if(val == value)
        {
            save = count;
        }
        temp = temp->Next;
        count++;
    }
    insertionAtPosition(head,insert_value,save+1);
}
void printLinkList(Node* &head)
{
    Node *currentNode = head;
    while(currentNode != NULL)
    {
        cout<<currentNode->data;
        if(currentNode->Next != NULL) cout<<" -> ";
        currentNode = currentNode->Next;
    }
    cout<<endl;
}
int main()
{
    Node *head = NULL;
    cout<<"Choice 1 : Insertion at Head"<<endl;
    cout<<"Choice 2 : Insertion at Tail"<<endl;
    cout<<"Choice 3 : Insertion at any Position"<<endl;
    cout<<"Choice 4 : Deletion at any Position"<<endl;
    cout<<"Choice 5 : Search a value"<<endl;
    cout<<"Choice 6 : Insertion after a specific value"<<endl;
    cout<<"Choice 0 : Exit"<<endl<<endl;
    int value,pos,searchValue,choice = 2;
    while(choice != 0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter your value : ";
            cin>>value;
            insertionAtHead(head,value);
            break;
        case 2:
            cout<<"Enter your value : ";
            cin>>value;
            insertionAtTail(head,value);
            break;
        case 3:
            cout<<"Enter your value & pos : ";
            cin>>value>>pos;
            insertionAtPosition(head,value,pos);
            break;
        case 4:
            cout<<"Enter your position : ";
            cin>>pos;
            deletionAtPosition(head,pos);
            break;
        case 5:
            cout<<"Enter your value you want to search : ";
            cin>>searchValue;
            struct Test T;
            //searchAtDuplicatePosition(head,searchValue);
            T = searchValueAtPositionReturn(head,searchValue);
            if(T.position[0] == 1)
            {
                cout<<"Search value is not yet at the list"<<endl;
            }
            else
            {
                int size = T.position[0];
                cout<<"Find at position : ";
                for(int i = 1; i<size; i++)
                {
                    cout<<T.position[i]<<" ";
                    if(i<size-1) cout<<",";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout<<"Enter your value : ";
            cin>>value;
            cout<<"Insert value after specific value : ";
            int insert_value;
            cin>>insert_value;
            insertAfterSpecificValue(head,value,insert_value);
            break;

        default:
            break;
        }
        cout<<"Next Choice : ";
        cin>>choice;
    }
    // cout<<"Length : "<<countLength(head)<<endl;
    printLinkList(head);




    return 0;
}



