#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSets {
    private:
        vector<int> elems;

    public:
        DisjointSets (vector<Video> input) {
            addelements(input.size());

        }
        void DisjointSets::addelements(int num) {
                for (int i = 0; i < num; i++) {
                    elems.push_back(-1);
                }
        }

        int DisjointSets::find(int elem) {
                if (elems[elem] < 0) {
                    return elem;
                } else {
                    return find(elems[elem]);
                }
        }
        
        void DisjointSets::setunion(int a, int b) {
                int a_root = find(a);
                int b_root = find(b);
                int total_size = elems[a_root] + elems[b_root];

                if (elems[a_root] <= elems[b_root]) {
                    //swap, which let the a_root become the bigger set
                    elems[b_root] = a_root;
                    //then we can update the total size
                    elems[a_root] = total_size;
                } else {
                    elems[a_root] = b_root;
                    elems[b_root] = total_size;
                }
        }

        int DisjointSets::size(int elem) {
                
                    return elems[find(elem)] * -1;
                }           
        

};