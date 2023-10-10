#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;

    // Con trỏ đến Node sibling
    Node* nextSibling;

public:
    Node() {
        // ...
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->nextSibling = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    Node(int data, Node* fatherNode = NULL, Node* firstChild = NULL, Node* nextSibling = NULL) {
        this->data = data;
        this->fatherNode = fatherNode;
        this->firstChild = firstChild;
        this->nextSibling = nextSibling;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        // ...
        this->root = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(Node* root) {
        this->root = root;
    }

    // Hàm tìm kiếm
    Node *treeTraversal(Node *p, int data)
    {
        Node *res = NULL;
        if (p->data == data)
        {
            return p;
        }

        if (p->nextSibling == NULL && p->firstChild == NULL)
        {
            return NULL;
        }

        if (p->nextSibling != NULL)
        {
            res = treeTraversal(p->nextSibling, data);
            if (res != NULL)
                return res;
        }

        if (p->firstChild != NULL)
        {
            res = treeTraversal(p->firstChild, data);
        }

        return res;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        Node *inserting = treeTraversal(root, father);
        if (inserting == NULL)
            return 0;
        
        if (inserting->firstChild == NULL) {
            inserting->firstChild = new Node(data, inserting);
            return 1;
        }

        Node *q = inserting->firstChild;
        if (data < q->data) {
            inserting->firstChild = new Node(data, inserting, NULL, q);
            return 1;
        }

        while (q->nextSibling != NULL && q->nextSibling->data < data) {
            q = q->nextSibling;
        }

        if (q->nextSibling != NULL && q->nextSibling->data == data)
            return 0;

        q->nextSibling = new Node(data, inserting, NULL, q->nextSibling);
        return 1;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    

    int removeChild(Node* p) {
        int cnt = 0;
        if (p->firstChild == 0)
            return cnt;
        Node *p1 = p->firstChild;
        while (p1 != NULL) {
            Node *p2 = p1;
            p1 = p1->nextSibling;
            cnt += removeChild(p2);
            delete p2;
            cnt++;
        }
        return cnt;
    }

    int removeProcess(Node* p) {
        Node *q = p->fatherNode->firstChild;
        if (q->data == p->data) {
            p->fatherNode->firstChild = q->nextSibling;
            int cnt = removeChild(p) + 1;
            delete p;
            return cnt;
        }

        while (q->nextSibling->data != p->data) {
            q = q->nextSibling;
        }

        q->nextSibling = p->nextSibling;

        int cnt = removeChild(p) + 1;
        delete p;
        return cnt;
    }

    int remove(int data) {
        Node *removing = treeTraversal(root, data);
        if (removing == NULL)
            return 0;

        return removeProcess(removing);
    }

    // Hàm in ra Node
    void print(Node* p) {
        cout << p->data << " ";
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* p) {
        print(p);
        if (p->nextSibling != NULL) {
            preorder(p->nextSibling);
        }
        
        if (p->firstChild != NULL) {
            preorder(p->firstChild);
        }
    }

    void preorder() {
        preorder(root);
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* p) {
        if (p->firstChild != NULL)
        {
            postorder(p->firstChild);
        }

        if (p->nextSibling != NULL)
        {
            postorder(p->nextSibling);
        }

        print(p);
    }

    void postorder() {
        postorder(root);
    }

    // Hàm kiểm tra cây nhị phân
    bool smallerThan2Child(Node* p) {
        if (p->firstChild == NULL)
            return 1;

        Node *q = p;
        int cnt = 0;
        while (q != NULL) {
            q = q->nextSibling;
            cnt++;
        }
        if (cnt <= 2)
            return 1;
        else
            return 0;
    }

    bool isBinaryTree(Node* p) {
        bool res1(1), res2(1);
        bool res3 = smallerThan2Child(p);
        if (!res3) {
            return res3;
        }

        if (p->firstChild != NULL) {
            res1 = isBinaryTree(p->firstChild);
        }

        if (p->nextSibling != NULL) {
            res2 = isBinaryTree(p->nextSibling);
        }

        return (res1 && res2);
    }

    bool isBinaryTree() {
        return isBinaryTree(root);
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree(Node* p) {
        bool res = 1;
        if (p->firstChild == NULL) {
            return 1;
        }

        if (p->firstChild->data >= p->data) {
            return 0;
        }

        if (p->firstChild->nextSibling != NULL) {
            if (p->firstChild->nextSibling->data <= p->data) {
                return 0;
            }

            if (p->firstChild->nextSibling->firstChild == NULL)
                return 0;

            if (p->firstChild->nextSibling->firstChild->data <= p->data)
                return 0;

            res = isBinarySearchTree(p->firstChild->nextSibling);
            if (!res)
                return res;
        }

        if (p->firstChild->firstChild != NULL) {
            if (p->firstChild->firstChild->nextSibling == NULL) {
                res = isBinarySearchTree(p->firstChild);
                if (!res)
                    return res;
            }

            if (p->firstChild->firstChild->nextSibling->data >= p->data)
                return 0;
        }

        return res;
    }

    bool isBinarySearchTree() {
        if (!isBinaryTree())
            return 0;

        return isBinarySearchTree(root);
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree(Node* p) {
        bool res = 1;
        if (p->firstChild == NULL) {
            return 1;
        }

        Node *q = p->firstChild;
        while (q != NULL) {
            if (p->data < q->data)
                return 0;

            res = isMaxHeapTree(q);
            if (res == 0)
                return res;

            q = q->nextSibling;
        }

        return res;
    }

    bool isMaxHeapTree() {
        return isMaxHeapTree(root);
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    /*void inorder(Node* p) {
        if (p->firstChild != NULL) {
            inorder(p->firstChild);
        }

        print(p);

        if (p->nextSibling != NULL) {
            inorder(p->nextSibling);
        }
    }*/

    void inorder(Node *p)
    {
        /*if (p->firstChild == NULL) {
            print(p);
            return;
        }*/

        if (p->firstChild != NULL)
        {
            inorder(p->firstChild);
        }

        print(p);

        if (p-> firstChild != NULL && p->firstChild->nextSibling != NULL)
        {
            //print(p->fatherNode);
            inorder(p->firstChild->nextSibling);
        }
    }

    void inorder() {
        if (!isBinaryTree()) {
            return;
        }

        inorder(root);
    }

    // Hàm trả về độ cao của cây
    int depth(Node* p) {
        int length = 0;
        while (p->fatherNode != NULL)
        {
            length++;
            p = p->fatherNode;
        }

        return length;
    }

    int max(int a, int b) {
        int max_val = a;
        if (max_val < b)
            max_val = b;

        return max_val;
    }

    int height(Node* p) {
        int h1(0), h2(0);
        if (p->firstChild == NULL && p->nextSibling == NULL) {
            return depth(p);
        }

        if (p->firstChild != NULL) {
            h1 = height(p->firstChild);
        }

        if (p->nextSibling != NULL) {
            h2 = height(p->nextSibling);
        }

        return max(h1, h2);
    }

    int height() {
        return height(root);
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node *selecting = treeTraversal(root, data);
        return depth(selecting);
    }

    // Hàm đếm số lượng lá
    int countLeaves(Node* p) {
        int cnt1(0), cnt2(0);
        if (p->nextSibling != NULL)
        {
            cnt1 = countLeaves(p->nextSibling);
        }

        if (p->firstChild == NULL)
            return cnt1 + 1;

        cnt2 = countLeaves(p->firstChild);
        return cnt2 + cnt1;
    }

    int numOfLeaves() {
        return countLeaves(root);
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax(Node* p) {
        int m1,m2;
        if (p->firstChild == NULL && p->nextSibling == NULL) {
            return p->data;
        }

        if (p->firstChild != NULL) {
            m1 = findMax(p->firstChild);
        }

        if (p->nextSibling != NULL) {
            m2 = findMax(p->nextSibling);
        }
        
        return max(m1, max(m2, p->data));
    }

    int findMax() {
        return findMax(root);
    }

    // Hàm trả về Node có nhiều con nhất
    int countChild(Node* p) {
        int cnt = 0;
        if (p->firstChild == NULL) return cnt;

        Node* q = p->firstChild;
        cnt++;
        while (q->nextSibling != NULL) {
            q = q->nextSibling;
            cnt++;
        }

        return cnt;
    }

    int findMaxChild(Node* p) {
        int n1(0), n2(0);
        if (p->firstChild == NULL && p->nextSibling == NULL)
            return 0;

        int n = countChild(p);

        if (p->nextSibling != NULL) {
            n1 = countChild(p->nextSibling);
        }

        if (p->firstChild != NULL) {
            n2 = countChild(p->firstChild);
        }

        return max(n, max(n1, n2));
    }

    int findMaxChild() {
        return findMaxChild(root);
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree *tree = new Tree(new Node(43));
    cout << tree->insert(43, 14);
    cout << tree->insert(43, 32);
    cout << tree->insert(43, 32);
    cout << tree->insert(43, 24);
    cout << tree->insert(43, 23);
    cout << tree->insert(14, 3);
    cout << tree->insert(13, 2);
    cout << tree->insert(32, 4);
    cout << tree->insert(32, 16);
    cout << tree->insert(32, 31);
    cout << tree->insert(16, 11);
    cout << tree->insert(11, 10);
    cout << tree->insert(11, 9);
    cout << tree->insert(9, 5);
    cout << tree->insert(10, 6);
    cout << tree->insert(23, 22);
    cout << tree->insert(23, 1);
    cout << tree->insert(31, 30);
    cout << tree->insert(22,21);
	cout << tree->insert(21,20);  
	cout << tree->insert(22,18);
	cout << tree->insert(21,15); 
	//cout << tree->insert(23,50); 
	
	cout << '\n';
	cout << tree->remove(16);
	
	cout << '\n';
	cout << tree->remove(14);
	
	cout << '\n';
	cout << tree->remove(24); 
	
    cout << '\n';
    tree->preorder();
    
    cout << '\n';
    tree->postorder() ;
    // Test thử các hàm của lớp cây
    cout << '\n';
    cout << tree->isBinaryTree() ;
    
    cout << '\n';
    cout << tree->depth(31);
	
	cout << '\n';
	cout << tree->height();  
	
	cout << '\n';
	cout << tree->numOfLeaves();
	
	
	cout << '\n';
	cout << tree->findMax();
	
	cout << '\n';
	cout << tree->findMaxChild();
	
	cout << '\n';
	tree->inorder();
	
	cout << '\n';
	cout << tree->isMaxHeapTree();
	
	/*cout << tree->insert(43, 55);
	cout << tree->insert(14,3);
	cout << tree->insert(14, 17);
	cout << tree->insert(55, 40);*/
	
	cout << '\n';
	cout << tree->isBinarySearchTree();

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
