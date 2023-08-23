#include<iostream>
#include<string>

using namespace std;

struct Link
{
    int data;
    Link* left;
    Link* right;
};

class BinaryTree
{
    private:
        Link* root;
    public:
        BinaryTree() : root(NULL)
        {}
        
        void add_node(int value)
        {
            //Create a new note to be added to the binary tree
            Link* temp = new Link;
            temp->data = value;
            temp->left = NULL;
            temp->right = nullptr;

            //Check if the binary tree is empty
            if(root == NULL)
            {
                root = temp;
            }
            else
            {
                if(value > root->data && root->right == nullptr)
                {
                    root->right = temp;
                }

                else if(value < root->data && root->left == nullptr)
                {
                    root->left = temp;
                }

                //adding a node to the right
                else if(value > root->data)
                {
                    //cout << "I am on the right node" << endl;
                    Link* node = new Link;
                    
                    node = search_node_right(value);
                    //cout << "Right node->data == "<< node->data << " "<< endl;

                    //Compare the current value to be added with search node so that it can be added to the left or the right of it
                    if(value > node->data)
                    {
                        node->right = temp;
                        node->left = nullptr;
                    }
                    else
                    {
                        node->left = temp;
                        node->right = nullptr;
                    }
                    
                }

                // Adding value to the left
                else
                {
                    //cout << "I am on the left node" << endl;
                    Link* node = new Link;
                    
                    node = search_node_left(value);
                    //cout << "Left node->data == "<< node->data << " "<< endl;

                    //Compare the current value to be added with search node so that it can be added to the left or the right of it
                    if(value > node->data)
                    {
                        node->right = temp;
                    }
                    
                    else 
                    {
                        node->left = temp;
                    }
                }


            }
            
        }

        Link* search_node_right(int value)
        {
            Link* temp = new Link;
            temp = root->right;

            while(temp->right != nullptr || temp->left != nullptr)
            {
                if(value > temp->data)
                {
                    //cout << "temp is on the right and its value is " << temp->data << endl;
                    if(temp->right == nullptr)
                        break;
                    temp = temp->right;
                    
                }
                else
                {
                    //cout << "temp is on the left and its value is " << temp->data << endl;
                    if(temp->left == nullptr)
                        break;
                    temp = temp->left;
                    
                }
            }

            //cout << temp->data;

            return temp;
        }
        
        Link* search_node_left(int value)
        {
            Link* temp = new Link;
            temp = root->left;

            while(temp->left != nullptr || temp->right != nullptr) 
            {
                if(value > temp->data)
                {
                    //cout << "temp is on the right and its value is " << temp->data << endl;
                    if(temp->right == nullptr)
                        break;
                    temp = temp->right;
                   
                }
                else
                {
                    //cout << "temp is on the left and its value is " << temp->data << endl;
                    if(temp->left == nullptr)
                        break;
                    temp = temp->left;
                    
                    
                }
            }

            return temp;
        }
        Link* search_left_node(int value)
        {
            Link* temp = new Link;
            temp = root->left;

            while(temp->left != nullptr || temp->right != nullptr) 
            {
                if(value > temp->data)
                {
                    //cout << "temp is on the right and its value is " << temp->data << endl;
                    if(temp->right == nullptr)
                        break;
                    if(temp->right->data == value)
                        return temp;
                    temp = temp->right;
                   
                }
                else
                {
                    //cout << "temp is on the left and its value is " << temp->data << endl;
                    if(temp->left == nullptr)
                        break;
                    if(temp->left->data == value)
                        return temp;
                    temp = temp->left;
                    
                    
                }
            }

            return temp;
        }

        Link* search_right_node(int value)
        {
            Link* temp = new Link;
            temp = root->right;

            while(temp->right != nullptr || temp->left != nullptr)
            {
                if(value > temp->data)
                {
                    //cout << "temp is on the right and its value is " << temp->data << endl;
                    if(temp->right == nullptr)
                        break;
                    if(temp->right->data == value)
                        return temp;
                    temp = temp->right;
                    
                }
                else
                {
                    //cout << "temp is on the left and its value is " << temp->data << endl;
                    if(temp->left == nullptr)
                        break;
                    if(temp->left->data == value)
                        return temp;
                    temp = temp->left;
                    
                }
            }

            return temp;
        }

        Link* search_node(int value)
        {
            //The link node will hold the value returned either by the search_left_node or search_right_node functions
            Link* temp = new Link;
            
            //Search the right subtree
            if(value > root->data)
            {
                temp = search_right_node(value);
            }
            //look for the left subtree
            else if(value < root->data)
            {
                temp = search_left_node(value);
            }
             //if the value we are looking for is equal to the root node value
            if(value == root->data)
                temp = root;
           
            
            return temp; // otherwise the value we are looking for found in the temp root
        }
        
        Link* get_root()
        {
            return this->root;
        }
        Link* get_left_node()
        {
            return this->root->left;
        }
        Link* get_right_node()
        {
            return this->root->right;
        }

        

};

//Using DFS(that is display the nodes first before display the root node approach) to display the BST
void display(Link* t)
{
    Link* temp = new Link;
    temp = t;

    
    if(temp == nullptr)
        cout << "empty ";
    else
    {
        cout << "( ";
        cout << temp->data << " ";
        cout << "L ";
        display(t->left);
        cout << " R ";   
        display(t->right);
        cout << ") ";     
    }

    

}

int main()
{
    BinaryTree t1;
    t1.add_node(16);
    t1.add_node(17);
    t1.add_node(10);
    t1.add_node(4);
    t1.add_node(21);
    t1.add_node(1);
    t1.add_node(5);
    t1.add_node(20);


    display(t1.get_root());
    cout << endl;

    string searchMessage ;
    Link* searchResult = new Link;
   
    int val =11;
    searchResult  = t1.search_node(val);
    
    //Since we are returning the node that containing the search value, we should test whether the right or left subtree the returned node have the value
    ((searchResult->left != nullptr && searchResult->left->data == val) || (searchResult->right != nullptr && searchResult->right->data == val)) ? searchMessage = "Found" : searchMessage = "Not Found";

    if(searchMessage == "Found")
        cout << "Looing for " << val << " in the BST and " << searchMessage << ". The node containing " << val << " has a value of " << searchResult->data << endl;
    else
        cout << "Looing for " << val << " in the BST and " << searchMessage << ". The node should containing " << val << " has a value of " << searchResult->data << endl;


    return 0;
}


