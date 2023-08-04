#include <bits/stdc++.h> 
using namespace std;


    template <typename T>
    class BTreeNode {
        public:
        T val;
        BTreeNode < T > * left;
        BTreeNode < T > * right;

        BTreeNode(T val) {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

    template <typename T>
    class NTreeNode {
        public:
        T val;
        vector < NTreeNode < T > * > child;

        NTreeNode(T val) {
            this -> val = val;
        }
    };

T