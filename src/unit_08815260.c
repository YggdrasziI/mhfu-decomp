/* unit_08815260: 0x08815260-0x08815348 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08815260 (ULES01213)
 *
 * Side tests of a point against the four edges of a quad on the XZ plane
 * (hypothesis on the purpose): returns 2 when the point lies on the outer
 * side of one edge, 0 otherwise. The first argument is unused.
 * The difference locals are reassigned for each edge: that sets the
 * schedule of the subtractions and products.
 */

typedef int s32;
typedef float f32;

s32 func_08815260(void *arg0, f32 *p, f32 *q) {
    f32 dx, dz, ex, ez;

    dx = q[0] - p[0];
    dz = q[2] - p[2];
    ex = p[0] - p[4];
    ez = p[2] - p[6];
    if (ez * dx - dz * ex < 0.0f) {
        return 2;
    }
    ex = p[5] - p[0];
    ez = p[7] - p[2];
    if (ez * dx - dz * ex < 0.0f) {
        return 2;
    }
    dx = q[0] - p[1];
    dz = q[2] - p[3];
    ex = p[4] - p[1];
    ez = p[6] - p[3];
    if (ez * dx - dz * ex < 0.0f) {
        return 2;
    }
    ex = p[1] - p[5];
    ez = p[3] - p[7];
    if (ez * dx - dz * ex < 0.0f) {
        return 2;
    }
    return 0;
}
