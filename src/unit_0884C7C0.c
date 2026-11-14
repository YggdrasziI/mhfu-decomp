/* unit_0884C7C0: 0x0884C7C0-0x0884C89C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 * Four words appended through D_089CC000 from a table of 4-word entries.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern s32 D_0893B7D0[];
extern u32 *D_089CC000;

void func_0884C7C0(s32 arg0, u8 arg1) {
    s32 i;

    *D_089CC000++ = 0x20000001;
    i = (u8) (arg1 * 4);
    *D_089CC000++ = D_0893B7D0[i];
    *D_089CC000++ = D_0893B7D0[i + 1];
    *D_089CC000++ = D_0893B7D0[i + 2];
    *D_089CC000++ = D_0893B7D0[i + 3];
}
