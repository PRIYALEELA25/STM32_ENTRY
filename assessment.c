BIT WISE OPERATION


#include <stdio.h>
 
unsigned char newRegister(unsigned char reg) {
    reg |= (1 << 2);   
    reg &= ~(1 << 5);  
    reg ^= (1 << 0);   
    return reg;       
}
 
int main() {
    unsigned char reg = 0b00101001; 
    unsigned char result = newRegister(reg);
    printf("New register = 0x%X\n", result);
    return 0;
}


PATTERN

#include <stdio.h>

int main() {
    int row = 5;

    for (int i = 0; i < row; i++) {
        for (int j = i; j < row; j++)
            printf(" ");
        for (int k = 0; k <= i; k++)
            printf("*");
        printf("\n");
    }

    return 0;
}
