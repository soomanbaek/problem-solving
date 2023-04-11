#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Node{
public:
    int num;
    Node* prev;
    Node* next;

    Node(int num, Node* prev, Node* next){
        this->num = num;
        this->prev = prev;
        this->next = next;
    }
};

stack<Node*> deleted_nodes;

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertNodeToHead(int num){
        Node* temp = new Node(num, nullptr, head);
        if(head == nullptr){
            head = temp;
            tail = temp;
        }
        else {
            head->prev = temp;
            head = temp;
        }
    }

    void insertNodeToTail(int num){
        Node* temp = new Node(num, tail, nullptr);
        if(tail == nullptr){
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertNode(Node* cursor, int num){
        if(head == nullptr){
            Node* temp = new Node(num, nullptr, nullptr);

            head = temp;
            tail = temp;

            return;
        }
        Node* temp = new Node(num, cursor, cursor->next);

        Node* nextCursor = cursor->next;
        if(nextCursor != nullptr){
            nextCursor->prev = cursor;
        }
        cursor->next = temp;
    }

    Node* deleteNode(Node* cursor){
        deleted_nodes.push(cursor);

        Node* prevCursor = cursor->prev;
        Node* nextCursor = cursor->next;
        if(cursor == head){
            head = nextCursor;
        }
        if(cursor == tail){
            tail = prevCursor;
        }
        if(prevCursor != nullptr){
            prevCursor->next = nextCursor;
        }
        if(nextCursor != nullptr){
            nextCursor->prev = prevCursor;
        }
        if(nextCursor == nullptr)
            return prevCursor;
        return nextCursor;
    }

    void restoreNode(){
        Node* node = deleted_nodes.top();
        deleted_nodes.pop();
        if(node->prev != nullptr){
            Node* prevNode = node->prev;
            prevNode->next = node;
        }
        if(node->next != nullptr){
            Node* nextNode = node->next;
            nextNode->prev = node;
        }
    }

    Node* up(Node* cursor, int n){
        for(int i=0; i<n; ++i){
            if(cursor->prev == nullptr) break;
            cursor = cursor->prev;
        }
        return cursor;
    }

    Node* down(Node* cursor, int n){
        for(int i=0; i<n; ++i){
            if(cursor->next == nullptr) break;
            cursor = cursor->next;
        }
        return cursor;
    }

    void display(){
        Node* cursor = this->head;
        while(cursor){
            cout<<cursor->num<<' ';
            cursor = cursor -> next;
        }
        cout<<'\n';
    }
};

string solution(int n, int k, vector<string> cmds) {
    string answer = "";

    LinkedList L;
    for(int i=0; i<n; ++i){
        L.insertNodeToTail(i);
    }
    Node* cursor = L.down(L.head, k);

    for(auto& cmd: cmds){
        if(cmd[0] == 'U'){
            int cnt = stoi(cmd.substr(2));
            cursor = L.up(cursor, cnt);
        }else if(cmd[0] == 'D'){
            int cnt = stoi(cmd.substr(2));
            cursor = L.down(cursor, cnt);
        }else if(cmd[0] == 'C'){
            cursor = L.deleteNode(cursor);
        }else if(cmd[0] == 'Z'){
            L.restoreNode();
            if(cursor == nullptr){
                cursor = L.head;
            }
        }
    }
    for(int i=0; i<n; ++i){
        answer.push_back('O');
    }
    while(!deleted_nodes.empty()){
        Node* node = deleted_nodes.top();
        deleted_nodes.pop();
        answer[node->num] = 'X';
    }
    return answer;
}