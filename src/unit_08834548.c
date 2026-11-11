/* unit_08834548: 0x08834548-0x088345B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_089CC438;

void func_08834548(char *arg0) {
    s32 temp_a2;
    s32 temp_a3;

    *(s8 *)(arg0 + 0x111D) = 0;
    *(s8 *)(arg0 + 0x111B) = 0;
    *(s8 *)(arg0 + 0x111A) = 0;
    *(s8 *)(arg0 + 0x1119) = 0;
    *(s8 *)(arg0 + 0x1118) = 0;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) | 4);
    temp_a3 = *(s32 *)(arg0 + 0x528) & ~0x800;
    temp_a2 = temp_a3 & ~0x200;
    *(s32 *)(arg0 + 0x528) = temp_a3;
    *(s32 *)(arg0 + 0x528) = temp_a2;
    *(s32 *)(arg0 + 0x528) = (s32) (temp_a2 & ~0x100);
    *(s8 *)(D_089CC438 + 0x10) = 0;
    *(s8 *)(arg0 + 0x112C) = 0;
    *(s8 *)(arg0 + 0x1138) = 0;
    *(s8 *)(arg0 + 0x1144) = 0;
    *(s8 *)(arg0 + 0x1150) = 0;
    *(s8 *)(arg0 + 0x115C) = 0;
    *(s8 *)(arg0 + 0x1168) = 0;
}
