/* unit_08865F68: 0x08865F68-0x08865F8C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 func_0886421C(void *, s16);

s32 func_08865F68(char *arg0, s32 arg1) {
    return func_0886421C(arg0 + 0x80, arg1) + 0xD0;
}
