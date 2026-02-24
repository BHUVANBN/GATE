//Hash Function types
//size of hash table should be prime and greater than number of elements
//1. mod method - x % size of hash table
//2. Mid-square method - (x^2) and take middle digit, eg: 11^2 = 121, take middle digit 2
//3. Folding method - for large numbers, fold them into smaller numbers, eg: 123456789 can be folded as 12+34+56+78+9 = 210

//for strings - we can use ascii values of characters and apply folding method
//then we can use mod, mid-square method, or take last number of digits

//we can design our own hash function