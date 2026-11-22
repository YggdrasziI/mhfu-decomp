/* unit_0889C66C: 0x0889C66C-0x0889C75C (ULES01213)
 *
 * Linear search among n records of the given size for the one whose 6-byte
 * key, found at (key - base) in each record, equals target; the match is
 * swapped with the first record (tmp is the swap buffer).
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

extern void memcpy(void *, void *, s32);

void func_0889C66C(s32 arg0, s32 n, u8 *base, s32 size, u8 *key, u8 *tmp,
                   u8 *target) {
    s32 i;
    s32 k;
    s32 r;
    u8 *a;
    u8 *b;
    u8 *cur;
    s32 off = key - base;

    cur = base;
    for (i = 0; i < n; i++) {
        k = 0;
        a = cur + off;
        b = target;
        do {
            if (*b < *a) {
                r = -1;
                goto done;
            }
            if (*a < *b) {
                r = 1;
                goto done;
            }
            k++;
            a++;
            b++;
        } while (k < 6);
        r = 0;
    done:
        if (r == 0) {
            memcpy(tmp, base, size);
            memcpy(base, cur, size);
            memcpy(cur, tmp, size);
            return;
        }
        cur += size;
    }
}
