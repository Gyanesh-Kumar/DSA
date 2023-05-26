//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node * head){
        Node* prev = NULL;
        Node* curr = head ;
        Node* nex = head->next ;
        while(curr != NULL){
            curr->next = prev ;
            prev = curr ;
            curr= nex ;
            if(nex != NULL)nex = nex->next ;
        }
        return prev; 
    }
    //Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first) ;
        second = reverse(second) ;
        Node* dummy = new Node(-1);
        Node* temp = dummy ;
        int carry = 0;
        while(first != NULL || second != NULL || carry == 1){
            int sum = 0 ;
            if(first){
                sum+=first->data ;
                first = first->next ;
            }
            if(second){
                sum+=second->data ;
                second = second->next ;
            }
            sum+=carry ;
            carry = sum/10 ;
             Node* newNode = new Node(sum % 10) ;
            temp->next = newNode;
            temp = temp->next ;
        }
        return reverse(dummy->next) ;
    }
};












//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends