/* unit_088CBBAC: 0x088CBBAC-0x088CBD20 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088CBBAC: interpolates the four bytes of a colour from a toward b
 * by t, channels in the order 2, 1, 0, 3. */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef union Color {
    u32 w;
    u8 c[4];
} Color;

void func_088CBBAC(Color *out, char *arg1, u8 *a, u8 *b, float t) {
    Color tmp;

    tmp.c[0] = a[2] + (u8)(u32)(t * (s32)(b[2] - a[2]));
    tmp.c[1] = a[1] + (u8)(u32)(t * (s32)(b[1] - a[1]));
    tmp.c[2] = a[0] + (u8)(u32)(t * (s32)(b[0] - a[0]));
    tmp.c[3] = a[3] + (u8)(u32)(t * (s32)(b[3] - a[3]));
    *out = tmp;
}
