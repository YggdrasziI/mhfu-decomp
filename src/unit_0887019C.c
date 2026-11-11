/* unit_0887019C: 0x0887019C-0x088701D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

s32 func_088568AC(s32, u16);
extern s32 D_089CC438;

s32 func_0887019C(s32 arg0, char *arg1) {
    s16 temp_s0;

    temp_s0 = *(s16 *)(arg1 + 4);
    return func_088568AC(D_089CC438, *(u16 *)(arg1 + 2)) >= temp_s0;
}
