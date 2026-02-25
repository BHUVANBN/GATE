/*Comparision of Time and Space Functions
- highest degree term of the Time function is called leading term
- this is used to get an idea of the time complexity of the function comparison
- eg:
    T(n) = 4                O(1)
    T(n) = 2n+1             O(n)
    T(n) = 2n^2+2n+1        O(n^2)

    1 < logn < √n < n < nlogn < n^2 < n^3 < .... < 2^n < 3^n < .... < n! < n^n
    |     |         |            |     |     
constant log      linear   quadratic cubic
     |____________________________________|     |_____________________________|
                   polynomial                             exponential    

Asymptotic Notations is the Mathematically rigorous way of comparing the time and space functions
- Big O Notation is the upper bound of the function - maximum value of the function
- Big Ω Notation is the lower bound of the function - minimum value of the function
- Big Θ Notation is the tight bound of the function - exact value of the function

Eg: T(n) = 2n^2+2n+1
    O(n^2) is the upper bound of the function
    Ω(n) is the lower bound of the function
    Θ(n^2) is the tight bound of the function