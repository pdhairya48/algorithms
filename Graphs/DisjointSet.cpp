//
// Created by Dhairya V Parekh on 01/07/23.
//

#include <iostream>
#include "../stdc++.h"
using namespace std;

class DisjointSet {
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }


    }

    int findPar(int value){
        if(parent[value]==value){
            return value;
        }
        parent[value]=findPar(parent[value]);
        return parent[value];
    }

    void unionByRank(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)
            return ;
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u]=ul_v;
        }
        else if(rank[ul_u]>rank[ul_v]){
            parent[ul_v]=ul_u;
        }
        else {
            parent[ul_u]=ul_v;
            rank[ul_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)
            return ;
        if(size[ul_u]<size[ul_v]){
            parent[ul_u]=ul_v;
            size[ul_v]+=size[ul_u];
        }
        else {
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
    }

};