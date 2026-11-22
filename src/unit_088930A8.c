/* unit_088930A8: 0x088930A8-0x08893198 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_088930A8: clear a 0x360-byte block, then feed every printable
 * character of the current entry list's strings to func_08893198. */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

typedef struct {
    s32 unk0;
    s32 unk4;
    u16 *str;
} Entry;

extern void memset(void *, s32, s32);
extern void func_08893198(char *, s32);

void func_088930A8(char *arg0) {
    Entry *e;
    s32 i;
    s32 n;
    u16 *p;
    s32 c;
    s32 idx;

    memset(arg0 + 0x22608, 0, 0x360);
    idx = *(s8 *) (arg0 + 0x15D);
    e = ((Entry **) (arg0 + 0x140))[idx];
    n = ((u8 *) (arg0 + 0x134))[idx];
    for (i = 0; i < n; i++, e++) {
        p = e->str;
        while (1) {
            c = *p++;
            if (c == 0) {
                break;
            }
            if (c == 0xA || c == 0x20 || c == 0xA0 || c == 0x2002 || c == 0x2003 || c == 0x3000) {
                continue;
            }
            func_08893198(arg0, c);
        }
    }
}
