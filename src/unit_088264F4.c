/* unit_088264F4: 0x088264F4-0x08826688 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern s32 D_08A62C50;
extern void func_0881C68C(char *, char *, s32, s32);
extern char *func_0885C13C(s32, u8 *, s32, u16 *, u16 *, s32);
extern s32 func_0885B718(s32, char *, s32, s32);

void func_088264F4(char *arg0, s32 arg1) {
    char *rec;
    s32 i;
    s32 j;
    s32 total;
    u8 key;
    s32 base;
    struct { u16 w; u16 h; } sz;
    u16 *out;
    char *hdr;

    hdr = arg0 + 0x5BC;
    func_0881C68C(arg0, hdr, arg1, 0);
    out = (u16 *)(arg0 + 0x5C8);
    for (j = 0; j < *(u8 *)(hdr + 6); j++) {
        out[j] = 0;
    }
    base = *(u8 *)(hdr + 6) * *(u8 *)(hdr + 8);
    total = base + (*(u8 *)(hdr + 8) < *(u8 *)(hdr + 9) - 1 ? *(u8 *)(hdr + 6) : *(u8 *)(hdr + 0xA));
    key = *(u8 *)(arg0 + 0x5D8);
    for (i = 0; i < total; i++) {
        rec = func_0885C13C(D_08A62C50, &key, 1, &sz.w, &sz.h, 1);
        if (i >= base && i < total) {
            if (*(u16 *)(hdr + 4) == i) {
                *(char **)(arg0 + 0x5A8) = rec;
                *(u8 *)(arg0 + 0x5BB) = key;
                *(u16 *)(arg0 + 0x5AC) = sz.w;
                *(u16 *)(arg0 + 0x5AE) = sz.h;
            }
            *out = *(s16 *)(rec + 2);
            if ((u8)func_0885B718(D_08A62C50, rec, 1, 0) == 1) {
                if (*(u8 *)(rec + 7) & 1) {
                    *out |= 0x8000;
                }
            } else {
                *out |= 0x4000;
            }
            out++;
        }
    }
}
