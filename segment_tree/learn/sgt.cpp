#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define ll long long int


class node{
    public:
    int data;

    node* left;
    node* right;

    node(int t){
        this -> data = t;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};


node* root = nullptr;

node* build_tree(vector<int>& nums,int l,int r){
    node* temp = new node(0);
    if(l==r){
        temp->data=nums[l];

        return temp;
    }

    int mid = (l+r)/2;

    temp->left = build_tree(nums,l,mid);
    temp->right = build_tree(nums,mid+1,r);

    temp->data=temp->left->data + temp->right->data;
}


void print_tree(node* root){
    cout << root->data << endl;

    if(root->left) print_tree(root->left);
    if(root -> right) print_tree(root->right);
}


void update_tree(int index,int val,int l,int r,node* root){
    int mid = (l+r)/2;

    if(l==r){
        cout << "left : " << l << endl;
        root->data=val;
        return;
    }

    if(index <= mid){
        update_tree(index,val,l,mid,root->left);
    }else{
        update_tree(index,val,mid+1,r,root->right);
    }

    root->data=root->left->data + root->right->data;
}


int find_sum(node* root,int l,int r,int rl,int rr){}


void solve(){
    ll n;
    cin >> n;
    vector<int> nums;
    nums.resize(n);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    root = build_tree(nums,0,n-1);
    print_tree(root);
    update_tree(5,19,0,n-1,root);

}





int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    ll t = 1;
    cin >> t;

    while(t--){
        solve();
    }
 
    return 0;
}
