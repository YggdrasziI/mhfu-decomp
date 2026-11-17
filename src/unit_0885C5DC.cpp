/* unit_0885C5DC: 0x0885C5DC-0x0885C6F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function before code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef unsigned short u16;

extern "C" {

typedef struct {
    u16 key;
    s16 val;
} Rec;

void func_0885C5DC(Rec *a, u32 n) {
    s32 h = 1;
    u32 i;
    s32 j;
    Rec t;

    if (n > 1) {
        do {
            h = h * 3 + 1;
        } while (h < n);
    }
    for (h /= 3; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i - h; j >= 0; j -= h) {
                if (!(a[j].key > t.key)) {
                    if (t.key != a[j].key) {
                        break;
                    }
                    if (!(a[j].val < t.val)) {
                        break;
                    }
                }
                a[j + h] = a[j];
            }
            a[j + h] = t;
        }
    }
}

}
