/*There are 3 notations of writing an expression-
Infix - operator operand operator
        eg: a+b   //a added to b
Prefix - operand operand operator
        eg: +ab   //add a and b
Postfix - operand operator operand
        eg: ab+   //a and b are added

Bodmas rule - it gives the precedence of the operators
Bracket open division multiplication addition subtraction
eg: 8+3*(9-6)/2^2 +6/2 can we converted to postfix so that it can be evaluated easily according to bodmas
        8396-2^2/*+62/+ is the postfix expression
*/
//infix to prefix or postfix
//step 1: parenthesise the expression based on precedence 
//precedence and associativity
//        __________________________________________________
//        |symbols        |precedence      |associativity   |
//        |()             |highest         |left to right   |
//        |^              |2               |right to left   |
//        |*/             |1               |left to right   |
//        |+-             |0               |left to right   |

//step 2: arrange the expression inside the brackets as prefix or postfix accordingly

/*
eg: a+b*c to prefix 
    brackets according to precedence - (a+(b*c))
    prefix - +a*bc
    postfix - abc*+

eg: a+b+c*d
    a+b+(*cd)
    (+ab)+(*cd)  //if same operator, the one on the left is done first according to associativity
    ++ab*cd  //prefix  
*/