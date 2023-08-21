/*
    This simple class uses a basic C++ array to contruct expandable stack data structure. 
    Author: Daniel Gashaw
*/

#include<iostream>
using namespace std;
int CAPACITY = 10;

class Stack
{
    private:
        int *stack;
        int size;
    public:
        Stack()
        {
            size = 0;
            stack = new int[CAPACITY];
        }
        bool isEmpty()
        {
            return (size == 0) ? true : false;
        }

        void push(int number)
        {
            if(size < CAPACITY)
            {
                stack[size++] = number;
            }

            // Expand the current stack size first and then add push the element
            else
            {
                int *temp = new int[CAPACITY*2];
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

        void display() const
        {
            cout << endl;
            for(int i=size-1; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }

            cout << endl;
        }

        ~ Stack()
        {
            cout << endl;
            cout << "Deleting stack pointer" << endl;

            delete stack;
        }
};

int main()
{
    Stack s;

    for(int i=0; i < 10; i++)
    {
        s.push(i*i);
    }

    s.display();

    //Testting if actually the stack array is expanding
    for(int i = 10; i < 15; i++)
    {
        s.push(i*i);
    }

    s.display();



}