/* unit_0889BFA0: 0x0889BFA0-0x0889C0D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

typedef struct {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
} Arg;

extern "C" {
extern u8 *D_089CC434;
extern char *D_089CC438;
extern s32 D_08A62D8C;
extern void func_088B3744(u8 *);
extern void func_0889CD24(char *, u8 *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void memset(void *, s32, s32);
void func_0889BFA0(Arg *arg0);
}

void func_0889BFA0(Arg *arg0) {
    char *p;
    s32 i;
    s32 r;

    Arg copy = *arg0;
    u8 buf[8];
    p = *(char **)&copy.unk8;
    func_088B3744(buf);
    func_0889CD24(p, buf);
    for (i = 0; i < 6; i++) {
        u8 a = buf[i];
        u8 b = p[0x12C8 + i];
        if (b < a) {
            r = -1;
            goto done;
        }
        if (a < b) {
            r = 1;
            goto done;
        }
    }
    r = 0;
done:
    if (r != 0) {
        return;
    }
    *(s32 *)(p + 0x12C4) |= 0x200;
    if (D_089CC434[0x30000 - 0x6CF4] == 0) {
        func_08883988(D_08A62D8C, 3, 0x1D, 0, 0, 0, 0, 0, 0);
        if ((bool) (*(s32 *)(D_089CC438 + 0x70000 - 0x50EC) & 8) != 0) {
            memset(p + 0x12C8, 0, 8);
        }
    }
}
