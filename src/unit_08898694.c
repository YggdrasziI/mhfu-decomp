/* unit_08898694: 0x08898694-0x08898748 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * A table of 0x200 entries of 12 bytes at offset 0x83C030 (func_0889885C returns
 * the first entry whose first word is -1). The code only matches with member
 * accesses through the array, not with offsets added to a pointer (the `addu`
 * operands come out swapped). Structure and field names are placeholders.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Entry;

typedef struct {
    char pad[0x83C030];
    Entry entries[0x200];
} Table;

extern s32 func_08859B44(void *, s32, s32);
extern s32 func_0889885C(void *);

s32 func_08898694(Table *arg0, s32 arg1, s32 arg2) {
    s32 i;

    i = func_0889885C(arg0);
    if (i != -1) {
        arg0->entries[i].unk4 = func_08859B44(arg0, arg2, 0x10);
        if (arg0->entries[i].unk4 != 0) {
            arg0->entries[i].unk8 = arg2;
            arg0->entries[i].unk0 = arg1;
            return arg0->entries[i].unk4;
        }
    }
    return 0;
}
