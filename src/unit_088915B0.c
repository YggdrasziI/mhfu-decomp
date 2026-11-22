/* unit_088915B0: 0x088915B0-0x08891700 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#include "libc/stdarg.h"

typedef struct Entry {
    s16 x;
    s16 y;
    u8 b4;
    u8 b5;
    s8 b6;
    u8 b7;
    char *text;
} Entry;

typedef struct Obj {
    char pad0[0x120];
    s16 x;           /* 0x120 */
    s16 y;           /* 0x122 */
    char pad124[0x8];
    u8 b12C;         /* 0x12C */
    u8 b12D;         /* 0x12D */
    s8 b12E;         /* 0x12E */
    s8 cur;          /* 0x12F */
    char pad130[0x4];
    u8 count[0xC];   /* 0x134 */
    Entry *list[7];  /* 0x140 */
    char pad15C[0x3];
    u8 b15F;         /* 0x15F */
    u16 off;         /* 0x160 */
} Obj;

extern void func_08890DFC(Obj *, s16, s16);
extern void func_08890E38(Obj *, s8);
extern void memset(void *, s32, s32);
extern void func_08893C6C(Obj *, char *, s32, const char *, va_list, s32);
extern void func_08894754(Obj *, char *, s32);

void func_088915B0(Obj *arg0, s16 arg1, s16 arg2, s8 arg3, const char *fmt, ...) {
    char buf[0x300];
    va_list ap;
    u8 n;
    Entry *e;

    n = arg0->count[arg0->cur];
    if (n < 0x80) {
        func_08890DFC(arg0, arg1, arg2);
        func_08890E38(arg0, arg3);
        e = &arg0->list[arg0->cur][n];
        arg0->count[arg0->cur]++;
        e->x = arg0->x;
        e->y = arg0->y;
        e->b4 = arg0->b12C;
        e->b5 = arg0->b12D;
        e->b7 = arg0->b15F;
        e->b6 = arg0->b12E;
        e->text = (char *)arg0 + arg0->off + 0x22CF8;
        memset(buf, 0, 0x300);
        va_start(ap, fmt);
        func_08893C6C(arg0, buf, 0x300, fmt, ap, 1);
        func_08894754(arg0, buf, 1);
    }
}
