/* unit_088900C4: 0x088900C4-0x08890114 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. Pseudo-random generator: a 16-bit seed
 * in a table at arg0 + 0xF7A56C, stepped by seed * 176 mod 0xFF53.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

u16 func_088900C4(char *arg0, s32 arg1) {
    u16 *p = (u16 *)(arg0 + 0xF7A56C) + arg1;
    u32 v = *p;

    if (v == 0) {
        v = 1;
    }
    *p = (v * 176) % 0xFF53;
    return *p;
}
