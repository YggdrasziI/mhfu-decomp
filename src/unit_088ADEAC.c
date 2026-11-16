/* unit_088ADEAC: 0x088ADEAC-0x088ADEF0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088ADE7C and unit_088ADEF0, same
 * shape as the two of unit_088ADDF4. Its jump table (0x08932124-0x0893213C) is
 * linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char unk0[8];
    s32 state;
    u8 unkC;
} T;

s32 func_088ADEAC(T *arg0) {
    switch (arg0->state) {
    case 0:
    case 1:
    case 2:
    case 4:
        return 0;
    case 3:
    case 5:
    default:
        arg0->unkC = 0;
        break;
    }
    return 1;
}
