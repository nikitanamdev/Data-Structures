#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void display(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
Node *addfirst(Node *node, Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    return head;
}
void addLast(Node *node, Node *&head, Node *&tail)
{
    if (tail == nullptr)
    {
        tail = node;
        head = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
Node *removefirst(Node *&head, Node *&tail)
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
Node *mid_(Node *node)
{
    Node *slow = node;
    Node *fast = node;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
//---------Fold the linked list--------------
void foldList(Node *&head, Node *&tail)
{
    Node *mid = mid_(head);
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
    display(head, tail);
}
//---------------Unfold the linked list-----------
void unfold(Node *&head, Node *&tail)
{
    display(head, tail);
    Node *list1 = head;
    Node *list2 = head->next;
    Node *head1 = nullptr;
    Node *head2 = nullptr;
    Node *tail1 = nullptr;
    Node *tail2 = nullptr;
    int count = 1;
    while (list1 != nullptr || list2 != nullptr)
    {
        Node *nextptr = list2->next;
        Node *temp = removefirst(head, tail);
        //cout<<temp->data;
        //break;
        if (count % 2 != 0)
        {
            addLast(temp, head1, tail1);
            list1 = nextptr;
            count++;
        }
        else
        {
            addfirst(temp, head2, tail2);
            list2 = nextptr->next;
            count++;
        }
    }
    // cout<<"out";
    tail1->next = head2;
    head = head1;
    tail = tail2;

    display(head, tail);
}
class LRU
{
public:
    list<int> ll;
    unordered_map<int, int> map;
    int default_size = 0;

    LRU(int size)
    {
        this->default_size = size;
    }
    void set(int key, int val)
    {
        if (map.find(key) == map.end())
        {
            if (ll.size() == default_size)
            {
                int old_value = ll.back();
                ll.pop_back();
                
                map.erase(old_value);
            }
            ll.push_front(key);
            map[key] = val;
        }
        else
        {
            ll.remove(key);
            ll.push_front(key);
            map[key] = val;
        }
    }
    int get(int key)
    {
        if (map.find(key) == map.end())
            return -1;

        ll.remove(key);
        ll.push_front(key);
        return map[key];
    }
    void display()
    {
        for (auto i : ll)
        {
            cout << i << "->";
        }
        cout << endl;
    }
};
void solve_LRU(){
    LRU cache(4);
    cache.set(1,100);
    cache.set(2,200);
    cache.set(3,300);
    cache.set(4,400);
    cache.display();

    cache.get(3);
    cache.display();
    cache.set(6,600);
    cache.display();
}
void solve()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < 9; i++)
    {
        Node *temp = new Node(i + 1);
        addLast(temp, head, tail);
    }
    // display(head,tail);
    // foldList(head, tail);
    // unfold(head, tail);
    solve_LRU();
}

int main()
{
    solve();
    return 0;
}