//Linear probing - uses fixed size array
//uses normal hash function but if the index is occupied then it stores the element in the next available index
//if end of array is reached then it stores the element in the first available index
//searching is done by linear search from the matched index so time complexity is not constant
//unsuccessfull search - stop when we find an empty index

//loading factor = n / size of hash table
//loading factor must be <=0.5

//time taken for successfull search = 1/lf*ln(1/(1-lf))
//time taken for unsuccessfull search = 1/(1-lf)

//deletion is done by rehashing - when an element is removed from hashtable ,take out all elements and rehash them 
//so deletion is not a good option

#include<iostream>
using namespace std;

int hashFunction(int value){
    return value % 10;
}
int probe(int hashTable[], int value){
    int index = hashFunction(value);
    int i =0;
    while(hashTable[(index+i)%10]!=0){
        i++;
    }
    return (index+i)%10;
}
void insert(int hashTable[], int value){
    int index = hashFunction(value);
    if (hashTable[index]!=0){
        index = probe(hashTable, value);
    }
    hashTable[index] = value;
}
int search(int hashTable[], int key){
    int index = hashFunction(key);
    int i = 0;
    while(hashTable[(index+i)%10]!=key){
        i++;
    }
    return (index+i)%10;
}
int main(){
    int hashTable[10] = {0};
    insert(hashTable, 18);
    insert(hashTable, 5);
    insert(hashTable, 15);

    for(int i = 0; i < 10; i++){
        cout<<hashTable[i]<<" ";
    }
    cout<<endl;
    cout<<search(hashTable, 15);
    return 0;
}

//quadratic probing
//same as linear probing but instead of storing in next available index we use index + i^2 where i = 0,1,2,3,...
//this prevents clustering - grouping of elements in same index in linear probing