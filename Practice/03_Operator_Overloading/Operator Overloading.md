Operator Overloading
==========================================================

Operators That Can Be Overloaded Using Member Functions:
Unary Operators:

    + (Unary Plus)
    - (Unary Minus)
    ++ (Prefix Increment)
    -- (Prefix Decrement)
    * (Dereference)
    & (Address-of)
    Binary Operators:

    + (Addition)
    - (Subtraction)
    * (Multiplication)
    / (Division)
    % (Modulus)
    ^ (Bitwise XOR)
    & (Bitwise AND)
    | (Bitwise OR)
    = (Assignment)
    +=, -=, *=, /=, %=, ^=, &=, |=
    <<, >> (Bitwise Shift)
    <<=, >>= (Bitwise Shift Assignment)
    [] (Subscript Operator)
    () (Function Call Operator)
    -> (Member Access)

Operators That Can Be Overloaded Using Friend Functions:
================================================================================================================================================================
A friend function is needed when the left-hand operand is not an object of the class (e.g., cout << obj, obj1 + obj2 when + is implemented outside the class).

1. Binary Operators:

    + (Addition)
    - (Subtraction)
    * (Multiplication)
    / (Division)
    % (Modulus)
    ^ (Bitwise XOR)
    & (Bitwise AND)
    | (Bitwise OR)
    ==, != (Equality and Inequality)
    <, >, <=, >= (Relational Operators)
    <<, >> (Bitwise Shift & Stream Operators)

2. Stream Operators (Must Be Friend Functions):

    << (Output Stream)
    >> (Input Stream)

Key Differences Between Member and Friend Overloading:
===============================================================

Feature                                     Member Function                     Friend Function
-------------------------------------------------------------------------------------------------------
Syntax                                      ClassName::operator()               operator() outside the class
Can Access Private Members?                 Yes                                 Yes (friend function has access)
Left Operand Requirement                    Must be an object of the class      Can be a non-class object
Used For                                    Unary and binary operators          Mostly binary operators
Stream Operators (<<, >>)                   ❌ (Cannot be member functions)    ✅ (Must be friend functions)