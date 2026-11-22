/* unit_0889C524: 0x0889C524-0x0889C66C (ULES01213)
 *
 * Bubble sort of n records of the given size, ordered by a 6-byte key found
 * at (key - base) in each record (descending order); tmp is a swap buffer.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

extern void memcpy(void *, void *, s32);

void func_0889C524(s32 arg0, s32 n, u8 *base, s32 size, u8 *key, u8 *tmp) {
    s32 i;
    s32 k;
    s32 r;
    u8 *b;
    u8 *a;
    u8 *cur;
    u8 *next;
    s32 j;
    s32 off = key - base;

    for (i = 0; i < n - 1; i++) {
        cur = base;
        next = base + size;
        for (j = 0; j < n - 1; j++) {
            k = 0;
            b = next + off;
            a = cur + off;
            do {
                if (*a < *b) {
                    r = -1;
                    goto done;
                }
                if (*b < *a) {
                    r = 1;
                    goto done;
                }
                k++;
                b++;
                a++;
            } while (k < 6);
            r = 0;
        done:
            if (r < 0) {
                memcpy(tmp, cur, size);
                memcpy(cur, next, size);
                memcpy(next, tmp, size);
            }
            cur += size;
            next += size;
        }
    }
}
