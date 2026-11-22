/* unit_0888A330: 0x0888A330-0x0888A388 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CBBE4;

extern s32 func_0888A49C(s32, char *, char *, s32);
extern s32 func_0888A538(s32, char *, char *, s32);

s32 func_0888A330(s32 arg0, s32 arg1, u8 arg2) {
    char *p = D_089CBBE4;
    char *v = *(char **)(p + 0xA90);

    if (v == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return func_0888A49C(arg0, p + 0xA98, v + 0x20, arg1);
    }
    return func_0888A538(arg0, p + 0xA98, v + 0x20, arg1);
}
