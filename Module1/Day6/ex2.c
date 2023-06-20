/*Write a C program that uses functions to perform the following operations: 
     i) Reading a complex number 
     ii) Writing a complex number 
     iii) Addition of two complex numbers 
     iv) Multiplication of two complex numbers 
  (Note: represent complex number using a structure.*/

  #include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

// Function to read a complex number
void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%f", &(c->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(c->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex* c) {
    if (c->imaginary >= 0)
        printf("Complex number: %.2f + %.2fi\n", c->real, c->imaginary);
    else
        printf("Complex number: %.2f - %.2fi\n", c->real, -c->imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex* c1, struct Complex* c2) {
    struct Complex result;
    result.real = c1->real + c2->real;
    result.imaginary = c1->imaginary + c2->imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex* c1, struct Complex* c2) {
    struct Complex result;
    result.real = c1->real * c2->real - c1->imaginary * c2->imaginary;
    result.imaginary = c1->real * c2->imaginary + c1->imaginary * c2->real;
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    // Addition
    sum = addComplex(&complex1, &complex2);
    printf("Addition of two complex numbers:\n");
    writeComplex(&sum);

    // Multiplication
    product = multiplyComplex(&complex1, &complex2);
    printf("Multiplication of two complex numbers:\n");
    writeComplex(&product);

    return 0;
}
