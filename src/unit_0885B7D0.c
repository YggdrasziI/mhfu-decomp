/* unit_0885B7D0: 0x0885B7D0-0x0885B82C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B7D0 */

typedef int s32;
typedef unsigned char u8;

extern char *D_089CC438;

extern char *func_0885B5B8(s32, s32, s32, s32, s32, s32);

s32 func_0885B7D0(s32 arg0, s32 arg1, s32 arg2) {
    char *e = func_0885B5B8(arg0, arg1, arg2, 0, 0, 0);
    u8 id;
    u8 b;

    if (e == 0) {
        return 0;
    }
    id = *(u8 *)(e + 6);
    b = ((u8 *)(D_089CC438 + 0x446C))[id >> 3];
    return (b & (1 << (id & 7))) != 0;
}
