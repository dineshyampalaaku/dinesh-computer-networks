
 #include <stdio.h>
 #define FLAG 0X7E
 #define ESCAPE 0X7D

int main() {
    unsigned char frame[20] = {FLAG, 0xA2, 0x7D, 0x5E, FLAG};  
    unsigned char stuffed_frame[30];  
    int i, j;

    
    j = 0;
    for (i = 0; i < 5; i++) {
        if (frame[i] == FLAG || frame[i] == ESCAPE) {
            stuffed_frame[j++] = ESCAPE;
            stuffed_frame[j++] = frame[i] ^ 0x20;
        } else {
            stuffed_frame[j++] = frame[i];
        }
    }

    
    stuffed_frame[j++] = FLAG;

     
    printf("Original frame: ");
    for (i = 0; i < 5; i++) {
        printf("%02X ", frame[i]);
    }
    printf("\n");

    printf("Stuffed frame: ");
    for (i = 0; i < j; i++) {
        printf("%02X ", stuffed_frame[i]);
    }
    printf("\n");

    return 0;
} 
