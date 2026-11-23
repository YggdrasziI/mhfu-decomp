/* unit_0886E36C: 0x0886E36C-0x0886E578 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Ent {
    s32 flags;
    u16 idx;
    s16 val;
} Ent;

typedef struct Obj5C2 {
    char pad[0x5C2];
    u8 bits[1];
} Obj5C2;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern u16 D_089AC5B6;

extern s32 func_0886E578(char *, u16, u16);
extern s32 func_0886E6F4(char *, u16);
extern void func_0886E0D8(char *, u16, s32);
extern s32 func_0886A35C(char *, s32);
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);

void func_0886E36C(char *arg0) {
    Ent *e;
    s32 i;
    s32 h;

    e = (Ent *)(arg0 + 0x728);
    for (i = 0; i < 2; i++) {
        if (((e->flags & 0x20) | 0x10) == 0x10) {
            if ((e->flags & 2) == 2) {
                h = func_0886E578(arg0, e->idx, i);
                e->val = h - func_0886E6F4(arg0, e->idx);
                if (e->val <= 0) {
                    func_0886E0D8(arg0, i, 2);
                }
            }
            if ((e->flags & 0x4004) == 0x4004) {
                if (((Obj5C2 *)arg0)->bits[e->idx] & (1 << (u16)e->val)) {
                    func_0886E0D8(arg0, i, 0x4000);
                }
            }
            if ((e->flags & 0x8004) == 0x8004 && *(s32 *)(arg0 + 0x720) != 0) {
                if (e->flags & 0x10000) {
                    h = func_0886A35C(arg0, 1) / 2;
                    if (func_0886A35C(arg0, 0) > h) {
                        continue;
                    }
                }
                if (((s16 *)arg0)[0x114 / 2] - *(s16 *)(*(char **)(arg0 + 0x720) + 0x2E4) >= e->val * 100) {
                    if ((e->flags & 0x10000) == 0x10000 && arg0[6] != 5 && ((u8 *)arg0)[0x8A4] == 0) {
                        func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B6));
                        arg0[0x8A4] = 1;
                    }
                    func_0886E0D8(arg0, i, 0x8000);
                }
            }
        }
        e++;
    }
}
