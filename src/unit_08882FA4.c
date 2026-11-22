/* unit_08882FA4: 0x08882FA4-0x0888307C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
} Entry_089AC454;

extern char *D_08A62D84;
extern Entry_089AC454 D_089AC454[];

extern s32 func_0887FF1C(char *arg0);
extern void func_0887FC40(char *arg0, s32 arg1, char *arg2, char *arg3);

void func_08882FA4(char *arg0, s8 arg1) {
    char *base;
    s32 i;
    Entry_089AC454 *entry;
    char *start;
    char *end;
    s32 idx;

    base = arg0 + 0x549BD0;
    idx = func_0887FF1C(D_08A62D84);
    if (idx == -1) {
        return;
    }
    i = 0;
    entry = &D_089AC454[idx * 16];
    do {
        if (entry->unk0 == 0) {
            break;
        }
        start = base;
        end = base + entry->unk0;
        base = end + entry->unk4;
        if (arg1 == 1) {
            func_0887FC40(D_08A62D84, i, start, end);
        } else if (i > 0) {
            func_0887FC40(D_08A62D84, i, start, end);
        }
        i++;
        entry++;
    } while (i < 16);
}
