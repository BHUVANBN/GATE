//lower triangular matrix - a square matrix where all elements above the main diagonal are zero
/*
eg:
    1 0 0 0 
    2 3 0 0 
    4 5 6 0 
    7 8 9 10 
    
    condition M[i,j]= 0 for all i<j
    for any n x n matrix, there are n(n+1)/2 non zero elements

    stored in 1D array
    row major mapping of lower triangular matrix to 1D array
    - elements are added row wise in an array
    M[i,j] = A[i*(i-1)/2 + j-1]
    eg: M[2,1] = A[2*(2-1)/2 + 1-1] = A[1]
        M[1,1] = A[1*(1-1)/2 + 1-1] = A[0]
    
    column major mapping of lower triangular matrix to 1D array
    - elements are added column wise in an array
    M[i,j] = A[(j-1)*j/2 + i-1]
    eg: M[2,1] = A[(1-1)*1/2 + 2-1] = A[0]
        M[1,1] = A[(1-1)*1/2 + 1-1] = A[0]
*/
#include <iostream>
using namespace std;

//struct implementation
struct Matrix {
    int *A;
    int n;
};
void setEle(struct Matrix *m, int i, int j, int ele) {
    if (i >= j) {
        m->A[i*(i-1)/2 + j-1] = ele;
    }
}
int getEle(struct Matrix m, int i, int j) {
    if (i >= j) {
        return m.A[i*(i-1)/2 + j-1];
    }
    return 0;
}
void display(struct Matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            cout << getEle(m, i, j) << " ";
        }
        cout << endl;
    }
}
//class implementation
class LowerT{
    private:
        int *A;
        int n;
    public:
        LowerT(){
            n=2;
            A=new int[2*(2+1)/2];
        }
        LowerT(int n){
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        void setEle(int i, int j, int ele) {
            if (i >= j) {
                A[i*(i-1)/2 + j-1] = ele;
            }
        }
        int getEle(int i, int j) {
            if (i >= j) {
                return A[i*(i-1)/2 + j-1];
            }
            return 0;
        }
        void display(){
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    cout << getEle(i, j) << " ";
                }
                cout << endl;
            }
        }
        ~LowerT(){
            delete []A;
        }
};
int main() {
    //struct implementation
    struct Matrix m;
    int n;
    cout << "Enter dimension: ";
    cin >> n;
    m.n = n;
    m.A = new int[m.n * (m.n + 1) / 2];
    cout<<"enter all the elements:"<<endl;
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            int ele;
            cin>>ele;
            setEle(&m,i,j,ele);
        }
    }
    cout<<"\n";
    display(m);
    delete[] m.A;

    //class implementation
    LowerT lt(n);
    cout<<"enter all elements: "<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int ele;
            cin>>ele;
            lt.setEle(i,j,ele);
        }
    }
    cout<<"\n";
    lt.display();
    
    return 0;
}
