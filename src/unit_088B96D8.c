/* unit_088B96D8: 0x088B96D8-0x088B97A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088B8A58 (still in assembly) and
 * code already in units. The cases of the switch compare in reverse source order.
 */

typedef unsigned char u8;
typedef int s32;

void func_088B96D8(char *arg0, s32 arg1, s32 arg2) {
    if (*(u8 *)(arg0 + 0x2930C) == 0) {
        *(s32 *)(arg0 + 0x29310) = 0;
        *(u8 *)(arg0 + 0x2930C) = 1;
    }
    switch (arg1) {
    case 0:
        break;
    case 1:
        *(s32 *)(arg0 + 0x29308) |= 1;
        break;
    case 2:
        *(s32 *)(arg0 + 0x29314) = arg2;
        *(s32 *)(arg0 + 0x29308) |= 2;
        break;
    case 3:
        *(s32 *)(arg0 + 0x29308) |= 4;
        break;
    }
}
