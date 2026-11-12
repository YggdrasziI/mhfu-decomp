/* unit_088A4BF0: 0x088A4BF0-0x088A4CB0 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern char D_089B2634;
extern char D_089B263C;
extern char D_089B2644;
extern char D_09A0EB10;
extern int func_0880D9EC(char *);

s32 func_088A4BF0(u32 arg0, s32 arg1) {
    if (arg0 >= 0x10U) {
        func_0880D9EC(&D_089B2634);
        func_0880D9EC(&D_089B263C);
        func_0880D9EC(&D_089B2644);
        return 0x80000001;
    }
    ((s32 *)&D_09A0EB10)[arg0] = arg1;
    return 0;
}

s32 func_088A4C54(u32 arg0) {
    if (arg0 >= 0x10U) {
        func_0880D9EC(&D_089B2634);
        func_0880D9EC(&D_089B263C);
        func_0880D9EC(&D_089B2644);
        return 0;
    }
    return ((s32 *)&D_09A0EB10)[arg0];
}
