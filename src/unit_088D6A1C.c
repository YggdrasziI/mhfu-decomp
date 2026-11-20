/* unit_088D6A1C: 0x088D6A1C-0x088D6AC8 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D69F0 and unit_088D6AC8.
 *
 * Both look a byte up in a short list: the six bytes at +0x676 of the
 * object, and five bytes of the global record chosen by the id at +0x1E6.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_088D6A1C(char *arg0, u8 arg1) {
    s32 i;

    i = 0;
    do {
        if (*(u8 *)(arg0 + 0x676 + i) == arg1) {
            return 1;
        }
        i++;
    } while (i < 6);
    return 0;
}

s32 func_088D6A54(char *arg0, u8 arg1) {
    u8 *p;
    s32 i;

    if (*(u16 *)(arg0 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) {
        p = (u8 *)(D_089CC438 + 0x69942);
    } else {
        p = (u8 *)(D_089CC438 + *(u16 *)(arg0 + 0x1E6) * 0x8C + 0xA9);
    }
    i = 0;
    do {
        if (*p == arg1) {
            return 1;
        }
        i++;
        p++;
    } while (i < 5);
    return 0;
}
