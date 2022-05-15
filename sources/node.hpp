#include <string>
#include <iostream>
#include <vector>

#ifndef NODE_HEADER
#define NODE_HEADER

using namespace std;

namespace ariel{

    class Node{

        private:

            std::string name;
            std::vector <Node *> children;
            Node * perent;
            Node * next;
            bool is_root;

        public:
            Node(std::string name, Node * perent);
            ~Node();
    };
}
#endif