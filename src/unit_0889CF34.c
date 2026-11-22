/* unit_0889CF34: 0x0889CF34-0x0889D008 (ULES01213)
 *
 * Stores a byte at 0x12D5, then looks for the 200-byte record (at 0x57C)
 * whose 6-byte key equals the one returned by func_0889C518 and copies the
 * byte into it at 0xBF.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern u8 *func_0889C518(u8 *);

void func_0889CF34(u8 *arg0, u8 arg1) {
    u8 *key;
    u8 *rec;
    u8 *p;
    s32 i;
    s32 j;
    s32 r;
    u8 a;
    u8 b;

    arg0[0x12D5] = arg1;
    key = func_0889C518(arg0);
    for (i = 0; i < *(s8 *) (arg0 + 0xEE3); i++) {
        p = arg0 + i * 200 + 0x57C;
        for (j = 0; j < 6; j++) {
            a = p[j];
            b = key[j];
            if (b < a) {
                r = -1;
                goto done;
            }
            if (a < b) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            rec = arg0 + i * 200 + 0x57C;
            goto found;
        }
    }
    rec = 0;
found:
    if (rec != 0) {
        rec[0xBF] = arg0[0x12D5];
    }
}
