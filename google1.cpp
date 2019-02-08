#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode-> val= val;
    newNode-> left = newNode-> right = NULL;
    return newNode;
}

void constructTree(int parent[], Node* created[], int i, int n, Node** root){

    if(created[i]){
        return;
    }
    if(created[i] == NULL){
        created[i] = createNode(i);
    }
    if(parent[i] == -1){
        *root = created[i];
        return;
    }else if(created[parent[i]] == NULL){
        constructTree(parent, created, parent[i], n, root);
    }
    Node* parentNode = created[parent[i]];
    if(parentNode-> left){
            parentNode-> right = created[i];
    }else{
            parentNode-> left = created[i];
    }
}
void inorder(Node* root){
    if(root == NULL){
        //cout <<"root is null" << endl;
        return;
    }
    inorder(root-> left);
    cout<< root-> val<< endl;
    inorder(root-> right);
}
void findKNodes(int kNodes[], Node* root, vector<int> path, int k){
    if(root == NULL){
        return;
    }
    //cout << "pushing "<<root-> val<< endl;
    path.push_back(root-> val);
    findKNodes(kNodes, root-> left, path, k);
    findKNodes(kNodes, root-> right, path, k);
    int cur = root-> val;
    cout<< "path size is "<<path.size() << endl;
    if(path.size() > k){
        kNodes[cur] = path[path.size() - k - 1];
        cout <<"cur "<<cur <<" has ancestor "<< kNodes[cur] << endl;
    }else{
        cout <<"no ancestor for "<<cur << endl;
        kNodes[cur] = -1;
        cout << kNodes[cur] << endl;
    }
    path.pop_back();

}
int main(){
    int parent[]= {1, 5, 5, 2, 2, -1, 3};
    int sz = sizeof(parent)/sizeof(parent[0]);
    Node* root = NULL;
    Node* created[sz];
    for(int i = 0; i < sz; i++){
        created[i] = NULL;
    }
    for(int i = 0; i < sz; i++){
        constructTree(parent, created, i, sz, &root);
    }
    //inorder(root);
    int kNodes[sz] = {0};
    vector<int> path;
    int k = 2;
    findKNodes(kNodes, root, path, k);
    cout <<"------------" <<endl;
    for(int i = 0; i < sz; i++){
        cout << kNodes[i] << endl;
    }
    return 0;
}
