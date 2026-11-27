/* unit_0882F580: 0x0882F580-0x0882F9A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a menu window described by w: frame (kind = low nibble of byte
 * 0xB), title, an optional bar/separator and a list of entries whose
 * strings come from one of seven text sources selected by src.
 * - Speed setting and opt_loop_invariants off: the kind - 4 range test is
 *   recomputed at each pass of the entry loop.
 * - Separator loop: x as an s32 holding an s16, copied into a u16 inside the
 *   guard (the mask sits between the guard and the loop); width as a u16.
 * - The entry loop steps y in the for step after i++; x and y are s32
 *   locals holding s16 values (no seh at the call).
 * - Two jump tables (jtbl_08930B60, jtbl_08930B44) built by the switches.
 */

#pragma optimize_for_size off
#pragma opt_loop_invariants off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 w;
    /* 0x06 */ u16 h;
    /* 0x08 */ u8 font;
    /* 0x09 */ u8 size;
    /* 0x0A */ s8 colour;
    /* 0x0B */ u8 kind;
    /* 0x0C */ s16 tx;
    /* 0x0E */ s16 ty;
    /* 0x10 */ u16 step;
    /* 0x12 */ u16 count;
    /* 0x14 */ void *items;
    /* 0x18 */ s32 cur;
    /* 0x1C */ u16 cx;
    /* 0x1E */ u16 cy;
    /* 0x20 */ u16 cw;
    /* 0x22 */ u16 ch;
    /* 0x24 */ s16 titleX;
    /* 0x26 */ s16 titleY;
} Window;

extern char *D_08A631A8;
extern char D_08938478[];
extern char *D_089CC438;
extern s32 D_09B22D70;
extern s32 D_09A44C5C;
extern s32 D_09A4F068;

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0882DCA8(char *, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, u8, u8);
extern void func_08890E38(char *, s32);
extern void func_0882D8DC(char *, u16, u16, u16, u16, s32, s32, s32, s32);
extern void func_088920A8(char *, s32, s32, char *, ...);
extern void func_0882F4A4(char *, u16, u16, u16, u16, s32);
extern void func_08831F3C(char *, u16, u16, u16, u16, u8, u8, u8);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_09A7B790(s32, u16);
extern char *func_09A63188(s32, u16);
extern char *func_09A63198(s32, u16);
extern char *func_09A7B7C0(s32, u16);
extern char *func_09A6E348(s32, u16);
extern s32 func_08890E48(char *, char *);

void func_0882F580(char *dl, Window *w, char *title, s32 sel, s32 frame, s32 src) {
    s32 kind;
    s32 n;
    s32 x;
    s32 y;
    u16 ww;
    s32 bx;
    u16 ub;
    s32 tw;
    char *s;
    s32 i;

    kind = w->kind & 0xF;
    switch (kind) {
    case 0:
    case 2:
    case 4:
    case 6:
        func_0882DCA0(dl, w->x, w->y, w->w, w->h, frame);
        break;
    case 1:
    case 3:
    case 5:
        func_0882DCA8(dl, w->x, w->y, w->w, w->h, frame);
        break;
    }
    func_08890DE8(D_08A631A8, w->font, w->size);
    func_08890E38(D_08A631A8, w->colour);
    if (title != 0) {
        func_0882D8DC(dl, w->x + 6, w->y + 6, w->w - 12, (u16)w->titleY + w->size - w->y - 6,
                      0xFF, 0xFF, 0xFF, 0x38);
        func_088920A8(D_08A631A8, w->titleX, w->titleY, D_08938478, title);
    }
    if (sel >= 0) {
        y = (s16)(w->cy + w->step * sel);
        if (kind != 6) {
            func_0882F4A4(dl, w->cx, y, w->cw, w->ch, w->cur);
        } else {
            func_08831F3C(dl, w->cx, y, w->cw, w->ch, ((u8 *)&w->cur)[2], ((u8 *)&w->cur)[1],
                          ((u8 *)&w->cur)[0]);
        }
    }
    if ((u32)(kind - 2) < 2) {
        if (title != 0) {
            func_0882D6F0(dl, w->x + 6, (u16)w->titleY + w->size, w->w - 12, 2, 0x80, 0x80, 0x80);
        }
        bx = (s16)(w->x + 8);
        y = (s16)((u16)w->ty + w->size);
        ww = w->w - 16;
        n = w->count - 1;
        if (n > 0) {
            ub = bx;
            do {
                func_0882D6F0(dl, ub, y, ww, 1, 0x80, 0x80, 0x80);
                y = (s16)(y + (s16)w->step);
            } while (--n > 0);
        }
    }
    if (w->items != 0) {
        x = w->tx;
        y = w->ty;
        for (i = 0; i < w->count; i++, y = (s16)(y + (s16)w->step)) {
            u16 id = ((u16 *)w->items)[i];
            if (id == 0xFFFF) {
                return;
            }
            switch (src) {
            case 0:
                s = func_0885151C(D_089CC438, id);
                break;
            case 1:
                s = func_09A7B790(D_09B22D70, id);
                break;
            case 2:
                s = func_09A63188(D_09A44C5C, id);
                break;
            case 4:
                s = func_09A63198(D_09A44C5C, id);
                break;
            case 5:
                s = func_09A7B7C0(D_09B22D70, id);
                break;
            case 6:
                s = func_09A6E348(D_09A4F068, id);
                break;
            case 3:
                s = ((char **)w->items)[i];
                break;
            }
            if ((u32)(kind - 4) < 2) {
                tw = func_08890E48(D_08A631A8, s);
                x = (s16)((u16)(w->x + (w->w >> 1)) - ((w->font * tw) >> 2));
            }
            func_088920A8(D_08A631A8, x, y, D_08938478, s);
        }
    }
}
