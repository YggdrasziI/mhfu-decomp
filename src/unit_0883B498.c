/* unit_0883B498: 0x0883B498-0x0883B53C (ULES01213)
 *
 * Searches the 6-byte keys of the D_09A0B544 table (count at 0xEE3,
 * 200-byte records at 0x57C) for the key of entry a1 of D_09A0FDC4.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s32 func_0880BFF0(void *, void *, s32);
extern char *D_09A0B544;
extern char *D_09A0FDC4;

s32 func_0883B498(s32 a0, s32 idx) {
    s32 i;
    char *key;

    key = D_09A0FDC4 + idx * 8 + 0x50;

    for (i = 0; i < *(s8 *)(D_09A0B544 + 0xEE3); i++) {
        if (func_0880BFF0(key, D_09A0B544 + (u8)i * 200 + 0x57C, 6) == 0) {
            return i;
        }
    }
    return -1;
}
