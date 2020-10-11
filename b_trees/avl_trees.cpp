//This program calculates the
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
}node;

class avl_tree{
private:
    node* root_node;
    //int* arr;
public:
    avl_tree(): root_node(nullptr)
    {}
    void insert_node(int k);
    void delete_node(int k);
    node*  avl_insert(node* a, int k);//inserts an element and returns a pointer to the root
    static int get_maximum(int a,int b); // returns the max of 2 elements
    static int get_height_of_tree(node* a);//return the height of a node
    static node* create_new_node(int k);//creates a new node and returns a pointer to it
    static int get_height_difference(node* a);//finds the height difference between the left and right substrees
    static node* right_rotate(node* a);//utility function for rotating right to rebalance tree
    static node* left_rotate(node* a);//utility function for rotating left to rebalance tree
    static void print_bst_tree(node* a);//utility function for printing the bst tree
    void print();//utility function which prints the avl tree
    static node* avl_delete(node* a, int k);//function to delete a node
    static node* find_min_of_subtree(node* a);//value to find the smallest element in the tree.
    static void print_in_tree_fashion(node*a);//print in tree fashion
    void print_tree();

};
void avl_tree::insert_node(int k) {
    root_node=avl_insert(root_node,k);
}
void avl_tree::delete_node(int k) {
    root_node=avl_delete(root_node,k);
}
int avl_tree::get_maximum(int a, int b) {
    return (a>b)? a : b ;
}
int avl_tree::get_height_of_tree(node *a) {
    return (a== nullptr)? 0:a->height;
}

int avl_tree::get_height_difference(node *a) {
    return get_height_of_tree(a->left)-get_height_of_tree(a->right);
}

node* avl_tree::find_min_of_subtree(node *a) {
    node* temp=a;
    //leftmost element is smallest
    while(temp->left!= nullptr){
        temp=temp->left;
    }
    return temp;
}

node* avl_tree::create_new_node(int k) {
    //create a new node
    node* newnode = new node();
    //make height 1
    newnode->height=1;
    //make left null
    newnode->left= nullptr;
    //make right null
    newnode->right= nullptr;
    //make data as k
    newnode->data=k;
    //return pointer to newnode
    return newnode;
}

node * avl_tree::right_rotate(node *a) {
    //perform rotation
    node* root=a->left;
    a->left = root->right;
    root->right = a;

    //update height
    root->height = 1+max(get_height_of_tree(root->right),get_height_of_tree(root->right));
    a->height = 1+max(get_height_of_tree(a->right),get_height_of_tree(a->right));
    return root;
}

node * avl_tree::left_rotate(node *a) {
    //perform rotation
    node* root=a->right;
    a->right = root->left;
    root->left = a;

    //update height
    root->height = 1+max(get_height_of_tree(root->right),get_height_of_tree(root->right));
    a->height = 1+max(get_height_of_tree(a->right),get_height_of_tree(a->right));
    return root;
}


