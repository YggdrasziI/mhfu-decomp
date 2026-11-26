/* unit_08830550: 0x08830550-0x088306DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08830550: matched. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62C54;
extern s32 func_0885E718(s32 arg0, u8 *arg1);

u16 func_08830550(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    s32 found;
    u16 r;

    if (arg1 == 0) {
        return 0;
    }
    if (*(u16 *)(arg1 + 2) == 0) {
        return 0;
    }
    if (*(u16 *)(arg1 + 2) > 0x5DC) {
        return 1;
    }
    if (arg2 & 0x100) {
        r = 6;
        switch (arg1[1]) {
        case 6:
            r = 8;
            break;
        case 5:
            if (arg3 != 0 && arg3[1] == 6) {
                r = 8;
            }
            break;
        }
        return r;
    }
    found = 0;
    if (func_0885E718(D_08A62C54, arg1) != 0) {
        found = 1;
    } else if (arg3 != 0 && *(u16 *)(arg3 + 2) != 0 && func_0885E718(D_08A62C54, arg3) != 0) {
        found = 1;
    }
    switch (arg1[1]) {
    case 6:
        r = 4;
        break;
    case 5:
        r = 2;
        break;
    default:
        r = 0x8003;
        if ((u16)found) {
            r += 2;
        }
        return r;
    }
    if ((u16)found) {
        r += 3;
        r |= 0x8000;
    }
    return r;
}
