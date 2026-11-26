/* unit_08830D3C: 0x08830D3C-0x08830F74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* unit_08830D3C: 0x08830D3C-0x08830F74 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * #pragma optimize_for_size off: puts arg0 in s6 (saved registers otherwise
 * rotated). #pragma opt_rebuildconditionals off: keeps the 0/1 table index
 * as a beqzl branch instead of sltu/xori. buf is declared 8 bytes so that it
 * lands at sp+0x28.
 */

#pragma optimize_for_size off
#pragma opt_rebuildconditionals off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_08A631A8;
extern char *D_089CC438;
extern char D_08938770;
extern char D_08938478;
extern u16 D_089AC868[];
extern u16 D_089AC86C;

extern void func_0882FC50(char *, char *, s32, s32);
extern void func_08890E40(char *, s32);
extern void func_08890E38(char *, s8);
extern s16 func_08892708(char *, s16, char *, char *, char **);
extern void func_08890DFC(char *, s16, s16);
extern void func_088921FC(char *, s16, char *);
extern char *func_0885151C(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08830D3C(char *arg0) {
    char buf[8];
    char *next;
    char *next2;
    s16 r;
    s32 n;
    s32 w;
    s32 cnt;
    s32 i;
    s16 y;
    char *p;
    s32 idx;

    if (*(s8 *)(arg0 + 0x5F0) & 0x10) {
        return;
    }
    func_0882FC50(arg0, &D_08938770, 0, 0xFF);
    if (*(s8 *)(arg0 + 0x5F0) & 0x20) {
        return;
    }
    func_08890E40(D_08A631A8, 0x10);
    func_08890E38(D_08A631A8, 0);
    n = *(s16 *)(arg0 + 0x5F2);
    p = *(char **)(arg0 + 0x5EC);
    y = 0x60;
    if (n > 0) do {
        i = 0;
        w = 0x16;
        cnt = 0;
        while (n > 0 && w > 0) {
            r = func_08892708(D_08A631A8, i, buf, p, &next);
            i++;
            if (buf[0] == 0xA) {
                break;
            }
            n--;
            cnt++;
            if (r == 1 || r == 2) {
                w--;
            }
            w--;
        }
        func_08890DFC(D_08A631A8, 0x10, y);
        func_088921FC(D_08A631A8, cnt, p);
        y += 0x10;
        if (w == 0) {
            func_08892708(D_08A631A8, i, buf, p, &next2);
            if (buf[0] == 0xA) {
                p = next2;
            } else {
                p = next;
            }
        } else {
            p = next;
        }
    } while (n > 0);
    if (*(s8 *)(arg0 + 0x5F0) & 2) {
        if (*(s8 *)(arg0 + 0x5F0) & 4) {
            idx = 0;
        } else {
            idx = 1;
        }
        func_088920A8(D_08A631A8, 0x10, y, &D_08938478,
                      func_0885151C(D_089CC438, D_089AC868[idx]));
    }
    if (*(s8 *)(arg0 + 0x5F0) & 8) {
        func_088915B0(D_08A631A8, 0x72, y, 2, &D_08938478, func_0885151C(D_089CC438, D_089AC86C));
    }
}
