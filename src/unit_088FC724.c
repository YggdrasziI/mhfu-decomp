/* unit_088FC724: 0x088FC724-0x088FC7A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Stores arg2 into the value of the first of three 0x1C-byte entries at
 * arg0 + 0x2C whose type is 2 and whose six-byte id equals arg1.
 *
 * #pragma optimize_for_size off: the loop is tested at the bottom.
 */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 value;
    char pad4[0x12];
    /* 0x16 */ char id[6];
} Entry; /* size 0x1C */

extern s32 func_0880BFF0(void *, void *, s32);

void func_088FC724(char *arg0, char *id, u16 value) {
    Entry *e;
    s32 i;

    e = (Entry *)(arg0 + 0x2C);
    for (i = 0; i < 3; i++, e++) {
        if (e->type == 2 && func_0880BFF0(e->id, id, 6) == 0) {
            e->value = value;
            return;
        }
    }
}
