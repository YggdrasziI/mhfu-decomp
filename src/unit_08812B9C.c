/* unit_08812B9C: 0x08812B9C-0x08812BD0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_08815348(char *, s32, s32);

void func_08812B9C(char *arg0, s32 arg1, s32 arg2) {
    *(s32 *)arg0 = 0x41f00000;
    *(s32 *)(arg0 + 0x4) = 0x477de800;
    *(s32 *)(arg0 + 0xc) = 0x3f5f49f5;
    *(s32 *)(arg0 + 0x8) = 0x3fe1e1e2;
    *(s32 *)(arg0 + 0xb34) = 0;
    func_08815348(arg0, arg1, arg2);
}
