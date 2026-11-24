/* unit_088522CC: 0x088522CC-0x08852618 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 key;
    u32 color;
} Key;

/* Colour of a key table at t, interpolated per byte between the keys
 * around it; the table ends with key -1 (last colour kept). */
void func_088522CC(s32 arg0, Key *p, s32 t, u32 *out) {
    s32 k, n;

    for (;;) {
        k = p->key;
        if (k == -1) break;
        if (t == k) {
            *out = p->color;
            return;
        }
        n = p[1].key;
        if (k < t && t < n) {
            float f = (float)(t - k) / (float)(n - k);
            u8 r0 = (p->color & 0xFF0000) >> 16;
            u8 g0 = (p->color & 0xFF00) >> 8;
            u8 b0 = p->color & 0xFF;
            u8 a0 = (p->color & 0xFF000000) >> 24;
            u8 a1 = (p[1].color & 0xFF000000) >> 24;
            u8 r1 = (p[1].color & 0xFF0000) >> 16;
            u8 g1 = (p[1].color & 0xFF00) >> 8;
            u8 b1 = p[1].color & 0xFF;
            *out = ((u8)((u8)a0 + (u8)(u32)(f * ((float)a1 - (float)a0))) << 24)
                 | ((u8)((u8)r0 + (u8)(u32)(f * ((float)r1 - (float)r0))) << 16)
                 | ((u8)((u8)g0 + (u8)(u32)(f * ((float)g1 - (float)g0))) << 8)
                 | (u8)((u8)b0 + (u8)(u32)(f * ((float)b1 - (float)b0)));
            return;
        }
        p++;
    }
    *out = p[-1].color;
}
