/* unit_08813F04: 0x08813F04-0x08814048 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

s32 func_08813F04(char *arg0) {
    u8 temp_v0;

    temp_v0 = *(u8 *)(arg0 + 0x9BE);
    if ((temp_v0 != 0x3F) && (temp_v0 != 0x3E) && (temp_v0 != 0x3D) && (temp_v0 != 0x3C) && (temp_v0 != 0x3B) && (temp_v0 != 0x3A) && (temp_v0 != 0x39) && (temp_v0 != 0x38) && (temp_v0 != 0x34) && (temp_v0 != 0x33) && (temp_v0 != 0x31) && (temp_v0 != 0x2E) && (temp_v0 != 0x2D) && (temp_v0 != 0x2C) && (temp_v0 != 0x2A) && (temp_v0 != 0x28) && (temp_v0 != 0x27) && (temp_v0 != 0x24) && (temp_v0 != 0x23) && (temp_v0 != 0x21) && (temp_v0 != 0x1F) && (temp_v0 != 0x1D) && (temp_v0 != 0x1C) && (temp_v0 != 0x1B) && (temp_v0 != 0x1A)) {
        return 0;
    }
    return 1;
}
