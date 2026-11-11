/* unit_08813C8C: 0x08813C8C-0x08813CC8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08813C8C(char *arg0) {
    u8 temp_v1;

    temp_v1 = *(u8 *)(arg0 + 0x9BE);
    if ((temp_v1 != 5) && (temp_v1 != 4) && (temp_v1 != 3)) {
        return 0;
    }
    return 1;
}
