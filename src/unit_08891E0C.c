/* unit_08891E0C: 0x08891E0C-0x08891F1C (ULES01213) */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern s32 D_089CBBE8;
extern void memset(void *, s32, s32);
extern u16 func_0881629C(s32, u8 **);
extern u16 func_088165FC(s32, u16);
extern s32 func_08893198(char *, u16);
extern void func_08893390(char *);

void func_08891E0C(char *arg0, u8 *arg1, s32 arg2) {
    u16 c;

    memset(arg0 + 0x22608, 0, 0x360);
    while (*arg1 != 0) {
        c = func_0881629C(D_089CBBE8, &arg1);
        c = func_088165FC(D_089CBBE8, c);
        if (c == 0) {
            break;
        }
        if (c == 0xA || c == 0x20 || c == 0xA0 || c == 0x2002 || c == 0x2003 || c == 0x3000) {
            continue;
        }
        if (*(u16 *)(arg0 + 0x162) < *(u16 *)(arg0 + 0x11E) - 1 && func_08893198(arg0, c)) {
            *(u16 *)(arg0 + 0x162) += 1;
        }
    }
    func_08893390(arg0);
}
