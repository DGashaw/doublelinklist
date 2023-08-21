/*
    This simple class uses a basic C++ array to contruct expandable stack data structure. 
    Author: Daniel Gashaw
*/

#include<iostream>
using namespace std;
int CAPACITY = 10;

template<typename T>
class Stack
{
    private:
        T *stack;
        int size;
    public:
        //constructor
        Stack()
        {
            size = 0;
            stack = new T[CAPACITY];
        }

        //checks whetther the stack is empty or not
        bool isEmpty()
        {
            return (size == 0) ? true : false;
        }
        //Pop will remove the top element from the stack; meaning the element removed won't exist in the stack anymore
        int pop()
        {
            return stack[--size];
        }

        /* Add new element to the stack and checks that there is enough room to add the new element. If not it will increase the current capacity by 
           doubling it. 
        */ 
        void push(T number)
        {
            if(size < CAPACITY)
            {
                stack[size++] = number;
            }

            // Expand the current stack size first and then add push the element
            else
            {
                T *temp = new T[CAPACITY*2];
                for(int i=0; i<size; i++)
                {
                    temp[i] = stack[i];
                }
                //stack now points the new expanded stack
                stack = temp;
                //Push the element in the stack
                stack[size++] = number;

                //Update the capacity of the stack
                CAPACITY *= 2;
            }
            
        }

        //Display the contents of the stack using LIFO(last in first out) fashion
        void display() const
        {
            for(int i=size-1; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }

            cout << endl;
        }

        //Distructor that will return the memory requested using new operator back to the OS
        ~ Stack()
        {
            cout << endl;
            cout << "Deleting stack pointer" << endl;

            delete stack;
        }

        //Return the current size of the stack which might change over the execution of the program
        int stack_size()
        {
            return size;
        }
        //Returns the reserved space for stack, it might be greater or equal to the size of the stack size
        int stack_capacity()
        {
            return CAPACITY;
        }
};

int main()
{
    Stack<int> s;

    for(int i=0; i < 10; i++)
    {
        s.push(i*i);
    }
    cout << "Poping the stack result " << s.pop() << endl;
    cout << "Didsplaying the contents of Stack s..." << endl;
    s.display();
    cout << "\n";

    //Testting if actually the stack array is expanding
    cout << "The current capacity of Stack s is " << s.stack_capacity() << endl;
    for(int i = 10; i < 15; i++)
    {
        s.push(i*i);
    }
    cout << "After adding more elements to Stack s, its capacity is " << s.stack_capacity() << endl;
    cout <<"\n";
    cout << "The current contents of the Stack s are..." << endl;
    s.display();

    Stack<char> ch;
    for (int i = 65; i < (65 + 26) ; i++)
    {
        ch.push(static_cast<char>(i));
    }

    cout << "Upper case letters of the English alphabets..." << endl;
    ch.display();

    Stack<char> ch2;
    for (int i = 97; i < (97 + 26) ; i++)
    {
        ch2.push(static_cast<char>(i));
    }

    cout << "Displaying the lowercase letters of the english alphabets...." <<endl;
    ch2.display();

    return 0;


}