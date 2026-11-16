/* unit_088ADDF4: 0x088ADDF4-0x088ADE7C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions before unit_088ADE7C. Their jump tables
 * (0x089320F4-0x08932124) are linked from this unit.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char unk0[8];
    s32 state;
    u8 unkC;
} T;

s32 func_088ADDF4(T *arg0) {
    switch (arg0->state) {
    case 0:
        return 0;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    default:
        arg0->unkC = 0;
        break;
    }
    return 1;
}

s32 func_088ADE38(T *arg0) {
    switch (arg0->state) {
    case 0:
    case 1:
    case 4:
    case 5:
        return 0;
    case 2:
    case 3:
    default:
        arg0->unkC = 0;
        break;
    }
    return 1;
}
