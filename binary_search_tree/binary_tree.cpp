#include<iostream>
#include<string>
#include <limits> // for ininity

using namespace std;

struct Link
{
    int data;
    Link* left;
    Link* right;
};

void display(Link* t);


class BinaryTree
{
    private:
        Link* root;
    public:
        BinaryTree() : root(NULL)
        {}
        
        //Functiuon that add a node as a subtree to the tree structure
        void add_node(int value)
        {
            //Create a new note to be added to the binary tree
            Link* temp = new Link;
            temp->data = value;
            temp->left = NULL;
            temp->right = nullptr;

            //Check if the binary tree is empty, if it is then the added node will be the node of the tree
            if(root == NULL)
            {
                root = temp;
            }

            //Since the tree is not empty, we have to do more tests before we add the node to the tree
            else
            {
                //Check if the right subtree of the root is empty and the node that to be added have a value greater than the root node value
                if(value > root->data && root->right == nullptr)
                {
                    root->right = temp;
                }

                //Check if the left subtree of the root is empty and the node that to be added have a value less than the root node value
                else if(value < root->data && root->left == nullptr)
                {
                    root->left = temp;
                }

                //At this point we know that tree is not empty and both the right and left nodes of the root node are not empty
                //Here we check if the node to be added have a value that is greater than the node value. If it does, it belongs to the right subtree
                else if(value > root->data)
                {
                    //cout << "I am on the right node" << endl;
                    Link* node = new Link;
                    
                    //Here the search_node_right function search an empty node that is suitable for the new node to be added on the right subtree
                    node = search_node_right(value);
                    
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

                //At this point we know that tree is not empty and both the right and left nodes of the root node are not empty
                //Here we check if the node to be added have a value that is less than the node value. If it does, it belongs to the left subtree
                else
                {
                    
                    Link* node = new Link;
                    
                    //Here the search_node_right function search an empty node that is suitable for the new node to be added on the left subtree
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

        //Helper function to the add_node function. It will look an suitable internal root node on the right subtree to the upcoming new node that have value of "value"
        Link* search_node_right(int value)
        {
            Link* temp = new Link;
            temp = root->right;

            //Using iterative exhaustive method to look for the suitable internal node
            while(temp->right != nullptr || temp->left != nullptr)
            {
                //The best thing about BST have a complexity of log since everytime we are searching, half of the tree elemnts are eliminated
                //Here we are looing for the right subtree only if the value of the new node to be added is greater than that of the root node value
                if(value > temp->data)
                {
                    if(temp->right == nullptr)
                        break;
                    temp = temp->right;
                    
                }

                //Here we are looing for the left subtree only if the value of the new node to be added is less than that of the root node value
                else
                {
                    if(temp->left == nullptr)
                        break;
                    temp = temp->left;
                    
                }
            }

            return temp;
        }
        
        //Helper function to the add_node function. It will look an suitable internal root node on the left subtree to the upcoming new node that have value of "value"
        //The rest of the functionalities are the same as the search_node_right function above
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

        //Helper function for the search_node function which traverses the left subtree of the tree strcuture to look for the internal node containing the search value
        Link* search_left_node(int value)
        {
            Link* temp = new Link;
            temp = root->left;

            while(temp->left != nullptr || temp->right != nullptr) 
            {
                //Search the right subtree of the tree structure since the value we are looking for is greater than the root node value
                if(value > temp->data)
                {
                    if(temp->right == nullptr)
                        break;
                    if(temp->right->data == value)
                        return temp;
                    temp = temp->right;
                   
                }
                
                //Search the left subtree of the tree structure since the value that we are looking for is less than the root node value
                else
                {
                    if(temp->left == nullptr)
                        break;
                    if(temp->left->data == value)
                        return temp;
                    temp = temp->left;
                    
                    
                }
            }

            return temp;
        }

        //Helper function for the search_node function which traverses the right subtree of the tree strcuture to look for the internal node containing the search value
        Link* search_right_node(int value)
        {
            Link* temp = new Link;
            temp = root->right;

            while(temp->right != nullptr || temp->left != nullptr)
            {
                //Search the right subtree of the tree structure since the value we are looking for is greater than the root node value
                if(value > temp->data)
                {
                    //cout << "temp is on the right and its value is " << temp->data << endl;
                    if(temp->right == nullptr)
                        break;
                    if(temp->right->data == value)
                        return temp;
                    temp = temp->right;
                    
                }
                //Search the left subtree of the tree structure since the value that we are looking for is less than the root node value
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

        //Function that search a node containing the search value. If succeeded, it will return the root node that contains the search node with a value; 
        //Otherwise, it will return the root node that should contain the node with a value that we are looking for.
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

        void delete_node(int value)
        {
            Link* temp = new Link;
            
            temp = root;
            
            //The node to be deleted is the root node
            if(temp->data == value)
            {
                //Check if the node to the right of the root node don't have a left subtree
                if(temp->right->left == nullptr)
                {
                    temp->right->left = temp->left;
                    root = temp->right;
                } 

                //If the node to the right of the root have a left subtree
                else
                {
                    Link* node = new Link;

                    //Here we are looking for the suitable node for the node to be on the left of the root node to be added as the root is abou to deleted
                    node = search_node_right(root->left->data);

                    node->left = temp->left;
                    root = root->right;
                }   
                
            }
            //The node to be deleted is the left of the root node
            else if(temp->left->data == value)
            {
                //check if the node to be deleted don't have a right subtree
                if(temp->left->right == nullptr)
                {
                    root->left = temp->left->left;
                }

                //check if the node to be deleted have a right subtree
                else
                {
                    Link* node = new Link;
                    Link* searchNode = new Link;
                    node = temp->left->left; // node now pointing the node to the left of the node to be deleted

                    root->left = temp->left->right; // the left node of the root node is pointing the right node of the node to be deleted

                    //Now we have to look for the specific node to be added for "node - pointing the node to the left of the node to be deleted"
                    searchNode = search_node_left(node->data);

                    if(node->data > searchNode->data)
                        searchNode->right = node;
                    else
                        searchNode->left = node; 

                }
            }

            //The node to be deleted is the right of the root node
            else if(temp->right->data == value)
            {
                //The node to be deleted do not have a left subtree
                if(temp->right->left == nullptr)
                {
                    root->right = temp->right->right;
                }

                //The node to be deleted have a left subtree
                else
                {
                    Link* node = new Link;
                    Link* searchNode = new Link;

                    node = temp->right->left; //node now pointing the left node of the node to be deleted
                    root->right = temp->right->right;  // The right node of the root node is pointing the right node that is one node below the node to be deleted

                    searchNode = search_node_right(node->data);

                    if(node->data > searchNode->data)
                    {
                        searchNode->right = node;
                    }
                    else
                    {
                        searchNode->left = node;
                    }
                }


            }

            //To delete any node other than the root node, the left and right node to the root node
            else
            {
                Link* node = new Link;
                Link* searchNode = new Link;
                Link* searchNode_2 = new Link;
                bool searchValue = false;

                //Search the node with the value to be deleted exist in the BST
                searchNode = search_node(value);
                //cout << "I am here to delete some right node with childs.." << endl;
                //cout << "searchNode->data = " << searchNode->data << endl;
                    
                //Check if the internal root node(searchNode) contains the node with value to be deleted 
                if(searchNode != nullptr) //(searchNode->left->data == value || searchNode->right->data == value)  // && searchValue
                {
                    //cout << "I am here..." << endl;
                    //check if the node to be deleted is the left node

                    if(searchNode->left != nullptr && searchNode->left->data == value)
                        node = searchNode->left;
                    else
                    {
                        //cout << "here..." << endl;
                        if(searchNode->right != nullptr && searchNode->right->data == value)
                        {
                            node = searchNode->right;
                        }
                            
                    }
                    //cout << "searchNode->right == node implies" << (searchNode->right == node) << endl;
                    //cout << "node->data = " << node->data << endl;
                    
                    //The node to be deleted have no children
                    if(node->left == nullptr && node->right == nullptr)
                        searchNode->left = nullptr;

                    //The node to be deleted have either a right subtree or left subtree
                    else if((node->left == nullptr && node->right != nullptr) || (node->left != nullptr && node->right == nullptr))
                    {
                        if(node->left != nullptr)
                            searchNode->left = node->left;
                        if(node->right != nullptr)
                            searchNode->left = node->right;
                    }
                        

                    //The node to be deleted have a left and right subtree
                    else 
                    {
                        if(searchNode->left != NULL &&  searchNode->left->data == value)
                        {
                            //cout << "I am here to delete some left node with childs.." << endl;
                            //search the appropriate node to be added on the right of the deleted node
                            Link* tempLeft = new Link;
                            tempLeft = node->left; //temporarily hold the left of the node to be deleted

                            //add the right of the node to be deleted to the root node left
                            searchNode->left = node->right;
                            

                            //now look for the right node to be added for the tempLeft->data
                            searchNode_2 = search_node(tempLeft->data);
                            
                            //Add the tempLeft either to the right or the left
                            if(tempLeft->data > searchNode_2->data)
                                searchNode_2->right = tempLeft;
                            else
                                searchNode_2->left = tempLeft;
                            
                        }

                        else if(searchNode->right != NULL &&  searchNode->right->data == value)
                        {
                            //cout << "I am here to delete some right node with child nodes .. " << endl;
                            //search the appropriate node to be added on the right of the deleted node
                            Link* tempLeft = new Link;
                            tempLeft = node->left; //temporarily hold the left of the node to be deleted

                            //add the right of the node to be deleted to the root node right
                            searchNode->right = node->right;
                
                            //now look for the right node to be added for the tempLeft->data
                            searchNode_2 = search_node(tempLeft->data);
                            
                            //Add the tempLeft either to the right or the left
                            /*if(searchNode_2 == nullptr)
                                searchNode_2->right = tempLeft;*/
                            if(tempLeft->data > searchNode_2->data)
                                searchNode_2->right = tempLeft;
                            else
                                searchNode_2->left = tempLeft;
                        }
                            
                            
                            
                        

                        

                    }
                    
                }
            }

        }
        
        //Returns the root node of the tree
        Link* get_root()
        {
            return this->root;
        }

        //Returns the left node of the root node
        Link* get_left_node()
        {
            return this->root->left;
        }

        //returns the right node of the root node
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
        cout << "L-";
        display(t->left);
        cout << " R-";   
        display(t->right);
        cout << ") ";     
    }

    

}

int main()
{
    BinaryTree t1;

    //Adding nodes to the BST
    t1.add_node(16);
    t1.add_node(17);
    t1.add_node(4);
    t1.add_node(21);
    t1.add_node(6);
    t1.add_node(20);
    t1.add_node(11);
    t1.add_node(10);
    t1.add_node(3);
    t1.add_node(5);
    t1.add_node(18);
    t1.add_node(22);
    t1.add_node(1);
    t1.add_node(2);
    t1.add_node(0);
    t1.add_node(12);
    

   


    //Dsiplaying the contents of the BST
    display(t1.get_root());
    cout << endl;
    cout << endl;

    string searchMessage ;
    Link* searchResult = new Link;
   
    int val = 1;
    //Searching the BST to look for the root node containig the node that have a value equal to val
    searchResult  = t1.search_node(val);
    
    //Since we are returning the node that containing the search value, we should test whether the right or left subtree the returned node have the value
    ((searchResult->left != nullptr && searchResult->left->data == val) || (searchResult->right != nullptr && searchResult->right->data == val)) ? searchMessage = "Found" : searchMessage = "Not Found";

    if(searchMessage == "Found")
        cout << "Looing for " << val << " in the BST and " << searchMessage << ". The node containing " << val << " has a value of " << searchResult->data << endl;
    else
        cout << "Looing for " << val << " in the BST and " << searchMessage << ". The node should containing " << val << " has a value of " << searchResult->data << endl;

    cout << endl;
    
    t1.delete_node(val);
    cout << "After deleting a node with a value " << val <<", the tree structure is ...." << endl;
    display(t1.get_root());
    cout << endl;

    
    
    

    
    return 0;
}


