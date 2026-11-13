/* unit_08812610: 0x08812610-0x0881263C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef struct { char b[24]; } E24;

s32 func_08812610(char *arg0, s32 arg1) {
    s32 temp_v1_i;

    temp_v1_i = (arg1 & 0xFF);
    if (*(u8 *) &((E24 *) (arg0 + 1))[temp_v1_i] != 0) {
        return *(s32 *) &((E24 *) (arg0 + 8))[temp_v1_i];
    }
    return -1;
}
