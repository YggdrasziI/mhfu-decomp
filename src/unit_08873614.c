/* unit_08873614: 0x08873614-0x0887370C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    s16 id;
    s16 pad02;
    s8 val;
    u8 pad05[0x2C - 0x05];
    s16 bit;
    u8 pad2E[0x3C - 0x2E];
} Entry;

typedef struct {
    s32 pad00;
    s32 pad04;
    s32 active;
    s32 offset;
} Group;

static inline u8 test_flag(u8 *arg0, s32 bit) {
    return (*(u32 *)(arg0 + 0x56C + (bit / 32) * 4) & (1 << (bit % 32))) != 0;
}

static inline void set_flag(u8 *arg0, s32 bit) {
    *(u32 *)(arg0 + 0x56C + (bit / 32) * 4) |= 1 << (bit % 32);
}

void func_08873614(u8 *arg0, Group *arg1, u16 *arg2) {
    Entry *e;

    for (;; arg1++) {
        if (arg1->active == 0) {
            return;
        }
        if (arg1->offset == 0) {
            continue;
        }
        for (e = (Entry *)(arg1->offset + *(s32 *)(arg0 + 0x50));; e++) {
            if (e->id == -1) {
                break;
            }
            if (test_flag(arg0, e->bit)) {
                continue;
            }
            arg2[e->id] += e->val;
            set_flag(arg0, e->bit);
        }
    }
}
