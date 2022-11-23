#include <iostream>

using namespace std;

int  depth = 0;
bool flag = false;
struct node {
    string data;
    struct node *left, *right;
};
node* newNode(string data) {
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return(temp);
}
int getOpCode(string cmd) {
    string command[] = { "+", "-", "depth", "leaf", "quit" };
    for(int i = 0 ; i < 5 ; i++) {
        if(command[i] == cmd) return i;
    }
    return -1;
}
node* minValueNode(node* temp) {
    node* current = temp;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
string successor(node* root) {
    root = root->right;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
string predecessor(node* root) {
    root = root->left;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
bool searchValue(node* root, string data) {
    node* x = new node;
    x = root;
    node* y = NULL;

    while (x != NULL) {
        if (x->data == data) return true;
        else if (x->data > data) x = x->left;
        else x = x->right;
        depth ++;
    }
    return false;
}
node* insertBTS(node* root, string data) {
    if (searchValue(root, data)) return root;
    node* newnode = newNode(data);
    node* x = root;
    node* y = NULL;
    while (x != NULL) {
        y = x;
        if (data < x->data) x = x->left;
        else x = x->right;
    }
    if (y == NULL) y = newnode;
    else if (data < y->data) y->left = newnode;
    else y->right = newnode;
    return y;
}

node* deleteBTS(node* root, string data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteBTS(root->left, data);
    else if (data > root->data)
        root->right = deleteBTS(root->right, data);
    else {
        if (root->left==NULL && root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            root->data = successor(root);
            root->right = deleteBTS(root->right, root->data);
            return root;
        }
        else if (root->right == NULL) {
            root->data = predecessor(root);
            root->left =  deleteBTS(root->left, root->data);
            return root;
        }
        node* temp = minValueNode(root->left);
        root->data = temp->data;
        root->left = deleteBTS(root->left, temp->data);
    }
    return root;
}
void getDepth(node* root, node* origin, int k) {
    node* x = root;
    if (x == NULL) return;
    getDepth(x->left, origin, k);
	depth = 0;
    searchValue(origin, x->data);
    if (depth == k) {
        flag = true;
        cout << x->data << " ";
    }
	getDepth(x->right, origin, k);
}
string getLeaf(node* node) {
    if(node == NULL) return "";
    if(node->left == NULL && node->right == NULL) return node->data+" ";
    return getLeaf(node->left) + getLeaf(node->right);
}

void startBTS() {
    string inp, bts;
    int btsDepth;
    node* root = NULL;
    root = insertBTS(root, "");
    while (cin >> inp) {
        switch(getOpCode(inp)) {
        case 0 : cin >> bts; insertBTS(root, bts); break;
        case 1 : cin >> bts; deleteBTS(root, bts); break;
        case 2 : cin >> btsDepth; flag = false;
                 getDepth(root, root, btsDepth);
                 if (!flag) cout << "NO";
                 cout << endl; break;
        case 3 : cout << getLeaf(root) << endl; break;
        case 4 : return;
        default: break;
        }
    }
}
int main() {
    startBTS();
    return 0;
}
