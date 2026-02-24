//Hashing is used to search an element in O(1) time
//searching methods - 
//      linear search - O(n), 
//      binary search - O(log n) - requires sorted array

//hashing - key is sored in the index position itself, but more space is required
//to save the space we use mapping technique of keys on hash table using hash function
// one to one mapping - each key is mapped to one index, ideal hash function - each key is mapped to unique index
// one to many mapping - each key is mapped to multiple indices
// collision - when two keys are mapped to same index - many to one mapping, hash(key) = key % size of hash table

/* collision handling techniques - 
    open hashing - more space is required
        chaining - each index contains linked list of keys
    closed hashing - space is fixed, open addressing- store keys in hash table in empty index (not given by hash function)
        linear probing 
        quadratic probing
        double hashing

