#define KSEG1           0xA0000000
#define DEV_CON_ADDR    0x10000000
#define DEV_CON_PUTC    0x00

void kputc(char c) {
    *((volatile char *) KSEG1 + DEV_CON_ADDR + DEV_CON_PUTC) = c;
}

void kputs(const char *str) {
    while (*str) {
        kputc(*str);
        str++;
    }
}

void main() {
    kputs("Hello world!\n");
    for (;;) ;
}
