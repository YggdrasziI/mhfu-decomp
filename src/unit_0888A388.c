/* unit_0888A388: 0x0888A388-0x0888A49C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef float f32;

typedef struct {
    f32 pos;
    s32 unk4;
    u8 idx;
} Cursor;

typedef struct {
    f32 len;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Entry;

void func_0888A388(s32 arg0, Cursor *cur, char *table, s32 target, f32 end) {
    f32 step = 0.5f;
    f32 d;
    Entry *e;
    u8 i;

    if ((i = cur->idx) < target) {
        do {
            d = *(f32 *)(table + i * 16 + 0x10C) - cur->pos;
            if (d <= step) {
                step -= d;
                cur->idx++;
                cur->pos = 0.0f;
            } else {
                cur->pos = cur->pos + step;
                return;
            }
        } while ((i = cur->idx) < target);
        if (end - cur->pos <= step) {
            cur->pos = end;
        } else {
            cur->pos = cur->pos + step;
        }
    } else {
        e = (Entry *)(table + target * 16 + 0x10C);
        do {
            if (cur->pos <= step) {
                step -= cur->pos;
                cur->idx--;
                cur->pos = e->len;
            } else {
                cur->pos = cur->pos - step;
                return;
            }
        } while (cur->idx > target);
        if (cur->pos - end <= step) {
            cur->pos = end;
        } else {
            cur->pos = cur->pos - step;
        }
    }
}
