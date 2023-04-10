
#pragma once

#include <iostream>
#include <string>
#include <vector>


class DisjointSets
{
  public:
   
    void addelements(int num);


    void setunion(int a, int b);
    
 
    int find(int elem);
    
    int size(int elem);

    private:
        std::vector<int> elements;

};
