/* unit_088DA940: 0x088DA940-0x088DA974 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

void func_088DA940(char *arg0, char *arg1) {
    *(f32 *)(arg0 + 0x200) = *(f32 *)arg1;
    *(f32 *)(arg0 + 0x204) = *(f32 *)(arg1 + 4);
    *(f32 *)(arg0 + 0x208) = *(f32 *)(arg1 + 8);
    *(s32 *)(arg0 + 0x1F0) = 0;
    *(s32 *)(arg0 + 0x1F4) = (s32) *(u16 *)(arg1 + 0xC);
    *(s32 *)(arg0 + 0x1F8) = 0;
    *(u16 *)(arg0 + 0x320) = (u16) *(u16 *)(arg1 + 0xC);
}
