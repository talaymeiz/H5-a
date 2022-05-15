#include "iterator.hpp"
#include "node.hpp"
#include "OrgChart.hpp"

using namespace std;

namespace ariel{

    OrgChart:: OrgChart(){}

    OrgChart& OrgChart::add_root(std::string root){
        return *this;
    }
    OrgChart& OrgChart::add_sub (std::string perent, std::string son){
        return *this;
    }
        
    std::string* OrgChart::begin_level_order(){
        std::string* it;
        return it;
    }
    std::string* OrgChart::end_level_order(){
        std::string* it;
        return it;
    }
        
    std::string* OrgChart::begin_reverse_order(){
        std::string* it;
        return it;
    }
    std::string* OrgChart::reverse_order(){
        std::string* it;
        return it;
    }
            
    std::string* OrgChart::begin_preorder(){
        std::string* it;
        return it;
    }
    std::string* OrgChart::end_preorder(){
        std::string* it;
        return it;
    }


    std::ostream &operator<<(std::ostream &o, OrgChart const &orgChart) {return cout<<"123";}
    int* OrgChart::begin(){
        int* it;
        return it;
    }
    int* OrgChart::end(){
        int* it;
        return it;
    }

    // OrgChart::~OrgChart(){}
}