/* unit_0888A1FC: 0x0888A1FC-0x0888A330 (ULES01213) */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CBBE4;
extern s32 D_08938234[];

extern s32 func_0888AFEC(char *);
extern s32 func_0888C9F8(char *);

void func_0888A1FC(char *arg0) {
    char *s1 = arg0 + 0xA0;
    char *s0 = D_089CBBE4;
    s32 ret;

    arg0[0x91] = 0;
    switch (*(u8 *)(arg0 + 0x98)) {
    case 0:
        if (*(u8 *)(s0 + 0xA80) != 0) {
            s1[0x4E] = *(u8 *)(s0 + 0xA80);
            *(s32 *)(s1 + 0x50) = *(s32 *)(s0 + 0xA7C);
            s1[0x9B] = 0;
            *(s32 *)(arg0 + 0x9C) = 0;
            if (D_08938234[*(u8 *)(s1 + 0x4E)] == -1) {
                arg0[0x98] = 2;
                ret = func_0888C9F8(arg0);
            } else {
                arg0[0x98] = 1;
                ret = func_0888AFEC(arg0);
            }
            arg0[0x91] = 1;
            s0[0xA80] = 0;
        }
        break;
    case 1:
        ret = func_0888AFEC(arg0);
        break;
    case 2:
        ret = func_0888C9F8(arg0);
        break;
    }
    if (*(u8 *)(arg0 + 0x98) != 0) {
        if (ret <= 0) {
            arg0[0x91] = 1;
            if (ret == 0) {
                s1[0x4F] = 1;
            } else {
                s1[0x4F] = -1;
            }
        } else {
            arg0[0x98] = 0;
            s1[0x4E] = 0;
            s1[0x4F] = 0;
            *(s32 *)(s1 + 0x50) = 0;
            s0[0xAAA] = 1;
            s1[0x9A] = 0;
        }
    }
}
