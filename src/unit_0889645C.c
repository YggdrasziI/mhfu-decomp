/* unit_0889645C: 0x0889645C-0x08896484 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 func_088965D8(s32, s32);

void func_0889645C(char *arg0) {
    if (*(u8 *)(arg0 + 0x1117) != 0) {
        func_088965D8((s32) arg0, 0);
    }
}
