#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int display_main_menu() {
    int x;
    printf("\n1. Basic Calculator\n");
    printf("2. Scientific Calculator\n");
    printf("3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &x);
    return x;
}
void basic_calculator() {
    int choice;
    double numbers[2]; 
    double *num_ptr = numbers;
    double result;
    
    printf("\n");
    printf("BASIC CALCULATOR\n");
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("\nEnter operation number: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 5) {
        printf("\nError: Invalid operation choice!\n");
        return;
    }
    
    printf("Enter first number: ");
    scanf("%lf", num_ptr);
    printf("Enter second number: ");
    scanf("%lf", num_ptr+1);
    
    switch(choice) {
        case 1: 
            result = *num_ptr + *(num_ptr + 1);
            printf("\nResult: %.2f + %.2f = %.2f\n", *num_ptr, *(num_ptr+1), result);
            break;
            
        case 2:
            result = *num_ptr - *(num_ptr + 1);
            printf("\nResult: %.2f - %.2f = %.2f\n", *num_ptr, *(num_ptr+1), result);
            break;
            
        case 3:
            result = *num_ptr * *(num_ptr + 1);
            printf("\nResult: %.2f * %.2f = %.2f\n", *num_ptr, *(num_ptr+1), result);
            break;
            
        case 4:
            if (*(num_ptr+1)==0) {
                printf("\nError: Division by zero!\n");
                return;
            }
            result = *num_ptr / *(num_ptr + 1);
            printf("\nResult: %.2f / %.2f = %.4f\n", *num_ptr, *(num_ptr+1),result);
            break;
            
        case 5:
            if (*(num_ptr + 1)==0) {
                printf("\nError: Modulus by zero!\n");
                return;
            }
            result = fmod(*num_ptr, *(num_ptr + 1));
            printf("\nResult: %.2f %% %.2f = %.2f\n", *num_ptr, *(num_ptr+1), result);
            break;
    }
}

void scientific_calculator() {
    int choice;
    double numbers[3];
    double *num_ptr = numbers;
    double results[3];
    double *res_ptr = results;
    
    printf("\n");
    printf("SCIENTIFIC CALCULATOR");
    printf("\n");
    printf("1.Sine (sin)\n");
    printf("2.Cosine (cos)\n");
    printf("3.Tangent (tan)\n");
    printf("4.Logarithm (base e)\n");
    printf("5.Logarithm (base 10)\n");
    printf("6.Square Root\n");
    printf("7.Power\n");
    printf("8.Exponential (e^x)\n");
    printf("\nEnter operation number: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 8) {
        printf("\nError: Invalid operation choice!\n");
        return;
    }
    switch(choice) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 8:
            printf("Enter the number: ");
            scanf("%lf", num_ptr);
            break;
            
        case 7:
            printf("Enter base: ");
            scanf("%lf", num_ptr);
            printf("Enter exponent: ");
            scanf("%lf", num_ptr + 1);
            break;
    }
    switch(choice) {
        case 1:
            *res_ptr = sin(*num_ptr);
            printf("\nResult: sin(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 2:
            *res_ptr = cos(*num_ptr);
            printf("\nResult: cos(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 3:
            *res_ptr = tan(*num_ptr);
            printf("\nResult: tan(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 4:
            if (*num_ptr <= 0) {
                printf("\nError: Logarithm undefined for non-positive numbers!\n");
                return;
            }
            *res_ptr = log(*num_ptr);
            printf("\nResult: ln(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 5:
            if (*num_ptr <= 0) {
                printf("\nError: Logarithm undefined for non-positive numbers!\n");
                return;
            }
            *res_ptr = log10(*num_ptr);
            printf("\nResult: log10(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 6:
            if (*num_ptr < 0) {
                printf("\nError: Cannot calculate square root of negative number!\n");
                return;
            }
            *res_ptr = sqrt(*num_ptr);
            printf("\nResult: sqrt(%.2f) = %.4f\n", *num_ptr, *res_ptr);
            break;
            
        case 7:
            *res_ptr = pow(*num_ptr, *(num_ptr + 1));
            printf("\nResult: %.2f ^ %.2f = %.4f\n", *num_ptr, *(num_ptr + 1), *res_ptr);
            break;
            
        case 8:
            *res_ptr = exp(*num_ptr);
            printf("\nResult: e^%.2f = %.4f\n", *num_ptr, *res_ptr);
            break;
    }
}

int main() {
    int choice;
    
    printf("      CALCULATOR\n");
    
    while(1) {
        choice = display_main_menu();
        
        switch(choice) {
            case 1:
                basic_calculator();
                break;
            case 2:
                scientific_calculator();
                break;
            case 3:
                exit(0);
            default:
                printf("\nError: Invalid choice! Please enter 1, 2, or 3.\n");
        }
        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }
    
    return 0;
}
