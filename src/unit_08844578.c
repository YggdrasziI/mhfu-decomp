/* unit_08844578: 0x08844578-0x08844654 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08844578 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern u8 D_0893914C[];
extern s32 func_088446CC(s32, s32);

u8 func_08844578(char *arg0, char *arg1) {
    u8 m;
    u8 r;

    if (arg1 == 0) {
        return 0;
    }
    if ((s32)((*(u32 *)(arg1 + 4) & 1) != 0) == 0) {
        return 0;
    }
    m = *(u8 *)(arg0 + 0x578);
    if (m != (u8)func_088446CC((s32)arg0, *(u16 *)(arg1 + 0x29A))) {
        return 0;
    }
    m = D_0893914C[*(u8 *)(arg1 + 0x1E8)];
    if (m == 0xFF || (m & 0xC0) == 0x80) {
        if (*(u8 *)(arg1 + 0x3D0) != 0) {
            return 1;
        }
        return 0;
    }
    r = *(u8 *)(arg0 + 0x5E7);
    if (*(u8 *)(arg1 + 0x3D0) != 0) {
        r |= 1;
    }
    if (r == 2) {
        return 0;
    }
    return r;
}
