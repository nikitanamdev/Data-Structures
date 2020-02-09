#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
    }
};
Node *head = NULL;
Node *tail = NULL;

void addFirst(int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
int size()
{
    if (head == NULL)
        return 0;
    else
    {
        Node *temp = head;
        int len = 1;
        while (temp != tail)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
}
bool isempty()
{
    return head == NULL;
}

void addLast(int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
int removeFirst()
{
    Node *temp = NULL;
    if (head != NULL)
    {
        if (head == tail)
        {
            tail = NULL;
        }
        temp = head;
        head = head->next;
    }
    int data = temp != NULL ? temp->data : -1;
    delete temp;
    return data;
}
int getIndex(int data)
{
    int idx = 0;
    Node *temp = head;
    while (temp->data != data)
    {
        ++idx;
        temp = temp->next;
    }
    return idx;
}
Node *getNodeAt(int idx)
{
    if (idx == 0)
        return head;

    Node *temp = head;
    while (idx != 0)
    {
        temp = temp->next;
        idx--;
    }
    return temp;
}
int removeLast()
{
    Node *rn = NULL;
    if (head == tail)
    {
        rn = tail;
        tail = NULL;
        head = NULL;
    }
    else
    {
        Node *temp = getNodeAt(size() - 2);
        rn = tail;
        temp->next = NULL;
        tail = temp;
    }
    int data = rn != NULL ? rn->data : -1;
    delete rn;
    return data;
}
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void addNode(int idx, int data)
{
    Node *temp = new Node(data);
    if (idx == 0)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp1 = getNodeAt(idx - 1);
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
int removeNode(int idx)
{
    Node *rn = NULL;
    if (head == tail)
    {
        rn = head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *temp = getNodeAt(idx);
        Node *temp1 = getNodeAt(idx - 1);
        rn = temp;
        temp1->next = temp->next;
    }
    int data = rn != NULL ? rn->data : -1;
    delete rn;
    return data;
}
int getMiddleNode()
{
    Node *temp1 = head;
    Node *temp2 = head;
    while (temp2 != NULL && temp2->next != NULL)
    {
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }
    return temp1->data;
}
//----------------Reverse Data using Stack (Printing)-----------------
void reverseData()
{
    stack<int> st;
    Node *temp = head;
    // cout<<temp->data<<" ";
    //st.push(temp->data);
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    while (st.size() != 0)
    {
        int c = st.top();
        st.pop();
        cout << c << "<-";
    }
}
//----------------Reverse Data using class Pair----------
class PairRev
{
public:
    Node *prevNode = nullptr;
};

void reverseData(Node *node, PairRev *prev, int level)
{
    if (node == nullptr)
        return;

    int size_ = size();
    reverseData(node->next, prev, level + 1);
    if (level > size_ / 2)
    {
        int temp = prev->prevNode->data;
        prev->prevNode->data = node->data;
        node->data = temp;

        prev->prevNode = prev->prevNode->next;
    }
}

void reverseDataRec()
{
    PairRev *prev = new PairRev();
    prev->prevNode = head;

    reverseData(head, prev, 0);
    display();
}

Node *reversePointer(Node *node) // by reversing the pointers
{
    Node *currnode = node;
    Node *prev = nullptr;
    Node *nextnode = nullptr;
    while (currnode != nullptr)
    {
        nextnode = currnode->next;
        currnode->next = prev;
        prev = currnode;
        currnode = nextnode;
    }
    return prev;
}
void reverseData_01() // using middle node method
{
    Node *temp1 = head;
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp2 = slow->next;
    // fast = slow->next;
    slow->next = nullptr;
    temp2 = reversePointer(temp2);
    fast = temp2;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        int temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2 = reversePointer(fast);
    slow->next = temp2;
    // slow -> next =  ;
}
// Reverse Linked List using adding and removing nodes from first-----------
Node *new_head = nullptr;
void addFirst(Node *node)
{
    // Node *temp = new Node(data);
    if (new_head == NULL)
    {
        new_head = node;
        tail = node;
    }
    else
    {
        node->next = new_head;
        new_head = node;
    }
}
Node *removeFirst_()
{
    Node *temp = NULL;
    if (head != NULL)
    {
        if (head == tail)
        {
            tail = NULL;
        }
        temp = head;
        head = head->next;
    }
    int data = temp != NULL ? temp->data : -1;
    temp->next = nullptr;
    return temp;
}
void reverseData_02()
{
    while (head != nullptr)
    {
        Node *temp = removeFirst_();
        addFirst(temp);
    }
}
void display(Node *node)
{
    Node *temp = node;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}
void revData()
{
    addLast(10);
    addLast(20);
    addLast(30);
    addLast(40);
    addLast(50);
    addLast(60);
    addLast(70);

    reverseData_02();
    display(new_head);
}
//--------------Checking Palindrome in Linked List---------
Node *getMiddleNode_(Node *node)
{
    Node *temp1 = node;
    Node *temp2 = node;
    while (temp2 != NULL && temp2->next != NULL)
    {
        temp2 = temp2->next->next;
        temp1 = temp1->next;
    }
    return temp1;
}
bool isPalindrome(Node *node)
{
    Node *mid = getMiddleNode_(node);
    Node *new_head = mid->next;
    mid->next = nullptr;

    Node *prev = reversePointer(new_head);

    Node *list1 = prev;
    Node *list2 = node;
    bool flag = true;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data != list2->data)
            flag = false;

        list1 = list1->next;
        list2 = list2->next;
    }
    new_head = reversePointer(prev);
    mid->next = new_head;

    return flag;
}
void checkPalindrome()
{
    addLast(1);
    addLast(2);
    addLast(3);
    addLast(4);
    addLast(3);
    addLast(2);
    addLast(1);

    cout << boolalpha << isPalindrome(head) << endl;
}
//------------FOLD THE LIST-----------------
// void addNode(Node* node,Node* prev,Node* nextptr){
//     // Node *temp = new Node(node->data);
//     if (prev == nullptr && nextptr==nullptr)
//     {
//         prev = node;
//         nextptr = node;
//     }
//     else{
//         node->next=nextptr;
//         prev->next=node;
//     }
// }
void foldList()
{
    Node *mid = getMiddleNode_(head);
    Node *new_head = mid->next;
    mid->next = nullptr;

    Node *prev = reversePointer(new_head);
    Node *list1 = head;
    Node *list2 = prev;

    while (list2 != nullptr)
    {
        Node *nextptr = list1->next;
        Node *temp = list2->next;
        list1->next = list2;
        list2->next = nextptr;
        list1 = nextptr;
        list2 = temp;
    }
    if (list1 == nullptr)
    {
        tail = new_head;
    }
    else
    {
        tail = list1;
    }
}
void solve()
{
    addFirst(20);
    addFirst(10);
    addLast(30);
    addLast(40);
    addLast(50);
    addLast(60);
    addLast(70);
    // addNode(4, 70);

    // cout<<removeFirst()<<endl;
    // display();
    // cout << endl;
    // cout<<isempty()<<endl;
    // cout<<size()<<endl;
    // cout<<getIndex(30)<<endl;
    // cout<<getNodeAt(2)->data<<endl;
    // cout<<removeLast()<<endl;
    // cout<<removeNode(4)<<endl;
    // display();
    // cout<<getMiddleNode();
    // reverseData();
    // reverseDataRec();
    // head = reversePointer(head);
    // reverseData_01();
    // checkPalindrome();
    // display();
    // revData();
    foldList();
    addLast(100);
    display();
    cout << endl;
}
int main()
{
    solve();
    return 0;
}