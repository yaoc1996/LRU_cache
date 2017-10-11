
#ifndef MAIN_YAO_LRUCACHE_H
#define MAIN_YAO_LRUCACHE_H

#include <iostream>
#include <unordered_map>
using namespace std;

namespace main_yao {
    struct Node {
        int key, value;
        Node *prev, *next;
    };

    class LRU {
    public:
        //CONSTRUCTOR
        LRU(int c);

        //MODIFICATION MEMBER FUNCTION
        void put(int key, int value);

        //CONSTANT MEMBER FUNCTION
        int get(int key);

    private:
        unordered_map<int, Node> cache;
        Node *head, *tail;
        int used, capacity;
    };
}

#endif