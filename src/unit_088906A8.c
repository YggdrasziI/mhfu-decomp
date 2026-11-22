/* unit_088906A8: 0x088906A8-0x088906DC (ULES01213) */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC434;

void func_088906A8(char *arg0) {
    *(s32 *) (arg0 + 0xF7A57C) |= 1;
    *(u8 *) (D_089CC434 + 0x2FBDC) = 0;
}
