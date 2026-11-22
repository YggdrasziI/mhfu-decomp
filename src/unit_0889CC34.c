/* unit_0889CC34: 0x0889CC34-0x0889CD24 (ULES01213)
 *
 * Clears every 0xC8-byte entry (at +0x57C, count at +0xEE3) whose first six
 * bytes equal key; if any was cleared, calls func_0889C75C and decrements the
 * count (kept at least 1).
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern void memset(void *, s32, s32);
extern void func_0889C75C(u8 *);

void func_0889CC34(u8 *arg0, u8 *key) {
    s32 found = 0;
    s32 i;
    u8 *p;
    s32 k;
    s32 r;

    for (i = 0; i < *(s8 *)(arg0 + 0xEE3); i++) {
        p = arg0 + i * 0xC8;
        k = 0;
        do {
            if (key[k] < p[0x57C + k]) {
                r = -1;
                goto done;
            }
            if (p[0x57C + k] < key[k]) {
                r = 1;
                goto done;
            }
            k++;
        } while (k < 6);
        r = 0;
    done:
        if (r == 0) {
            memset(p + 0x57C, 0, 0xC8);
            found = 1;
        }
    }
    if (found) {
        func_0889C75C(arg0);
        if (*(s8 *)(arg0 + 0xEE3) > 1) {
            (*(s8 *)(arg0 + 0xEE3))--;
        }
    }
}
