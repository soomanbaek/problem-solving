#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct compare{
    bool operator()(vector<int>& l, vector<int>& r){
        if(l[1] == r[1]) return l[0] < r[0];
        return l[1] > r[1];
    }
};

class Node{
public:
    vector<pair<int,int>> nodes;
    int height;
    Node* next;

    Node(int height){
        this->height = height;
        this->next = nullptr;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    Node* insertNodeToTail(int height){
        Node* temp_node = new Node(height);

        if(head == nullptr && tail == nullptr){
            head = temp_node;
            tail = temp_node;

        }else{
            tail-> next = temp_node;
            tail = temp_node;
        }
        return temp_node;
    }
};

class TreeNode{
public:
    int num;
    int x;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, int num){
        this->x = x;
        this->num = num;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* findChild(int left, int right, vector<pair<int,int>>& nodes){
    int L = 0;
    int R = nodes.size()-1;
    int M;
    while(L<=R){
        M = (L+R)/2;
        if(left <= nodes[M].first && nodes[M].first <= right){
            return new TreeNode(nodes[M].first, nodes[M].second);
        }else if(nodes[M].first < left){
            L = M + 1;
        }else if(nodes[M].first > right){
            R = M - 1;
        }
    }
    return nullptr;
}

void makeTree(TreeNode* tree_node, int left, int right, Node* child_node){
    if(child_node == nullptr) return;
    int mid = tree_node->x;
    
    tree_node->left = findChild(left, mid - 1, child_node->nodes);
    tree_node->right = findChild(mid + 1, right, child_node->nodes);

    if(tree_node->left != nullptr)   makeTree(tree_node->left, left, mid - 1, child_node->next);
    if(tree_node->right != nullptr)  makeTree(tree_node->right, mid + 1, right, child_node->next);
}

void preOrder(vector<int>& V, TreeNode* node){
    if(node == nullptr) return;
    V.push_back(node->num);
    preOrder(V, node->left);
    preOrder(V, node->right);
}

void postOrder(vector<int>& V, TreeNode* node){
    if(node == nullptr) return;
    postOrder(V, node->left);
    postOrder(V, node->right);
    V.push_back(node->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    map<pair<int,int>, int> M;

    LinkedList height_list;
    for(int i=0; i<nodeinfo.size(); ++i){
        vector<int> node = nodeinfo[i];
        M.insert({{node[0], node[1]}, i+1});
    }

    // 1. nodeinfo 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), compare());

    int height = nodeinfo[0][1];
    Node* cur = height_list.insertNodeToTail(height);
    int left = 100001;
    int right = 0;

    for(int i=0; i<nodeinfo.size(); ++i){
        int node_x = nodeinfo[i][0];
        int node_y = nodeinfo[i][1];
        int num = M[{node_x, node_y}];

        left = min(left, node_x);
        right = max(right, node_x);
        
        if(height != node_y){
            height = node_y;
            cur = height_list.insertNodeToTail(height);
        }
        cur -> nodes.push_back({node_x, num});
    }

    Node* root_node = height_list.head;

    TreeNode* tree_root_node = new TreeNode(root_node->nodes[0].first, root_node->nodes[0].second);
    makeTree(tree_root_node, left, right, root_node->next);
    
    vector<int> pre_order;
    preOrder(pre_order, tree_root_node);
    
    vector<int> post_order;
    postOrder(post_order, tree_root_node);
    
    answer.push_back(pre_order);
    answer.push_back(post_order);

    return answer;
}