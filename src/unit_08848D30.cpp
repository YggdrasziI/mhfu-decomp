/* unit_08848D30: 0x08848D30-0x08848E04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A0;

void func_08848D30(char *arg0) {
    s32 temp_t0;
    s32 temp_t1;
    char *temp_a3;

    *(s8 *)(arg0 + 0x52D) = 1;
    *(s8 *)(arg0 + 0x57C) = 0;
    *(s8 *)(D_089CC438 + 0x10) = 1;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) | 4);
    temp_t1 = *(s32 *)(arg0 + 0x528) & ~0x800;
    temp_t0 = temp_t1 & ~0x200;
    *(s32 *)(arg0 + 0x528) = temp_t1;
    *(s32 *)(arg0 + 0x528) = temp_t0;
    *(s32 *)(arg0 + 0x528) = (s32) (temp_t0 & ~0x100);
    *(s8 *)(arg0 + 0x5FE) = 0;
    *(s16 *)(arg0 + 0x5FC) = (s16) *(u8 *)(arg0 + 0x57D);
    *(s8 *)(arg0 + 0x5FF) = -1;
    if (((bool) (*(s32 *)((char *)D_08A631A0 + 0xF7A57C) & 1) == 1) && (*(u8 *)(arg0 + 0x57D) == 0xA)) {
        *(s16 *)(arg0 + 0x5FC) = 0xB;
    }
    *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) & ~4);
    temp_a3 = *(char **)(arg0 + 0x530);
    *(s32 *)(temp_a3 + 0x614) = (s32) (*(s32 *)(temp_a3 + 0x614) & ~1);
    *(s32 *)(arg0 + 0x1194) = (s32) (*(s32 *)(arg0 + 0x1194) & ~0x33);
}

}
