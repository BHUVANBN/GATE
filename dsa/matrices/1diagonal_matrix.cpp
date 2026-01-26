//Matrix - it is a 2D array 
/*Diagonal Matrix - a square matrix where all elements except the main diagonal are zero    
     
      1 2 3 4 5
  1  [1 0 0 0 0]
  2  [0 2 0 0 0]
  3  [0 0 3 0 0]
  4  [0 0 0 4 0]
  5  [0 0 0 0 5]
     condition M[i,j]=0 for all i!=j

*/
//to store diagonal matrix, we only need to store the diagonal elements instead of wasting space on non-diagonal elements
//so stored in 1D array
// M[1,1] = 1 , store it in A[0]  i.e A[i-1] or A[j-1]
// M[2,2] = 2 , store it in A[1]  i.e A[i-1] or A[j-1] and so on...
#include<iostream>
using namespace std;

struct Matrix{
    int Arr[10];
    int n;
};
void setEle(struct Matrix *m,int i, int j, int ele){
    if(i == j){
        m->Arr[i-1] = ele;
    }
}
int getEle(struct Matrix m,int i, int j){
    if(i == j){
        return m.Arr[i-1];
    }
    return 0;
}
void display(struct Matrix m){
    for(int i=0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            if(i == j){
                cout<<m.Arr[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
//class implementation
class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(int n){
            this->n=n;
            A=new int[n];
            for(int i=0;i<n;i++){
                A[i]=0;
            }
        }
        void set(int i, int j, int ele){
            if(i == j){
                A[i-1] = ele;
            }
        }
        int get(int i, int j){
            if(i == j){
                return A[i-1];
            }
            return 0;
        }
        void disp(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i == j){
                        cout<<A[i]<<" ";
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }
        ~Diagonal(){
            delete []A;
        }
};
int main(){
    cout<<"\nStruct implementation\n";
    struct Matrix m;
    m.n=4;
    setEle(&m,1,1,1);
    setEle(&m,2,2,2);
    setEle(&m,3,3,3);
    setEle(&m,4,4,4);
    display(m);
    cout<<getEle(m,2,1)<<endl;
    
    //class implementation
    cout<<"\nClass implementation\n";
    Diagonal mat(4);
    mat.set(1,1,10);
    mat.set(2,2,20);
    mat.set(3,3,30);
    mat.set(4,4,40);
    mat.disp();
    cout<<mat.get(2,2)<<endl;
    return 0;
}
