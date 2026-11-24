/* unit_08852114: 0x08852114-0x08852200 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852114: keyframe lookup with linear interpolation (hypothesis). */

typedef float f32;
typedef int s32;

typedef struct {
    f32 t;
    f32 x;
    f32 y;
    f32 z;
} Key;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

void func_08852114(s32 arg0, f32 t, Key *k, Vec *out) {
    f32 r;

    while (1) {
        if (k->t == -1.0f) {
            break;
        }
        if (t == k->t) {
            out->x = k->x;
            out->y = k->y;
            out->z = k->z;
            return;
        }
        if (t > k->t && t < k[1].t) {
            r = (t - k->t) / (k[1].t - k->t);
            out->x = k->x + r * (k[1].x - k->x);
            out->y = k->y + r * (k[1].y - k->y);
            out->z = k->z + r * (k[1].z - k->z);
            return;
        }
        k++;
    }
    out->x = k[-1].x;
    out->y = k[-1].y;
    out->z = k[-1].z;
}
