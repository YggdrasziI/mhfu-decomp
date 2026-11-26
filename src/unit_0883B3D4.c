/* unit_0883B3D4: 0x0883B3D4-0x0883B498 (ULES01213)
 *
 * Finds the n-th entry (stride 0xC8 at +0x57C of D_09A0B544) whose 6-byte key
 * matches the key returned by func_0889C518.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char *D_09A0B544;
extern char *func_0889C518(char *);
extern s32 func_0880BFF0(void *, void *, s32);

char *func_0883B3D4(s32 arg0, s32 n) {
    s32 found;
    s32 i;
    char *e;

    found = 0;
    for (i = 0; i < *(s8 *)(D_09A0B544 + 0xEE3); i++) {
        e = D_09A0B544 + (u8)i * 0xC8 + 0x57C;
        if (func_0880BFF0(func_0889C518(D_09A0B544), e, 6) != 0) {
            if (found == n) {
                return e;
            }
            found++;
        }
    }
    return 0;
}
