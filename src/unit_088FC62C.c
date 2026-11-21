/* unit_088FC62C: 0x088FC62C-0x088FC724 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Fills up to three 0x1C-byte rows of arg1 with the entries (0xC8 bytes
 * each, at +0x57C of D_09A0B544, count at +0xEE3) whose first six bytes
 * match those returned by func_0889C518: a kind (3 when byte +0xBF is 5,
 * else 1), 0x12 bytes from +0x8 and the six bytes themselves.
 *
 * #pragma optimize_for_size off: the loop is entered behind a guard and
 * tested at the bottom (notes/COMPILER.md, "Speed and space").
 * D_09A0B544 is declared volatile and read into a local first: the pointer
 * is loaded again at the top of each pass (no form without volatile gave it).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x00 */ u8 id[6];
    u8 pad6[2];
    /* 0x08 */ u8 name[0x12];
    u8 pad1A[0xBF - 0x1A];
    /* 0xBF */ u8 kind;
    u8 padC0[8];
} Entry;

typedef struct {
    char pad0[0x57C];
    /* 0x57C */ Entry entries[4];
    char pad89C[0xEE3 - 0x89C];
    /* 0xEE3 */ s8 count;
} Game;

extern Game *volatile D_09A0B544;
extern void *func_0889C518(void);
extern int func_0880BFF0(void *, void *, int);
extern void memcpy(void *, void *, s32);

void func_088FC62C(s32 arg0, char *arg1)
{
    s32 i;
    Entry *entry;
    Game *g;

    *(s16 *)(arg1 + 0x0) = 0;
    *(s16 *)(arg1 + 0x1C) = 0;
    *(s16 *)(arg1 + 0x38) = 0;
    for (i = 0; i < D_09A0B544->count; i++) {
        g = D_09A0B544;
        entry = &g->entries[(u8)i];
        if (func_0880BFF0(func_0889C518(), entry, 6) != 0) {
            if (entry->kind == 5) {
                *(s16 *)(arg1 + 0x0) = 3;
            } else {
                *(s16 *)(arg1 + 0x0) = 1;
            }
            *(s16 *)(arg1 + 0x2) = 0;
            memcpy(arg1 + 0x4, entry->name, 0x12);
            memcpy(arg1 + 0x16, entry->id, 6);
            arg1 += 0x1C;
        }
    }
}
