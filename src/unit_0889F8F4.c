/* unit_0889F8F4: 0x0889F8F4-0x0889F9A0 (ULES01213) */

typedef int s32;

extern char D_089B2110[];
extern char D_089B2118[];
extern char D_089B2148[];

extern int func_0880D9EC(char *, ...);
extern s32 func_088A1554(s32 *);
extern void func_088A16A4(s32 *, void *);

s32 func_0889F8F4(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 ret = 0;

    switch (*arg1) {
    case 0x20000001:
        ret = func_088A1554(arg2);
        break;
    case 0x20000002:
        func_088A16A4(arg2, arg1 + 2);
        break;
    default:
        func_0880D9EC(D_089B2110);
        func_0880D9EC(D_089B2118);
        func_0880D9EC(D_089B2148, *arg1);
        break;
    }
    *arg2 = ret;
    return ret;
}
