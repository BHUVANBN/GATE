//Double hash function also helps to reduce collison
//first hash function is used to find the index 
//second hash function is used to hash the index
//second hash function should not give 0 as output and should be coprime to the size of hash table

//h1(x) = x%10
//h2(x) = 7-(x%7)
//h(x) = (h1(x)+i*h2(x))%10  where i = 0,1,2,3,...

#include <iostream>
using namespace std;

#define SIZE 10

int hash1(int key){
    return key % SIZE;
}
int hash2(int key){
    return 7 - (key % 7);   // must be non-zero and coprime with SIZE
}
void insert(int hashTable[], int key){
    int index = hash1(key);
    // If empty slot found immediately
    if(hashTable[index] == -1){
        hashTable[index] = key;
        return;
    }
    // Probe using double hashing
    int i = 1;
    while(i < SIZE){
        int newIndex = (hash1(key) + i * hash2(key)) % SIZE;
        if(hashTable[newIndex] == -1){
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }
    cout << "Hash Table is Full\n";
}
int search(int hashTable[], int key){
    int index = hash1(key);
    if(hashTable[index] == key)
        return index;
    int i = 1;
    while(i < SIZE){
        int newIndex = (hash1(key) + i * hash2(key)) % SIZE;
        if(hashTable[newIndex] == key)
            return newIndex;
        if(hashTable[newIndex] == -1)
            return -1;
        i++;
    }
    return -1;
}

int main(){
    int hashTable[SIZE];
    // Initialize with -1 (empty)
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    insert(hashTable, 23);
    insert(hashTable, 43);
    insert(hashTable, 13);
    insert(hashTable, 27);

    int key = 43;
    int result = search(hashTable, key);
    if(result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found\n";
    return 0;
}