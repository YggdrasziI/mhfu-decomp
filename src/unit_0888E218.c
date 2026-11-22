/* unit_0888E218: 0x0888E218-0x0888E28C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern char *D_09C121B0;

static inline char *get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(char **)(base + 0x1220 + i * 4);
}

char *func_0888E218(char *arg0) {
    char *sub = arg0 + 0xA0;
    char *target = *(char **)(arg0 + 0xF0);
    s32 i;

    if (target != 0) {
        for (i = 0; i < 20; i++) {
            if (get_entry(D_09C121B0, i) == target) {
                return target + 0x10;
            }
        }
    }
    *(u8 *)(sub + 0x99) = 1;
    return 0;
}
