/* unit_08850C9C: 0x08850C9C-0x08850D04 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

s32 func_08850C9C(char *arg0, s32 arg1) {
    char *temp_v1;

    temp_v1 = arg0 + 0x4A0;
    if (*(u16 *)(arg0 + 0x44C0) == arg1) {
        return 1;
    }
    if (*(u16 *)(temp_v1 + 0x4022) == arg1) {
        return 1;
    }
    if (*(u16 *)(temp_v1 + 0x4024) == arg1) {
        return 1;
    }
    if (*(u16 *)(temp_v1 + 0x4026) == arg1) {
        return 1;
    }
    if (*(u16 *)(temp_v1 + 0x4028) == arg1) {
        return 1;
    }
    return *(u16 *)(temp_v1 + 0x402A) == arg1;
}
