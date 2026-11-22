/* unit_088987D4: 0x088987D4-0x0889885C (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_088987D4: clears the first entry whose unk4 equals arg1 (hypothesis: 0x200 12-byte records at 0x83C030). */
#pragma optimize_for_size off

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Entry;

typedef struct {
    char pad[0x83C030];
    Entry entries[0x200];
} Work;

extern int func_08859C40(void *, s32);

void func_088987D4(Work *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < 0x200; i++) {
        if (arg0->entries[i].unk4 == arg1) {
            func_08859C40(arg0, arg0->entries[i].unk4);
            arg0->entries[i].unk0 = -1;
            return;
        }
    }
}
