/* unit_08834304: 0x08834304-0x08834400 (ULES01213) */

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern char *D_08A631A0;

extern s32 func_08834D04(char *);
extern s32 func_088345B8(char *, s32);
extern void func_08834B0C(char *, s32);
extern void func_0882A168(char *);
extern void func_08825D38(char *);
extern void func_088345FC(char *);
extern void func_08834664(char *);
extern void func_088346D8(char *);
extern void func_08823A50(char *);

void func_08834304(char *arg0) {
    s32 r = func_08834D04(arg0) & 0xFFFF;

    switch (*(u8 *)(arg0 + 0x52C)) {
    case 0:
        (*(u8 *)(arg0 + 0x52C))++;
    case 1:
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
            *(u8 *)(arg0 + 0x606) = 0;
            if (*(s32 *)(arg0 + 0x600) <= 0) {
                *(s32 *)(arg0 + 0x600) = 0;
            } else {
                (*(s32 *)(arg0 + 0x600))--;
            }
        }
        if (*(s8 *)(arg0 + 0x5F0) == 0) {
            if (func_088345B8(arg0, r) == 0) {
                func_08834B0C(arg0, r);
            }
            func_0882A168(arg0);
        }
        break;
    }
    func_08825D38(arg0);
    func_088345FC(arg0);
    func_08834664(arg0);
    func_088346D8(arg0);
    func_08823A50(arg0);
}
