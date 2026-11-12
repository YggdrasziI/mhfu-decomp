/* unit_088DACA4: 0x088DACA4-0x088DACF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_08865CB8(void *, s32, s32);
extern s32 func_088DACF8(s32);

s32 func_088DACA4(s32 arg0) {
    if ((func_088DACF8(arg0) & 0xFF) == 1) {
        return 1;
    }
    return (func_08865CB8((char *) arg0, 0, 0x48) & 0xFF) == 1;
}
