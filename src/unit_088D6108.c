/* unit_088D6108: 0x088D6108-0x088D61CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

extern char *D_09A4F0C4;

extern char *func_08865254(char *, u32);

char *func_088D6108(char *arg0, u32 arg1) {
    char *g;
    char *base;
    u32 id;
    u32 *entry;
    s32 off;

    if (arg1 >= 1000) {
        return func_08865254(arg0, arg1);
    }
    g = D_09A4F0C4;
    if (g == 0) {
        return func_08865254(arg0, arg1);
    }
    base = *(char **)(g + 0x40);
    if (base == 0) {
        return func_08865254(arg0, arg1);
    }
    id = arg1 % 100;
    entry = (u32 *)(base + (arg1 / 100) * 8);
    if (id >= entry[0]) {
        return 0;
    }
    off = *(s32 *)(base + entry[1] + id * 4);
    if (off == -1) {
        return 0;
    }
    return base + off;
}