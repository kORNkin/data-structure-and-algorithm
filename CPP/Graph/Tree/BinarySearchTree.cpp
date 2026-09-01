#include<bits/stdc++.h>
using namespace std;

class ArrayBST{
    vector<int> tree;
    int sz;
    private:
        int leftChild(int idx) const { return (idx<<1) + 1; }
        int rightChild(int idx) const { return (idx<<1) + 2; } 
        
        void adjustSize(int idx){
            if(idx < sz) return;
            tree.resize((idx<<1) + 3, -1);
            sz = (idx<<1) + 4;
        }

        bool hasNode(int idx) { return idx >= 0 && idx < sz && tree[idx] != -1; }

        int findMaxIndex(int idx){
            while(hasNode(rightChild(idx))) idx = rightChild(idx);
            return idx;
        }

        int findMinIndex(int idx){
            while(hasNode(leftChild(idx))) idx = leftChild(idx);
            return idx;
        }
        
        void deleteIdx(int idx){
            int leftIdx = leftChild(idx);
            int rightIdx = rightChild(idx);
            bool hasLeft = hasNode(rightIdx);
            bool hasRight = hasNode(leftIdx);

            if(!hasLeft && !hasRight){
                tree[idx] = -1;
            } else if (hasLeft && !hasRight){
                int successorIdx = findMaxIndex(leftIdx);

                tree[idx] = tree[successorIdx];
                deleteIdx(successorIdx);
            } else {
                int successorIdx = findMinIndex(rightIdx);

                tree[idx] = tree[successorIdx];
                deleteIdx(successorIdx);
            }
        }

    public:
        explicit ArrayBST(int initialSize = 16){
            sz = initialSize;
            tree.resize(sz, -1);
        }

        void insert(int num){   
            int idx = 0;
            adjustSize(idx);

            while(tree[idx] != -1){
                if(tree[idx] >= num) idx = leftChild(idx);
                else idx = rightChild(idx);

                adjustSize(idx);
            }
            tree[idx] = num;
        }
        
        int find(int num){
            int idx = 0;
            int sz = tree.size();

            while(hasNode(idx)){
                if(tree[idx] == num) return idx;
                if(tree[idx] > num) idx = leftChild(idx);
                else idx = rightChild(idx);
            }

            return -1;
        }

        bool deleteNode(int num){
            int idx = find(num);
            if(idx == -1) return false;

            deleteIdx(idx);
            return true;
        }

        void preorderTraversal(int idx){
            if(!hasNode(idx)) return;

            cout << tree[idx] << ' ';
            preorderTraversal(leftChild(idx));
            preorderTraversal(rightChild(idx));
        }

        void inorderTraversal(int idx){
            if(!hasNode(idx)) return;

            inorderTraversal(leftChild(idx));
            cout << tree[idx] << ' ';
            inorderTraversal(rightChild(idx));
        }

        void postorderTraversal(int idx){
            if(!hasNode(idx)) return;

            postorderTraversal(leftChild(idx));
            postorderTraversal(rightChild(idx));
            cout << tree[idx] << ' ';
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nums[] = {2, 5, 1, 6, 8, 3, 9, 10, 4, 7};
    int sz = sizeof(nums) / sizeof(nums[0]);

    ArrayBST bst;

    for(int n : nums) bst.insert(n);

    bst.preorderTraversal(0);
    cout << '\n';
    bst.inorderTraversal(0);
    cout << '\n';
    bst.postorderTraversal(0);
    cout << '\n';
    
    bst.deleteNode(2);
    
    bst.inorderTraversal(0);
    cout << '\n';

    return 0;
}