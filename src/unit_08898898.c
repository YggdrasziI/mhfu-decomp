/* unit_08898898: 0x08898898-0x088988EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_08898898: look up a key in a 0x200-entry table of 12-byte records
 * held at offset 0x83C030 of the object; returns the second word or 0.
 */
#pragma optimize_for_size off

typedef int s32;

typedef struct {
    s32 key;
    s32 value;
    s32 unk8;
} Entry;

typedef struct {
    char pad[0x83C030];
    Entry e[0x200];
} Big;

s32 func_08898898(Big *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0x200; i++) {
        if (arg0->e[i].key == arg1) {
            return arg0->e[i].value;
        }
    }
    return 0;
}
