/* unit_0889D6EC: 0x0889D6EC-0x0889D7E8 (ULES01213)
 *
 * The 6-byte id compare is written in place (index on the entry field, not
 * on a pointer parameter).
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 b[6];
} Id;

typedef struct {
    Id id;
    char pad[0x20 - 6];
    char body[200 - 0x20];
} Ent;

typedef struct {
    char pad0[0x57C];
    Ent ent[8];
    char pad1[0xEE3 - 0x57C - 8 * 200];
    s8 n;
    char pad2[0x12D0 - 0xEE4];
    s32 timer;
} P;

extern char *D_08A631A0;
extern void *func_0889C518(P *);
extern s32 func_088B0C8C(char *);

static inline u8 flag(void) {
    return (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0;
}

void func_0889D6EC(P *p) {
    s32 j;
    s32 i;
    s32 r;
    u8 *key;

    if (flag()) {
        for (j = 0; j < p->n; j++) {
            key = (u8 *)func_0889C518(p);
            for (i = 0; i < 6; i++) {
                if (p->ent[j].id.b[i] < key[i]) {
                    r = -1;
                    goto done;
                }
                if (p->ent[j].id.b[i] > key[i]) {
                    r = 1;
                    goto done;
                }
            }
            r = 0;
done:
            if (r == 0) {
                func_088B0C8C(p->ent[j].body);
                break;
            }
        }
        p->timer = 0x3C;
    }
}
