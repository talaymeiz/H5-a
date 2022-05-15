#include <string>
#include <iostream>
#include "node.hpp"
#include "iterator.hpp"

#ifndef ORGCHART_HEADER
#define ORGCHART_HEADER

using namespace std;

namespace ariel{

    class OrgChart{

        private:

            Node * root;

        public:

            OrgChart();
            OrgChart& add_root(std::string root);
            OrgChart& add_sub (std::string perent, std::string son); 
            
            std::string* begin_level_order();
            std::string* end_level_order();
            
            std::string* begin_reverse_order();
            std::string* reverse_order();
            
            std::string* begin_preorder();
            std::string* end_preorder();

            friend std::ostream &operator<<(std::ostream &o, OrgChart const &orgChart);
            int* begin();
            int* end();

            // ~OrgChart();
    };
}
#endif