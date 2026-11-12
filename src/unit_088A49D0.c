/* unit_088A49D0: 0x088A49D0-0x088A4A30 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

extern char D_089B25DC;
extern char D_089B25E4;
extern char D_089B261C;
extern char D_09A0EA84;
extern int func_0880D9EC(char *);

s32 func_088A49D0(u32 arg0) {
    if (arg0 >= 0x10U) {
        func_0880D9EC(&D_089B25DC);
        func_0880D9EC(&D_089B25E4);
        func_0880D9EC(&D_089B261C);
        return 0x80000001;
    }
    return ((s32 *)&D_09A0EA84)[arg0];
}
