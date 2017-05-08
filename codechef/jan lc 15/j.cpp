// Learned this implementation of segment from http://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/

// Author Jinank Jain

#include<bits/stdc++.h>
using namespace std;

// Segment Tree Node Structure
struct SegmentTreeNode{

    int c[3]={0},sum=0;

    void assignLeaf(char value){
        for(int i=0;i<3;i++) c[i] = 0;
        sum = (value - 48)%3;
        c[sum] = 1;
    }

    void merge(SegmentTreeNode& left, SegmentTreeNode& right){
        sum =0;
        sum = (left.sum + right.sum)%3;
        for(int i=0;i<3;i++) c[i] = 0;
        for (int i = 0; i < 3; i++) {
            if(i==0){
            c[i] += left.c[i];
            c[(i + left.sum) % 3] += (right.c[i]-1);
            }else{
                c[i] += left.c[i];
            c[(i + left.sum) % 3] += (right.c[i]);

            }
        }
    }

    long long getValue(){
        long long res = 0;
        for (int i = 0; i < 3; i++) {
            long long curr = c[i];
            if (i == 0)
                curr++;
            res += (curr * (curr - 1))   / 2;
        }
        return res;
    }
};

// Generic Segment Tree operation
template<class T, class V>
class SegmentTree{
    SegmentTreeNode* nodes;
    int N;

    public:
        // Constructor
        SegmentTree(T arr[], int N){
            this->N = N;
            nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
            buildTree(arr, 1, 0, N-1);
        }

        // Destructor
        ~SegmentTree(){
            delete[] nodes;
        }

        V getValue(int lo, int hi) {
            SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
            return result.getValue();
        }

        void update(int index, T value){
            update(1, 0, N-1, index, value);
        }

    private:
        void buildTree(T arr[], int stIndex, int lo, int hi){
            if(lo==hi){
                nodes[stIndex].assignLeaf(arr[lo]);
                return;
            }
            int left = 2*stIndex;
            int right = left + 1;
            int mid = (lo+hi)/2;
            buildTree(arr, left, lo, mid);
            buildTree(arr, right, mid+1, hi);
            nodes[stIndex].merge(nodes[left], nodes[right]);
        }

        int getSegmentTreeSize(int N) {
            int size = 1;
            for (; size < N; size <<= 1);
            return size << 1;
        }

        SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi){
            if(lo==left && hi==right){
                return nodes[stIndex];
            }
            int mid = (left + right)/2;

            if(lo > mid){
                return getValue(2*stIndex+1, mid+1, right, lo, hi);
            }
            if(hi <= mid){
                return getValue(2*stIndex, left, mid, lo, hi);
            }

            SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
            SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
            SegmentTreeNode result;
            result.merge(leftResult, rightResult);
            return result;
        }

        void update(int stIndex, int lo, int hi, int index, T value){
            if(lo==hi){
                nodes[stIndex].assignLeaf(value);
                //cout<<nodes[stIndex].c[0]<<" "<< nodes[stIndex].c[1]<<" "<<nodes[stIndex].c[2] <<endl;
                return;
            }
            int left = 2*stIndex;
            int right = left + 1;
            int mid = lo + (hi-lo)/2;

            if(index <= mid){
                update(left, lo, mid, index, value);
            }
            else{
                update(right, mid+1, hi, index, value);
            }
            nodes[stIndex].merge(nodes[left], nodes[right]);
        }
};

int main(){
    //ios_base::sync_with_stdio(false);
    int n,m,q,x,y;
    scanf("%d %d", &n, &m);
    char a[n],z;
    scanf("%s", &a);
    SegmentTree<char, int> st(a,n);
    while(m--){
        scanf("%d", &q);
        if(q==1){
            scanf("%d %c", &x, &z);
            //cout<<z<<endl;
            st.update(x-1, z);
        }else{
            scanf("%d %d", &x, &y);
            printf("%d\n", st.getValue(x-1,y-1));
        }
    }
    return 0;
}

