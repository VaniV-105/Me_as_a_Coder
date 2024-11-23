#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class AVLNode{
public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
    AVLNode(T val):data(val),height(1),right(nullptr),left(nullptr){}
};
template <typename T>
class AVLTree{
private:
    AVLNode<T>* root;
    int height(AVLNode<T>* node){
        if(node==nullptr)
            return 0;
        return node->height;
    }
    int balanceFactor(AVLNode<T>* node){
        if(node==nullptr)
            return 0;
        return height(node->left)-height(node->right);
    }
    AVLNode<T>* rightRotate(AVLNode<T>* y){
        AVLNode<T>* x=y->left;
        AVLNode<T>* T2=x->right;
        x->right=y;
        y->left=T2;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
        return x;
    }
    AVLNode<T>* leftRotate(AVLNode<T>* x){
        AVLNode<T>* y=x->right;
        AVLNode<T>* T2=y->left;
        y->left=x;
        x->right=T2;
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;
        return y;
    }
    AVLNode<T>* insertNode(AVLNode<T>* node,T val){
        if(node==nullptr)
            return new AVLNode<T>(val);
        if(val<node->data){
            node->left = insertNode(node->left,val);
        }
        else if(val>node->data){
            node->right = insertNode(node->right,val);
        }
        else    
            return node;
        node->height=1+max(height(node->left),height(node->right));
        int balance = balanceFactor(node);

        if(balance>1 && val<node->left->data)
            return rightRotate(node);
        if(balance<-1 && val>node->right->data)
            return leftRotate(node);
        if(balance>1 && val>node->left->data){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        if(balance<-1 && val<node->right->data){
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    AVLNode<T>* minValueNode(AVLNode<T>* node){
        AVLNode<T>* current = node;
        while(current->left!=nullptr){
            current=current->left;
        }
        return current;
    }
    AVLNode<T>* deleteNode(AVLNode<T>* root,int key){
        if(root==nullptr)
            return root;
        if(key<root->data)
            root->left = deleteNode(root->left,key);
        else if(key>root->data)
            root->right = deleteNode(root->right,key);
        else{
            if(root->right==nullptr || root->left==nullptr){
                AVLNode<T>* temp = root->left?root->left:root->right;
                if(temp==nullptr){
                    temp=root;
                    root=nullptr;
                }else{
                    *root=*temp;
                }
                delete temp;
            }else{
                AVLNode<T>* temp = minValueNode(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
            if(root==nullptr)
                return root;
            root->height = 1+max(height(root->left),height(root->right));
            int balance = balanceFactor(root);
            if(balance>1 && balanceFactor(root->left)>=0)
                return rightRotate(root);
            if(balance>1 && balanceFactor(root->left)<0){
                root->left=leftRotate(root->left);
                return rightRotate(root);
            }
            if(balance<-1 && balanceFactor(root->right)<=0)
                return leftRotate(root);
            if(balance<-1 && balanceFactor(root->right)>0){
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
    }
    void search(AVLNode<T>* root,T val){
        if(root==nullptr)
            cout<<"Element not found";
        if(root->data==val){
            cout<<"Element found";
        }
        else if(val<root->data){
            search(root->left,val);
        }
        else{
            search(root->right,val);
        }
    }
    void preOrder(AVLNode<T>* root){
        if(root==nullptr)
            return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(AVLNode<T>* root){
        if(root==nullptr)
            return;
        inOrder(root->left);
        cout<<root->data<<" with height "<<root->height<<endl;
        inOrder(root->right);
    }

    void postOrder(AVLNode<T>* root){
        if(root==nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
    public:
        AVLTree():root(nullptr){}
        void insert(T val){
            root=insertNode(root,val);
        }
        void remove(T val){
            root = deleteNode(root,val);
        }
        void display(){
            preOrder(root);
            cout<<endl;
            inOrder(root);
            cout<<endl;
            postOrder(root);
            cout<<endl;
            search(root,128);
        }
};
int main(){
    AVLTree<int> avlTree;
    int flag=1,ch,n;
    while(flag){
        cout<<"Menu:AVL Tree:"<<endl;
        cout<<"1.Insertion."<<endl;
        cout<<"2.Deletion."<<endl;
        cout<<"3.Display."<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the element to be inserted:";
                cin>>n;
                avlTree.insert(n);
                break;
            case 2:
                cout<<"Enter the element to be removed:";
                cin>>n;
                avlTree.remove(n);
                break;
            case 3:
                avlTree.display();
                break;
            default:
                flag=0;
        }

    }
    return 0;
}