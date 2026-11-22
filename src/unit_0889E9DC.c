/* unit_0889E9DC: 0x0889E9DC-0x0889EA4C (ULES01213) */

typedef int s32;

extern s32 D_089B1F8C;
extern void func_0889EE40(s32);

void func_0889E9DC(s32 arg0) {
    switch (arg0) {
    case 0:
        D_089B1F8C = 0;
        func_0889EE40(1);
        break;
    case 1:
        D_089B1F8C = 1;
        func_0889EE40(0);
        break;
    case 2:
        D_089B1F8C = 2;
        func_0889EE40(0);
        break;
    }
}
