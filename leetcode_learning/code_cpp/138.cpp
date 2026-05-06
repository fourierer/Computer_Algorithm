#include<iostream>
#include<map>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        if(Cache_Node.count(head)==0)
        {
            Node* new_head = new Node(head->val);
            Cache_Node[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        return Cache_Node[head];
        
    }
private:
    map<Node*, Node*> Cache_Node;
};