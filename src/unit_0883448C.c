/* unit_0883448C: 0x0883448C-0x088344FC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

void func_0883448C(char *arg0) {
    s32 temp_a2;
    s32 temp_a3;

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
    *(s8 *)(arg0 + 0x5FE) = 4;
    *(s16 *)(arg0 + 0x5FC) = (s16) *(u8 *)(arg0 + 0x111C);
    *(s8 *)(arg0 + 0x5FF) = -1;
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~0x40);
}
