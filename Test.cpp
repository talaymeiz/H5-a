#include "doctest.h"
#include <string>
#include <algorithm>
using namespace std;

#include "OrgChart.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace ariel;

TEST_CASE("One Root") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     

    auto it = org1.begin_level_order();
    std::string name= (*it);
    CHECK_EQ(name,"Employee_1"); //first root

    std::string names1= "";
    for (auto it = org1.begin_level_order(); it != org1.end_level_order(); ++it) //org1 befor change
    {
        names1 += (*it);
        names1 += " ";
    }

    org1.add_root("Employee_1_new");
    it = org1.begin_level_order();
    name= (*it);
    CHECK_EQ(name,"Employee_1_new"); //root after change

    std::string names2= "";
    for (auto it = org1.begin_level_order(); it != org1.end_level_order(); ++it) //org1 after change
    {
        names2 += (*it);
        names2 += " ";
    }

    CHECK_EQ(names1,names2); //The order of the tree should not change
 
}

TEST_CASE("Chack LEVEL_ORDER") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    std::string names= "";
    for (auto it = org1.begin_level_order(); it != org1.end_level_order(); ++it)
    {
        names += (*it); //Add names in level_order
        names += " ";
    }
    std::string t_names="Employee_1 Employee_2_1 Employee_2_2 Employee_2_3 Employee_3_1 Employee_3_2 "; //expected order

    CHECK_EQ(names, t_names);
    
}

TEST_CASE("Chack Operators Of LEVEL_ORDER") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    // iter++
    std::string name;
    int num=0;
    for (auto it = org1.begin_level_order(); num<3; num++) //Advanced to fourth
    {
        it++;
        if(num==2){}
            // name=(*it++); } //save him befaor advanced
    }
    CHECK_EQ(name, "Employee_2_3");

    // ++iter
    num=0;
    for (auto it = org1.begin_level_order(); num<3; num++) //Advanced to fourth
    {
        ++it;
        if(num==2){
            name=(*(++it)); } //Takes the fifth after progress
    }
    CHECK_EQ(name, "Employee_3_1");

    // !=
    num=0;
    for (auto it = org1.begin_level_order(); num<5; it++)
    {
        CHECK(it != org1.end_level_order()); //All first five in order are different from last
        num++;
    }

    // ==
    num=0;
    for (auto it = org1.begin_level_order(); it != org1.end_level_order(); it++)
    {
        if (num==0){
            CHECK(it == org1.begin_level_order()); //the first one
        }
        num++;
        if (num==5){
            it++;
            CHECK(it == org1.end_level_order()); //the last one
        }
    }

}

TEST_CASE("Chack REVERSE_ORDER") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    std::string names= "";
    for (auto it = org1.begin_reverse_order(); it != org1.reverse_order(); ++it)
    {
        names += (*it); //Add names in reverse_order
        names += " ";
    }
    std::string t_names="Employee_3_1 Employee_3_2 Employee_2_1 Employee_2_2 Employee_2_3 Employee_1 "; //expected order
    CHECK_EQ(names, t_names);
    
}

TEST_CASE("Chack Operators Of REVERSE_ORDER") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    // iter++
    std::string name;
    int num=0;
    for (auto it = org1.begin_reverse_order(); num<3; num++) //Advanced to fourth
    {
        it++;
        if(num==2){}
            // name = *it; } //save him befaor advanced
    }
    CHECK_EQ(name, "Employee_2_2");

    // ++iter
    num=0;
    for (auto it = org1.begin_reverse_order(); num<3; num++) //Advanced to fourth
    {
        if(num==2){
            name=(*++it); } //Takes the fifth after progress
    }
    CHECK_EQ(name, "Employee_2_3");

    // !=
    num=0;
    for (auto it = org1.begin_reverse_order(); num<5; it++)
    {
        CHECK(it != org1.reverse_order()); //All first five in order are different from last
        num++;
    }

    // ==
    num=0;
    for (auto it = org1.begin_reverse_order(); it != org1.reverse_order(); it++)
    {
        if (num==0){
            CHECK(it == org1.begin_reverse_order()); //the first one
        }
        num++;
        if (num==5){
            it++;
            CHECK(it == org1.reverse_order()); //the last one
        }
    }

}

TEST_CASE("Chack PREORDER") {

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    std::string names= "";
    for (auto it=org1.begin_preorder(); it!=org1.end_preorder(); ++it)
    {
        names += (*it); // Add names in preorder
        names += " ";
    }
    std::string t_names="Employee_1 Employee_2_1 Employee_3_1 Employee_2_2 Employee_2_3 Employee_3_2 "; //expected order
    CHECK_EQ(names, t_names);

}

TEST_CASE("Chack Operators Of PREORDER"){

    ariel::OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    // iter++
    std::string name;
    int num=0;
    for (auto it = org1.begin_preorder(); num<3; num++) //Advanced to fourth
    {
        if(num==2){
            name=(*it++); } //save him befaor advanced
    }
    CHECK_EQ(name, "Employee_2_2");

    // ++iter
    num=0;
    for (auto it = org1.begin_preorder(); num<3; num++) //Advanced to fourth
    {
        if(num==2){
            name=(*++it); } //Takes the fifth after progress
    }
    CHECK_EQ(name, "Employee_2_3");

    // !=
    num=0;
    for (auto it = org1.begin_preorder(); num<5; it++)
    {
        CHECK(it != org1.end_preorder()); //All first five in order are different from last
        num++;
    }

    // ==
    num=0;
    for (auto it = org1.begin_preorder(); it != org1.end_preorder(); it++)
    {
        if (num==0){
            CHECK(it == org1.begin_preorder()); //first one
        }
        num++;
        if (num==5){
            it++;
            CHECK(it == org1.end_preorder()); //last one
        }
    }

}

TEST_CASE("The usual iteration") {

    OrgChart org1;
    CHECK_NOTHROW(org1.add_root("Employee_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1"));        
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_2"));     
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_3"));     
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_3_1"));
    CHECK_NOTHROW(org1.add_sub("Employee_2_3", "Employee_3_2"));

    std::string names= "";
    for (auto element : org1)
    {
        names += element;
        names += " ";
    }
    std::string t_names="Employee_1 Employee_2_1 Employee_2_2 Employee_2_3 Employee_3_1 Employee_3_2 ";
    CHECK_EQ(names, t_names);
}

TEST_CASE("Chack add_sub") {

    ariel::OrgChart org1;
    org1.add_root("Employee_1");

    CHECK_THROWS(org1.add_sub("Employee_3", "Employee_2_1"));  // Employee_3 not in org1
    CHECK_NOTHROW(org1.add_sub("Employee_1", "Employee_2_1")); // Employee_1 in org1
    CHECK_NOTHROW(org1.add_sub("Employee_2_1", "Employee_1"));  // You can add a vertex twice  

}

