/* unit_088490C8: 0x088490C8-0x08849120 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern char *D_089CC438;

void func_088490C8(char *arg0) {
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;

    *(s8 *)(arg0 + 0x52D) = 0;
    *(s8 *)(arg0 + 0x57C) = 0;
    *(s8 *)(D_089CC438 + 0x10) = 0;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    temp_a3 = *(s32 *)(arg0 + 0x528) & ~4;
    temp_a2 = temp_a3 & ~0x800;
    *(s32 *)(arg0 + 0x528) = temp_a3;
    temp_a1 = temp_a2 & ~0x200;
    *(s32 *)(arg0 + 0x528) = temp_a2;
    *(s32 *)(arg0 + 0x528) = temp_a1;
    *(s32 *)(arg0 + 0x528) = (s32) (temp_a1 & ~0x100);
}
