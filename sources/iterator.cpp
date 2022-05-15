#include "iterator.hpp"
#include "node.hpp"
#include "OrgChart.hpp"

using namespace std;

using namespace ariel;

    Iterator:: Iterator(int flag){
        this->flag= flag;
    }
 
    Iterator::~Iterator(){}