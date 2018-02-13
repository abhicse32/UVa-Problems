#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vi>
#define vvii vector<vii>
#define sc(n) scanf("%d\n",&n)
#define scc(n,m) scanf("%d%d\n",&n,&m)
#define repf(i,a,b) for(i=a;i<b;++i)
#define gc getchar_unlocked

typedef struct Quad_Node Q_node;
typedef struct Quad_Tree Q_tree;

struct Quad_Node{
    char key;
    Q_node* ne;
    Q_node* nw;
    Q_node* sw;
    Q_node* se;
    Quad_Node(char color);
};

struct Quad_Tree{
    Q_node* root;
    Quad_Tree();
    void pre_order(Q_node*);
};

Quad_Tree::Quad_Tree(){
    root=nullptr;
}

Quad_Node::Quad_Node(char color){
    key= color;
    ne=sw=nw=se= nullptr;
}

Q_node* build_tree(string str, Q_node* q_node,int* index){
    q_node= new Q_node('p'); 
    int i;
    for(i=0,++(*index);i<4 && *index<str.size();++i,++(*index)){
        switch(i){
            case 0:
                if(str[*index]=='p')
                    q_node->ne=build_tree(str,q_node->ne,index),--(*index);
                else q_node->ne= new Q_node(str[*index]);
                break;         
            case 1: 
                if(str[*index]=='p')
                    q_node->nw=build_tree(str,q_node->nw,index),--(*index);
                else q_node->nw= new Q_node(str[*index]);
                break;         
            case 2:
                if(str[*index]=='p')
                    q_node->sw=build_tree(str,q_node->sw,index),--(*index);
                else q_node->sw= new Q_node(str[*index]);
                break;         
            case 3:
                if(str[*index]=='p')
                    q_node->se=build_tree(str,q_node->se,index),--(*index);
                else q_node->se= new Q_node(str[*index]);
                break;         
            default:
                break;        
        }
    }
    return q_node;
}

void Q_tree::pre_order(Q_node* node){
    if(node){
        printf("%c ",node->key);
        pre_order(node->ne);
        pre_order(node->nw);
        pre_order(node->sw);
        pre_order(node->se);
    }
}

Q_node* create_overlapped_tree(Q_node* node1, Q_node* node2, Q_node* node3){
    if(!node1) return node2;
    if(!node2) return node1;
    if(node1->key=='f'||(node1->key=='p' && node2->key=='e'))
        return node1;
    if(node2->key=='f'||(node2->key=='p' && node1->key=='e'))
        return node2;     
    else if(node1->key=='e')
        return node1;
    else{
        node3=new Q_node('p');
        node3->ne= create_overlapped_tree(node1->ne,node2->ne,node3->ne);
        node3->nw= create_overlapped_tree(node1->nw,node2->nw,node3->nw);
        node3->sw= create_overlapped_tree(node1->sw,node2->sw,node3->sw);
        node3->se= create_overlapped_tree(node1->se,node2->se,node3->se);
    }
    return node3; 
}

int calc_black_pixels(Q_node* root, int side_len){
    if(!root ||root->key=='e') return 0;
    else if(root->key=='f')
       return (side_len*side_len);
    
    else return calc_black_pixels(root->ne,(side_len>>1))+
               calc_black_pixels(root->nw,(side_len>>1))+
               calc_black_pixels(root->sw,(side_len>>1))+
               calc_black_pixels(root->se,(side_len>>1)); 
}

int main(){
    int i,j,k,t;
    sc(t);
    string str1,str2;
    while(t--){
        cin >> str1 >> str2;
        Q_tree *q_tree1=new Q_tree();
        Q_tree *q_tree2=new Q_tree();
        i=0,j=0;
        if(str1[i]=='p')
            q_tree1->root=build_tree(str1,q_tree1->root,&i);
        else q_tree1->root= new Q_node(str1[i]);
        if(str2[j]=='p')
            q_tree2->root=q_tree2->root=build_tree(str2,q_tree2->root,&j);
        else q_tree2->root= new Q_node(str2[j]);
        Q_tree* res_tree= new Q_tree();
        res_tree->root= create_overlapped_tree(q_tree1->root,q_tree2->root,res_tree->root);
        int black_pixels= calc_black_pixels(res_tree->root,32); 
        printf("There are %d black pixels.\n",black_pixels);
    } 
}
