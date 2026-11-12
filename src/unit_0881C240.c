/* unit_0881C240: 0x0881C240-0x0881C2E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern char D_0899D198;
extern s32 D_08A62D8C;
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0881C240(char *arg0, s32 arg1, u16 arg2) {
    s32 temp_a1;
    s8 temp_v1;

    temp_a1 = arg1 & 0xFFFF;
    if ((*(u16 *)((char *)((&D_0899D198 + (temp_a1 * 0x18))) + 0x16) != 0) && (temp_a1 != 0) && (arg2 & 0x8000)) {
        func_08883988(D_08A62D8C, 0, 9, 0, 0, 0, 0, 0, 0);
        temp_v1 = *(s8 *)(arg0 + 0x5FF) + 1;
        *(s8 *)(arg0 + 0x5FF) = temp_v1;
        *(s8 *)(arg0 + 0x5FF) = (s8) (temp_v1 & 1);
    }
}
