/* unit_0889E8F8: 0x0889E8F8-0x0889E984 (ULES01213) */

typedef int s32;

extern s32 D_09A0B560;
extern s32 func_0889F9A0(s32, s32, s32, char *);
extern void func_0889F018(void);
extern void func_0889F764(s32, char *, char *);
extern void func_0889F8F4(s32, char *, char *);

void func_0889E8F8(s32 arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, char *arg5, s32 arg6, s32 arg7, s32 arg8) {
    switch (arg1) {
    case 0x309:
        *(s32 *)arg5 = func_0889F9A0(D_09A0B560, arg1, arg2, arg3);
        func_0889F018();
        break;
    case 1:
        func_0889F764(arg1, arg3, arg5);
        break;
    case 0x64:
        func_0889F8F4(arg1, arg3, arg5);
        break;
    case 0x65:
        break;
    }
}
