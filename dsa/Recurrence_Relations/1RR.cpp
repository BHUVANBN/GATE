/*Recurrence Relation is a mathematical way of finding time complexity of a recursive function

Recurrence Relation for Decreasing Problem Size 
eg: 
Algorithm fun(int n){      ---T(n)
    if(n>0){
        print(n)           ---1
        fun(n-1);          ---T(n-1)
    }
}

T(n) - time required to solve a problem of size n

T(n) = 1 + T(n-1) ,if n>0
T(n) = 1 ,if n=0 //base case

solving recurrence relation using successive substitution
T(n) = 1 + T(n-1)
T(n) = 1 + (1 + T(n-2))                       | T(n-1) = 1 + T(n-2)
T(n) = 2 + T(n-2)
T(n) = 3 + T(n-3)                             | T(n-2) = 1 + T(n-3)

for k times
T(n) = k + T(n-k)  //recurrence relation

    assume T(n-k) reached 0
        T(0) = T(n-k)
        n-k = 0
        n = k

now substitute k with n and T(n-k) with 1 from base case
T(n) = k + T(n-k)
T(n) = n + 1

so Time Complexity is O(n)
__________________________________________________________________________________________________
General Form for decreasing problem size
T(n) = aT(n-b) + f(n)
    where a is the number of recursive calls
    b is the factor by which the size of the problem is reduced in each recursive call
    f(n) is the cost of the work done outside the recursive calls i.e other than recursive calls

other Recurrence Relation
T(n) = T(n-1) + 1        O(n)
T(n) = T(n-1) + n        O(n^2)
T(n) = T(n-1) + n^2      O(n^3)
T(n) = T(n-1) + logn     O(nlogn)
T(n) = T(n-2) + 1        O(n)
it only depends on the two terms in the recurrence relation

T(n) = 2T(n-1) + 1        O(2^n)
T(n) = 3T(n-1) + 1        O(3^n)
T(n) = 3T(n-1) + n        O(n3^n)
T(n) = 3T(n-2) + n        O(n3^(n/2))
__________________________________________________________________________________________________
Master Theorem for Decreasing Problem Size

General Form: T(n) = aT(n-b) + f(n)
case 1: if a = 1
        O(n*f(n))
case 2: if a > 1
        O(a^(n/b)*f(n))
case 3: if a < 1   //practically not possible i.e number of recursive calls cannot be less than 0
        O(f(n))    //but mathematically possible
__________________________________________________________________________________________________
Recurrence Relation for Dividing Problem Size
eg: 
Algorithm fun(int n){      ---T(n)
    if(n>1){ //if its given as n>0 also assume n=1 is base case to find the recurrence relation
        print(n)           ---1
        fun(n/2);          ---T(n/2)
    }
}

T(n) = 1 + T(n/2) ,if n>0
T(n) = 1 ,if n=1 //base case

solving recurrence relation using successive substitution
T(n) = 1 + T(n/2) 
T(n) = 1 + (1 + T(n/2^2))                       | T(n/2) = 1 + T(n/2^2)
T(n) = 2 + T(n/2^2)
T(n) = 3 + T(n/2^3)                             | T(n/2^2) = 1 + T(n/2^3)

for k times
T(n) = k + T(n/2^k)  //Recurrence Relation

    assume T(n/2^k) reached 1 
        T(n/2^k) = 1
        n/2^k = 1
        n = 2^k
        k = log_2(n)

now substitute k with n and T(n/2^k) with 1 from base case 
T(n) = k + T(n/2^k)
T(n) = log_2(n) + 1

so Time Complexity is O(logn)
__________________________________________________________________________________________________
General form: T(n) = aT(n/b) + f(n)
    where a is the number of recursive calls
    b is the factor by which the size of the problem is reduced in each recursive call
    f(n) is the cost of the work done outside the recursive calls i.e other than recursive calls

other Recurrence Relation
T(n) = T(n/2) + 1        O(logn) 
T(n) = T(n/2) + n        O(n)
T(n) = 2T(n/2) + 1       O(n)
T(n) = 2T(n/2) + n       O(nlogn)
T(n) = 2T(n/2) + n^2     O(n^2)
T(n) = 4T(n/2) + n^2logn O(n^2(log^2)n)
__________________________________________________________________________________________________
Master Theorem for Dividing Problem Size

General Form: T(n) = aT(n/b) + f(n), here we represent f(n) as n^k * log^p(n)
find log_b(a) and k
case 1: if log_b(a) > k, then T(n) = O(n^(log_b(a)))
case 2: if log_b(a) = k, then T(n) = O(f(n)*logn)
case 3: if log_b(a) < k, then T(n) = O(f(n))
__________________________________________________________________________________________________
Recurrence Relation for decreasing root(√) Problem Size
eg: 
Algorithm fun(int n){      ---T(n)
    if(n>2){ //if its given as n>0 also assume n=2 is base case to find the recurrence relation
        print(n)           ---1
        fun(√n);          ---T(√n)
    }
}

T(n) = 1 + T(√n) ,if n>2
T(n) = 1 ,if n=2 //base case

solving recurrence relation using successive substitution
T(n) = 1 + T(n^(1/2)) 
T(n) = 1 + (1 + T(n^(1/2^2)))                       | T(n^(1/2)) = 1 + T(n^(1/2^2))
T(n) = 2 + T(n^(1/2^2))
T(n) = 3 + T(n^(1/2^3))                             | T(n^(1/2^2)) = 1 + T(n^(1/2^3))

for k times
T(n) = k + T(n^(1/2^k))  //Recurrence Relation

    assume n is in 2^m , then m = log_2(n)
    T(n)=T(2^(m/2^k)) + k
    assume T(2^(m/2^k)) reached 1
        T(2^(m/2^k)) = T(2)
        m/2^k = 1
        m = 2^k
        k = log_2(m)

now substitute k with n and T(n/2^k) with 1 from base case 
T(n) = T(2^(m/2^k)) + k
T(n) = T(2) + k                  | m/2^k = 1
T(n) = 1 + log_2(m)              | T(2) - 1 and k = log_2(m) 
T(n) = 1 + log_2(log_2(m))

so Time Complexity is O(log(logn))
__________________________________________________________________________________________________
General form: 
T(n) = 1 + T(√n)          ....concvert this into dividing problem size
assume n = 2^m
T(2^m) = 1 + T(2^(m/2))   ....now take only powers in consideration
S(m) = 1 + S(m/2)         ....now this is in decreasing problem size recurrence relation

this relation comes under case 2 of master theorem 
log_2(1) = 0 and f(n) = n^k = n^0 = 1

so Time Complexity is O(logm) = O(log(logn))
__________________________________________________________________________________________________
