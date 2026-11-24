/* unit_08850FB8: 0x08850FB8-0x0885100C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef unsigned int u32;

void func_08850FB8(char *arg0) {
    u32 t;

    *(u16 *)(arg0 + 0x1C) += 1;
    if (*(u16 *)(arg0 + 0x1C) % 30 == 0) {
        t = *(u32 *)(arg0 + 0x4468) + 1;
        *(u32 *)(arg0 + 0x4468) = t;
        if (t > 0x22550FF) {
            *(u32 *)(arg0 + 0x4468) = 0x22550FF;
        }
    }
}
