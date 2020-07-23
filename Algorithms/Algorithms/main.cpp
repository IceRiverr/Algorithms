//
//  main.cpp
//  Algorithms
//
//  Created by IceRiver on 2020/7/23.
//  Copyright © 2020 IceRiver. All rights reserved.
//

#include <iostream>
#include <list>
#include <queue>

struct Node
{
    int v;
    Node* leftNode;
    Node* rightNode;
};

// 层序遍历，借用队列辅助即可，根节点先入队列，然后循环从队列中pop节点，
// 将pop出来的节点的左子节点先入队列，右节点后入队列，依次循环，直到队列为空，遍历结束。
std::list<Node*> level_order(Node* tree)
{
    if(tree == nullptr)
        return std::list<Node*>();
    else
    {
        std::list<Node*> nodes = std::list<Node*>();
        std::queue<Node*> q;
        q.push(tree);
        
        while (!q.empty())
        {
            Node* n = q.front();
            nodes.push_back(n);
            q.pop();
            if(n->leftNode)
                q.push(n->leftNode);
            if(n->rightNode)
                q.push(n->rightNode);
        }
        return nodes;
    }
}

void TEST_level_order()
{
    Node* tree = new Node();
    tree->v = 1;
    
    Node* b = new Node();
    b->v = 2;
    
    Node* c = new Node();
    c->v = 3;
    
    tree->leftNode = b;
    tree->rightNode = c;
    
    Node* d = new Node();
    d->v = 4;
    
    Node* e = new Node();
    e->v = 5;
    
    b->leftNode = d;
    b->rightNode = e;
    
    Node* f = new Node();
    f->v = 6;
    
    Node* g = new Node();
    g->v = 7;
    
    c->leftNode = f;
    c->rightNode = g;
    
    Node* h = new Node();
    h->v = 8;
    
    e->leftNode = nullptr;
    e->rightNode = h;
    
    std::list<Node*> level_nodes = level_order(tree);
    
    for(const auto& n : level_nodes)
    {
        std::cout << n->v << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TEST_level_order();
    
    return 0;
}
