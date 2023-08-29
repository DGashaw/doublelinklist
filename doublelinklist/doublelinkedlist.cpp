#include<iostream>

using namespace std;

template<typename T>
struct Link
{
    T data;
    Link* next;
    Link* prev;
};

template<typename T>
class DoubleLinkList
{
    private:
        Link<T>* head;
        Link<T>* tail;
        int count; // for counting the number of elements in the linked list

    public: 
        //Constructor
        DoubleLinkList();
        //Function to add the head of the list
        void addToHead(T value);
        //Function that add to the tail of the list
        void addToTail(T value);
        //Function that returns the last node of the link list
        Link<T>* findLastNode();
        //Function that returns a specific node with a given value if exist in the list
        Link<T>* searchNode(T value);
        //Function that deletes a specific node with a given value if exist in the list
        void deleteNode(T value);
        //Function that displays the list in forward direction (starting from the head)
        void display() const;
        //Function that displays the list in reverse direction (starting from the tail)
        void reverseDisplay() const;
        //Function that returns a reversed double link list
        DoubleLinkList<T>* reverese();
        //Overloaded subscript operator to access the double link list with index
        T& operator [] (int j)
        {
            Link<T>* node = new Link<T>;

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
        ~DoubleLinkList()
        {
            Link<T>* temp = new Link<T>;

            temp = head;
            while(temp->next != nullptr)
            {
                cout << "Deleting ... " << temp->data << endl;
                temp = temp->next;
                delete temp->prev;

            }
            cout << "Deleting ... " << temp->data << endl;

            delete temp;
        }

};

template<typename T>
DoubleLinkList<T>::DoubleLinkList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template<typename T>
void DoubleLinkList<T>::addToHead(T value)
{
    Link<T>* newLink = new Link<T>;
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

template<typename T>
void DoubleLinkList<T>::addToTail(T value)
{
    Link<T>* newLink = new Link<T>;
    Link<T>* temp = new Link<T>;
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

template<typename T>
Link<T>* DoubleLinkList<T>::findLastNode()
{
    Link<T>* temp = new Link<T>;
    temp = head;

    while(temp != NULL)
    {
        if(temp->next == NULL)
            break;
        temp = temp->next;
    }

    return temp;
}

template<typename T>
Link<T>* DoubleLinkList<T>::searchNode(T value)
{
    Link<T>* node = new Link<T>;
    node = head;

    while(node != NULL)
    {
        if(node->data == value)
            break;
        node = node->next;
    }

    return node;
}

template<typename T>
void DoubleLinkList<T>::deleteNode(T value)
{
    Link<T>* temp = new Link<T>;
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
template<typename T>
DoubleLinkList<T>* DoubleLinkList<T>::reverese()
{
    DoubleLinkList<T>* list = new DoubleLinkList<T>();
    Link<T>* temp = new Link<T>;

    temp = head;
    while(temp != NULL)
    {
        list->addToHead(temp->data);
        temp = temp->next;
    }

    return list;
}

template<typename T>
void DoubleLinkList<T>::display() const
{
    Link<T>* temp = new Link<T>;
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
template<typename T>
void DoubleLinkList<T>::reverseDisplay() const
{
    Link<T>* temp = new Link<T>;
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

    //Some more features can be added here 



    
    return 0;
}
