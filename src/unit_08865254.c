/* unit_08865254: 0x08865254-0x088652DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;

char *func_08865254(char *arg0, u32 arg1) {
    char *base = *(char **)(arg0 + 0x1AC);
    u32 group;
    u32 id;
    u32 *entry;
    s32 off;

    if (base == 0) {
        return 0;
    }
    group = arg1 % 1000;
    id = group % 100;
    entry = (u32 *)(base + (group / 100) * 8);
    if (id >= entry[0]) {
        return 0;
    }
    off = *(s32 *)(base + entry[1] + id * 4);
    if (off == -1) {
        return 0;
    }
    return base + off;
}