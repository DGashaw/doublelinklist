#include<iostream>

using namespace std;

template<class Type>
struct Link
{
    Type data;
    Link* next;
    Link* prev;
};

template<class Type>
class DoubleLinkList
{
    private:
        Link<Type>* head;
        Link<Type>* tail;
        int count; // for counting the number of elements in the linked list

    public: 
        //Constructor
        DoubleLinkList();
        //Function to add the head of the list
        void addToHead(Type value);
        //Function that add to the tail of the list
        void addToTail(Type value);
        //Function that returns the last node of the link list
        Link<Type>* findLastNode();
        //Function that returns a specific node with a given value if exist in the list
        Link<Type>* searchNode(Type value);
        //Function that deletes a specific node with a given value if exist in the list
        void deleteNode(Type value);
        //Function that displays the list in forward direction (starting from the head)
        void display() const;
        //Function that displays the list in reverse direction (starting from the tail)
        void reverseDisplay() const;
        //Function that returns a reversed double link list
        DoubleLinkList<Type>* reverese();
        //Overloaded subscript operator to access the double link list with index
        Type& operator [] (int j)
        {
            Link<Type>* node = new Link<Type>;

            node = head;
            if(j < size())
            {
                for(int i = 0; i < j; i++)
                    node = node->next;
                //indexData = node->data;
            }

            return node->data;

            
        }
        //Function that returns the number of elemnts in the linked list
        int size()
        {
            return this->count;
        }

};

template<class Type>
DoubleLinkList<Type>::DoubleLinkList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template<class Type>
void DoubleLinkList<Type>::addToHead(Type value)
{
    Link<Type>* newLink = new Link<Type>;
    newLink->data = value;

    //check if the link list is empty
    if(head == NULL)
    {
        newLink->next = head;
        newLink->prev = NULL;
        head = newLink;
    }

    //adding a new link in the middle
    else
    {
        newLink->next = head;
        head->prev = newLink;
        newLink->prev = NULL;
        

        head = newLink;
    }

    count += 1;
}

template<class Type>
void DoubleLinkList<Type>::addToTail(Type value)
{
    Link<Type>* newLink = new Link<Type>;
    Link<Type>* temp = new Link<Type>;
    newLink->data = value;

    if(tail == NULL)
    {
        temp = findLastNode();
        temp->next = newLink;
        newLink->prev = temp;
        newLink->next = NULL;
        tail = newLink;
    }

    else
    {
        tail->next = newLink;
        newLink->prev = tail;
        newLink->next = NULL;
        tail = newLink;
    }

    count += 1;

}

template<class Type>
Link<Type>* DoubleLinkList<Type>::findLastNode()
{
    Link<Type>* temp = new Link<Type>;
    temp = head;

    while(temp != NULL)
    {
        if(temp->next == NULL)
            break;
        temp = temp->next;
    }

    return temp;
}

template<class Type>
Link<Type>* DoubleLinkList<Type>::searchNode(Type value)
{
    Link<Type>* node = new Link<Type>;
    node = head;

    while(node != NULL)
    {
        if(node->data == value)
            break;
        node = node->next;
    }

    return node;
}

template<class Type>
void DoubleLinkList<Type>::deleteNode(Type value)
{
    Link<Type>* temp = new Link<Type>;
    temp = searchNode(value);

    //Delete the first node which has data = value as long if it exist
    if(temp != NULL)
    {
        if(temp == head)
        {
            head = temp->next;
            head->prev = NULL;
            delete temp;
        }
        else if(temp == tail)
        {
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
        }

        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }

        this->count -= 1; // decrease the size of the double linked list
        //May be throw an exception if the value that is been looking for don't exist in the list

            }
}
template<class Type>
DoubleLinkList<Type>* DoubleLinkList<Type>::reverese()
{
    DoubleLinkList<Type>* list = new DoubleLinkList<Type>();
    Link<Type>* temp = new Link<Type>;

    temp = head;
    while(temp != NULL)
    {
        list->addToHead(temp->data);
        temp = temp->next;
    }

    return list;
}

/*
template<class Type>
Type& DoubleLinkList<Type>::operator[] (int index)
{
    Link<Type>* node = new Link<Type>;
    node = head;
    if(index < size())
    {
        for(int i = 0; i < index; i++)
            node = node->next;
    }

    return node->data;
}
*/

template<class Type>
void DoubleLinkList<Type>::display() const
{
    Link<Type>* temp = new Link<Type>;
    temp = head;

    cout << "[";
    while(temp!= NULL)
    {
        if(temp->next == NULL)
            cout << temp->data;
        else
            cout << temp->data << ",";
        temp = temp->next;
    }

    cout << "]";
}
template<class Type>
void DoubleLinkList<Type>::reverseDisplay() const
{
    Link<Type>* temp = new Link<Type>;
    temp = tail;
    
    cout << "[";
    while(temp != NULL)
    {
        if(temp->prev == NULL)
            cout << temp->data;
        else
            cout << temp->data << ",";
        temp = temp->prev;
    }

    cout << "]";
}



int main()
{
    DoubleLinkList<int> dl;
    int value, index;
    char ch;
    dl.addToHead(5);
    dl.addToHead(8);
    dl.addToHead(10);
    dl.addToTail(-1);
    dl.addToTail(54);

    cout << "The dl double linked list contains..." << endl;
    dl.display();
    cout << endl;


    DoubleLinkList<char>* dl2 = new DoubleLinkList<char>;
    dl2->addToHead('a');
    dl2->addToHead('e');
    dl2->addToHead('i');
    dl2->addToTail('o');
    dl2->addToTail('u');

    cout << "The dl2 double linked list contains..." << endl;
    dl2->display();
    cout << endl; 

    //Testing the reverse display function 
    cout << "Reversing the dl2 double linked list..." << endl;
    dl2->reverseDisplay();
    cout << endl;

    //Deleting a node from the linked list
    cout << "Enter a character to delete from dl2 double link list: ";
    cin >> ch;
    dl2->deleteNode(ch);

    cout <<endl;
    cout << "The dl2 double linked list after deleting a node with a value of " << ch << " is..." << endl;
    dl2->display();
    cout << endl;

    //Reversing the double link list with integer elements
    DoubleLinkList<int>* reverseList = new DoubleLinkList<int>;

    reverseList = dl.reverese();
    cout << "Reversing dl double linked list..." << endl;
    reverseList->display();
    cout << endl;

    //Testing the overloaded subscript operator
    DoubleLinkList<char> dl3;

    dl3.addToHead('b');
    dl3.addToHead('c');
    dl3.addToHead('d');
    dl3.addToHead('f');

    cout << "The dl3 double linked list contains..." << endl;
    dl3.display();
    cout << endl;
    cout << "Enter the index number you want to access from dl2 double link list: ";
    cin >> index;
    cout << "The node at index "<< index << " = " << (*dl2)[index] << endl;



    
    return 0;
}
