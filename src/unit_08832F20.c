/* unit_08832F20: 0x08832F20-0x08833290 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Rec;

extern char D_08938478;
extern char D_08938540;
extern char D_0893879C;
extern Rec D_08939430;
extern Rec D_08939850;
extern char *D_08A631A8;
extern int func_0880E8F0(char *, char *, ...);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C11C(char *, u16, u16, s32, s32, u8, u8, u8, u8, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern s32 func_08890E48(char *, char *);
extern int func_088915B0(char *, s32, s32, s32, char *, ...);

void func_08832F20(char *arg0, s32 x, s32 y, u8 idx, u8 cnt, s32 flags) {
    char buf[16];
    Rec *p;
    s16 w;
    u8 m;
    Rec *q;
    s32 yy;
    s32 xx;

    func_08890DE8(D_08A631A8, 0xE, 0xE);
    if (flags & 4) {
        func_0880E8F0(buf, &D_08938540, idx + 1, cnt);
    } else {
        func_0880E8F0(buf, &D_0893879C, idx + 1, cnt);
    }
    func_08890E48(D_08A631A8, buf);
    w = func_08890E48(D_08A631A8, buf) * 7;
    x = (s16) ((s16) x - (w >> 1));
    func_088915B0(D_08A631A8, x, y, 0, &D_08938478, buf);
    m = 0;
    if (flags & 1) {
        m = 3;
    } else if (cnt > 1) {
        if (idx != 0) {
            m |= 1;
        }
        if (idx != cnt - 1) {
            m |= 2;
        }
    }
    if (m != 0) {
        p = &D_08939850;
        if (!(flags & 2)) {
            if (m & 1) {
                func_0882C7B4(arg0, (s16) x - 2 - p->unk4, (s16) ((s16) y - 1), p->unk4, p->unk6, 0, 0xC0, 0x40, 0xF0, 0x8E, 1);
            }
            if (m & 2) {
                func_0882C11C(arg0, (s16) x + 2 + w, (s16) ((s16) y - 1), p->unk4, p->unk6, 0, 0xC0, 0x40, 0xF0, 0x8E);
            }
        } else {
            q = &D_08939430;
            if (m & 1) {
                func_0882C7B4(arg0, (s16) x - 4 - p->unk4 - q->unk4, (s16) ((s16) y - 1), p->unk4, p->unk6, 0, 0xC0, 0x40, 0xF0, 0x8E, 1);
                func_0882A9DC(arg0, (s16) x - 2 - q->unk4, (s16) ((s16) y - 1) - 1, 0x36);
            }
            if (m & 2) {
                yy = (s16) y - 1;
                xx = (s16) x;
                func_0882C11C(arg0, q->unk4 + (xx + 4 + w), (s16) yy, p->unk4, p->unk6, 0, 0xC0, 0x40, 0xF0, 0x8E);
                func_0882A9DC(arg0, xx + 2 + w, (s16) yy - 1, 0x37);
            }
        }
    }
}
