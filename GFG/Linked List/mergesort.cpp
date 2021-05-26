// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.

struct Node *merge(struct Node *l,struct Node *r){
    if(l==NULL){
        return r;
    }
    if(r==NULL){
        return l;
    }
    if(l->data < r->data){
        l->next = merge(l->next,r);
        l->next->prev = l;
        l->prev=NULL;
        return l;
    }
    else{
        r->next = merge(l,r->next);
        r->next->prev=r;
        r->prev=NULL;
        return r;
    }
}

struct Node *middle(struct Node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node *s=head,*f=head->next;
    while(f!=NULL){
        f=f->next;
        if(f!=NULL){
            s=s->next;
            f=f->next;
        }
    }
    Node *temp=s->next;
    s->next=NULL;
    return temp;
}

struct Node *sortDoubly(struct Node *head)
{
	if(head==NULL || head->next==NULL){
	    return head;
	}
	struct Node *mid=middle(head);
	head = sortDoubly(head);
	mid = sortDoubly(mid);
	return merge(head,mid);
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends
