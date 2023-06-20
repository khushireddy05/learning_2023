/*Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.*/

    #include <stdio.h>

// Define the structure for a box
struct Box {
    float length;
    float width;
    float height;
};

// Function to calculate the volume of the box
float calculateVolume(struct Box* box) {
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of the box
float calculateSurfaceArea(struct Box* box) {
    return 2 * (box->length * box->width + box->width * box->height + box->height * box->length);
}

int main() {
    // Declare a box structure variable
    struct Box myBox;

    // Initialize the box dimensions
    myBox.length = 2.5;
    myBox.width = 3.0;
    myBox.height = 4.0;

    // Calculate the volume and surface area
    float volume = calculateVolume(&myBox);
    float surfaceArea = calculateSurfaceArea(&myBox);

    // Print the results
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    return 0;
}
