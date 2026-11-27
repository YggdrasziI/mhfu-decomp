/* unit_08812338: 0x08812338-0x088123C8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * Searches a 0x4000-bit map at offset 0x458 for a run of arg1 clear bits
 * and returns the index of its first bit, or -1.
 */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    char pad[0x458];
    s32 bits[0x200];
} Map;

s32 func_08812338(Map *arg0, u32 arg1) {
    s32 i;
    u32 count;
    s32 start;

    count = 0;
    start = 0;
    i = 0;
    do {
        if (!(arg0->bits[i / 32] & (1 << (i % 32)))) {
            if (count == 0) {
                start = i;
            }
            count++;
            if (count >= arg1) {
                return start;
            }
        } else {
            count = 0;
        }
        i++;
    } while (i < 0x4000);
    return -1;
}