//We do avl_insertion through recursion
node* avl_tree::avl_insert(node* a, int k) {

    if( a== nullptr ) return create_new_node(k);//if the node is empty then make a new node and point a at it
    else if(k < a->data)    a->left = avl_insert(a->left,k); //if the element is greater than "a" then insert in left
    else if(k > a->data)    a->right = avl_insert(a->right,k); //if the element is greater than "a" then insert in right
    else return a; // duplicate elements not allowed in bst

    a->height=1+get_maximum(get_height_of_tree(a->left),get_height_of_tree(a->right));//update the height of the ancestor

    //if left subtree is bigger
    if(get_height_difference(a)>1){
        //left left case
        if(a->left->data > k) return right_rotate(a);
            //left right case
        else if (a->left->data < k){
            a->left = left_rotate(a->left);
            return right_rotate(a);
        }
    }
        //if right subtree is bigger
    else if(get_height_difference(a)<-1){
        //right left case
        if (a->right->data > k){
            a->right = right_rotate(a->right);
            return left_rotate(a);
        }
        else if(a->right->data < k)   return left_rotate(a);
    }
    //none of the above then return a
    return a;
}
//function implements avl delete
node* avl_tree::avl_delete(node *a,int k) {
    //do standard bst delete
    if(a== nullptr) return a;//if a is nullptr return a
    else if(a->data > k)    a->left = avl_delete(a->left,k);//if a->data is greater than k then avl_delete on a->left
    else if(a->data < k)    a->right = avl_delete(a->right,k);//if a->data is lesser than k then avl_delete on a->right
    else{
        node* temp=a;
        if(a->left== nullptr && a->right== nullptr){//no child
            a= nullptr;
            free(temp);
        }
        else if(a->left== nullptr || a->right== nullptr){//only one child
            if(a->left== nullptr){//left child null
                temp = a->right;
                *a = *(a->right);//transfer data
                free(temp);
            }
            else if(a->right== nullptr){//right child null
                temp = a->left;
                *a = *(a->left);//transfer data
                free(temp);
            }
        }
        else{//two child case
            temp=find_min_of_subtree(a->right); // get the smallest node of a
            a->data=temp->data; //copy data into node
            a->right = avl_delete(a->right,temp->data);//delete the temp node copied above
        }
    }
    if(a== nullptr)
        return a;

    a->height = 1+max(get_height_of_tree(a->left),get_height_of_tree(a->right));//update height

    if(get_height_difference(a) > 1){
        if(get_height_difference(a->left)>=0)   return right_rotate(a); //left left case
        else if(get_height_difference(a->left)<0){//left right case
            a->left = left_rotate(a->left);
            return right_rotate(a);
        }
    }
    else if(get_height_difference(a)<-1){
        if(get_height_difference(a->right)>0){//right left case
            a->right = right_rotate(a->right);
            return left_rotate(a);
        }
        else if(get_height_difference(a->right)<=0)  return right_rotate(a);//right right case
    }
    return a;
}

//print function
void avl_tree::print_bst_tree(node *a) {
    if(a== nullptr) return;
    print_bst_tree(a->left);
    cout<<" "<<a->data;
    print_bst_tree(a->right);

}
void avl_tree::print() {
    print_bst_tree(root_node);
    cout<<endl;
}

//prints the avl tree
void avl_tree::print_in_tree_fashion(node *a) {
    if(a== nullptr) return;
    //variable to print newline
    node* const newline= nullptr;
    int height=(a->height);
    queue<node*>  q;
    q.push(a);
    q.push(newline);
    for (int i = 0; i < height; ++i) {
        cout<<" ";
    }
    height--;
    //we loop till we completely traverse a tree
    while(true){
        node* pointer=q.front();
        q.pop();
        if(pointer!=newline){
            cout<<pointer->data<<" ";
            if(pointer->left != nullptr)    q.push(pointer->left);
            if(pointer->right != nullptr)   q.push(pointer->right);
        }
        else{
            cout<<"\n";
            for (int i = 0; i < height; ++i) {
                cout<<" ";
            }
            height--;
            if(q.empty())   break;
            q.push(newline);
        }
    }
}
void avl_tree::print_tree() {
    print_in_tree_fashion(root_node);
}

// The main function
int main()
{
    //creates an object of avl_tree
    avl_tree obj;
    //insert elements
    obj.insert_node(12);
    obj.insert_node(23);
    obj.insert_node(11);
    obj.insert_node(76);
    obj.insert_node(86);
    obj.insert_node(91);
    //prints the sorted order after insertion
    cout<<"Sorted array using avl tree after insertion only:"<<endl;
    obj.print();
    //prints tree
    obj.print_tree();
    obj.delete_node(11);
    cout<<"Sorted array using avl tree after deletion"<<endl;
    //prints the sorted order after deletion
    obj.print();
    //prints tree
    obj.print_tree();


    return 0;
}
