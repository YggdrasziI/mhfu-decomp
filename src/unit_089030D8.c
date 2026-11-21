/* unit_089030D8: 0x089030D8-0x0890383C (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Fills three parallel 96-slot tables of a list (entry pointer, item pointer,
 * value) from the used entries of the global block, clears the remaining
 * slots, then sorts the used slots by the list's mode (1: item order byte,
 * 2: 16-character name, 3: value, 4: item first word), descending for the
 * numeric modes. Structure and field names are hypotheses.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x00 */ u32 value;
    /* 0x04 */ char pad04[0x22];
    /* 0x26 */ s8 order;
    /* 0x27 */ char pad27[0x1];
} Item; /* size 0x28 */

typedef struct {
    /* 0x00000 */ char pad0[0x16];
    /* 0x00016 */ s8 mode;
    /* 0x00017 */ char pad17[0xA730 - 0x17];
    /* 0x0A730 */ char *names[96];
    /* 0x0A8B0 */ Item *items[96];
    /* 0x0AA30 */ u32 values[96];
} List;

typedef struct {
    /* 0x0000 */ u16 id;
    /* 0x0002 */ char pad2[0x1078 - 2];
} Entry; /* size 0x1078 */

typedef struct {
    /* 0x00000 */ char pad0[0x4A58];
    /* 0x04A58 */ Entry entries[96];
    /* 0x67758 */ char pad67758[0x687D0 - 0x67758];
    /* 0x687D0 */ Item items[96];
    /* 0x696D0 */ char pad696D0[0x6A384 - 0x696D0];
    /* 0x6A384 */ u32 values[96];
} Game;

extern Game *D_089CC438;

void func_089030D8(List *arg0) {
    u8 swap;
    Entry *e;
    u32 b;
    s32 j;
    u32 a;
    u16 c;
    u32 i;
    u32 n;

    n = 0;
    e = D_089CC438->entries;
    for (j = 0; j < 96; j++, e++) {
        if (e->id != 0) {
            n++;
        }
    }
    for (i = 0; i < n; i++) {
        arg0->names[i] = (char *)&D_089CC438->entries[i];
        arg0->values[i] = D_089CC438->values[i];
        arg0->items[i] = &D_089CC438->items[i];
    }
    for (; i < 96; i++) {
        arg0->names[i] = 0;
        arg0->values[i] = 0;
        arg0->items[i] = 0;
    }
    if (n == 0) {
        return;
    }
    if (arg0->mode == 0) {
        return;
    }
    for (a = 0; a < n - 1; a++) {
        for (b = a + 1; b < n; b++) {
            swap = 0;
            switch (arg0->mode) {
            case 1:
                if (arg0->items[b]->order == 0) {
                    arg0->items[b]->order |= 0x80;
                }
                if (arg0->items[a]->order == 0) {
                    arg0->items[a]->order |= 0x80;
                }
                if ((u8)arg0->items[b]->order < (u8)arg0->items[a]->order) {
                    swap = 1;
                }
                break;
            case 2:
                for (c = 0; c < 16; c++) {
                    if ((u16)arg0->names[b][c] < (u16)arg0->names[a][c]) {
                        swap = 1;
                        break;
                    }
                    if ((u16)arg0->names[b][c] > (u16)arg0->names[a][c]) {
                        break;
                    }
                }
                break;
            case 3:
                if (arg0->values[b] > arg0->values[a]) {
                    swap = 1;
                }
                break;
            case 4:
                if (arg0->items[b]->value > arg0->items[a]->value) {
                    swap = 1;
                }
                break;
            }
            if (swap == 1) {
                char *name = arg0->names[a];
                Item *item = arg0->items[a];
                u32 value = arg0->values[a];
                arg0->names[a] = arg0->names[b];
                arg0->items[a] = arg0->items[b];
                arg0->values[a] = arg0->values[b];
                arg0->names[b] = name;
                arg0->items[b] = item;
                arg0->values[b] = value;
            }
        }
    }
}
