/*

An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, 
it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it
has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

*/

#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* nextXORprev;

    Node(int val){
        this->val = val;
        nextXORprev = nullptr;
    }

    static Node* XOR(Node* a, Node* b){
        return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
    }

    int getVal(){
        return val;
    }
};

class XORList{

    private:
        
        Node* head;
        Node* tail;
    
    public:

        XORList(){
            head = nullptr;
            tail = nullptr;
        }

        bool empty(){
            return head == nullptr;
        }

        void insert(int val){
            
            Node* curr = new Node(val);

            if(empty()){
                tail = curr;
                head = curr;
            } else {
                tail->nextXORprev = Node::XOR(tail->nextXORprev, curr);
                curr->nextXORprev = Node::XOR(tail, nullptr);
                tail = curr;
            }

        }

        Node* get(int index){
            Node* prev = head;
            Node* curr = Node::XOR(prev->nextXORprev, nullptr);
            for(int i = 0; curr != nullptr && i < index; i++){
                Node* next = Node::XOR(curr->nextXORprev, prev);
                prev = curr;
                curr = next;    
            }
            return prev;
        }

};

int main(){


    XORList l;
    for(int i = 0; i < 10; i ++){
        l.insert(i);
    }
    for(int i = 0; i < 10; i ++){
        cout<<l.get(i)->getVal()<<" ";
    }
    return 0;
}
