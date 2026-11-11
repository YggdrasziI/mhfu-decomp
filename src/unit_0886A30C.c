/* unit_0886A30C: 0x0886A30C-0x0886A35C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CC438;

s32 func_0886A30C(s32 arg0, s32 arg1) {
    u8 temp_v1;

    temp_v1 = *(u8 *)(D_089CC438 + 0x2E);
    if ((u32) (temp_v1 - 3) < 2U) {
        return 1;
    }
    if ((arg1 == 1) && ((u32) (temp_v1 - 5) < 3U)) {
        return -1;
    }
    return 0;
}
