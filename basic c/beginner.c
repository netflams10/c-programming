#include <stdio.h>
#include <stdbool.h> // import to use boolean

int add_number(int first_number, int second_number);
int sum(int number);

void greet ()
{
    printf("Good Morning\n");
}

void calculate_square (int number)
{
    printf("Square of %d is %d", number, number * number);
}

void find_value (int* number)
{
    *number = 39;
}

int main () 
{

    // int number;
    int number = 15;
    printf("%d -> %p", number, &number);
    find_value(&number);

    printf("\n%d -> %p", number, &number);

    // greet();
    // calculate_square(10);

    // printf("Please Enter Number to Square:");
    // scanf("%d", &number);

    // calculate_square(number);

   // using the boolean
//    bool is_true = false;
//    printf("%d", is_true);

//    add_number(10, 10);



    return 0;
}

int add_number (int first_value, int second_value)
{
    return first_value + second_value;
}

int sum (int number) 
{
    // on each recursive call we decrease the value of n (sum(number - 1))
    if (number != 0) return number + sum(number - 1);
    return number;
}