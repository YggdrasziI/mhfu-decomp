/* unit_088197A0: 0x088197A0-0x088198E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

/* func_088197A0: builds an entry list (optionally compacted and sorted)
 * and passes it to func_088198E4.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    s16 count;
} Entry;

extern char *D_089CC438;

extern Entry *func_08856884(char *, s32);
extern void func_0885C5DC(Entry *, u32);
extern void func_088198E4(char *, Entry *, s32, s32, s32, s32);

void func_088197A0(char *arg0, s32 pos, s32 sel, s32 flags, s32 title) {
    Entry buf[24];
    Entry *src;
    Entry *dst;
    u32 i;
    s32 n;

    if (!(flags & 2)) {
        src = func_08856884(D_089CC438, 0);
    } else {
        src = (Entry *)(D_089CC438 + 0x43C8);
    }
    if (flags & 0x20) {
        dst = buf;
        n = 0;
        for (i = 24; i != 0; i--, src++) {
            if (((volatile Entry *)src)->id != 0) {
                n++;
                dst->id = src->id;
                dst->count = src->count;
                dst++;
            }
        }
        for (i = 24 - n; i != 0; i--, dst++) {
            dst->count = 0;
            dst->id = 0;
        }
        func_0885C5DC(buf, n);
        src = buf;
        sel = 0;
        if (flags & 1) {
            flags = 0x21;
        } else {
            flags = 0x20;
        }
        pos = pos % 8;
    }
    func_088198E4(arg0, src, pos, sel, flags, title);
}
