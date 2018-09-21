
#include "build.hpp"
#include <iostream>
#include <algorithm>

int sum_toll(const vector<Bridge> & bridges){
    int total = 0;
    for (auto i : bridges) {
        total += i[TOLL];
    }
    return total;
}

bool collision(const Bridge & a, const Bridge & b)
{
    if((( a[WEST]>=b[WEST])&&(a[EAST]<=b[EAST]))||
        ((a[WEST]<=b[WEST])&&(a[EAST]>=b[EAST])))
        return true;
    return false;
}

bool find_collisions(const vector<Bridge> & bridges){
    for(int i=0;i<bridges.size();i++)
        for (int j=i+1;j<bridges.size();j++) 
            if (collision(bridges[i], bridges[j]))
                return true;
    return false; 
}

vector<Bridge> generate_bridges(const vector<int> & indicies, const vector<Bridge> & bridges)
{
    vector<Bridge> v;
    for (auto i : indicies)
    {
        v.push_back(bridges[i]);
    }
    return v;
}

void generate_combinations(int offset, int k, vector<int> indicies, const vector<Bridge> & bridges, int & max){
  if (k == 0) {
    vector<Bridge> combination = generate_bridges(indicies, bridges);
    if (!find_collisions(combination)){
        int sum = sum_toll(combination);
        if (sum > max) max = sum;
    }
    return;
  }
  for (int i = offset; i <= bridges.size() - k; ++i) {
    indicies.push_back(i);
    generate_combinations(i+1, k-1, indicies, bridges, max);
    indicies.pop_back();
  }
}

int build(int w, int e, const vector<Bridge> & bridges)
{
    vector<Bridge> best;
    vector<int> indicies;
    int max = 0;
    for(int i = bridges.size(); i > 0; --i)
    {
        generate_combinations(0, i, indicies, bridges, max);
    }
    return max;
}
