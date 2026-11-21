/* unit_0889FD08: 0x0889FD08-0x088A00B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_0889FB94) and unit_088A00B0.
 *
 * Optimized for speed: the divisions by 4095, 100, 32767 and 44100 are
 * multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 a;
    char pad[14];
} Ent;

extern Ent D_09A0D140[];
extern s32 D_09A0D13C;

extern s32 func_088A0AB0(char *);
extern s16 func_088A0BE4(s32);
extern s16 func_088A0AFC(s32);
extern float func_088085A4(float, float);

/* a * b / 4095 as a helper: gives the operand order of the first mult. */
static inline s32 sc(s32 a, s32 b) { return a * b / 4095; }

s32 func_0889FD08(char *arg0) {
    s32 v;
    s32 pan;
    s32 l;
    s32 r;
    s32 rate;
    s32 t;
    float f;
    s32 sum;
    u32 base;

    v = sc(sc(D_09A0D140[*(u8 *)(arg0 + 0x1C) & 0xF].a, *(u16 *)(arg0 + 0x22)), *(u16 *)(arg0 + 0x24) * *(u8 *)(arg0 + 0x2A) / 100);
    v += func_088A0AB0(arg0 + 0x40);
    if (v < 0) {
        v = 0;
    }
    if (v > 0xFFF) {
        v = 0xFFF;
    }
    pan = *(u8 *)(arg0 + 0x20) + (*(u8 *)(arg0 + 0x21) - 0x40);
    if (pan < 0) {
        pan = 0;
    }
    if (pan > 0x7F) {
        pan = 0x7F;
    }
    pan *= 2;
    l = v * func_088A0BE4(pan) / 32767;
    r = v * func_088A0AFC(pan) / 32767;
    sum = *(s16 *)(arg0 + 0x2C) + (*(s16 *)(arg0 + 0x26) + *(s16 *)(arg0 + 0x28));
    sum += func_088A0AB0(arg0 + 0x38);
    f = (float) sum / 1200.0f;
    base = *(u32 *)(arg0 + 0x34);
    rate = ((u32) ((float) base * func_088085A4(2.0f, f)) << 12) / 44100;
    if (D_09A0D13C == 0) {
        t = l;
    } else {
        t = (l + r) / 2;
    }
    *(s16 *)(*(char **)(arg0 + 0x10) + 0x10) = t;
    r = D_09A0D13C == 0 ? r : (l + r) / 2;
    *(s16 *)(*(char **)(arg0 + 0x10) + 0x12) = r;
    *(u16 *)(*(char **)(arg0 + 0x10) + 0x20) = *(u16 *)(arg0 + 0x32);
    *(u16 *)(*(char **)(arg0 + 0x10) + 0x22) = *(u16 *)(arg0 + 0x32);
    *(s32 *)(*(char **)(arg0 + 0x10) + 0xC) |= 0x400;
    if (rate > 0x3FFF) {
        rate = 0x3FFF;
    }
    *(s16 *)(*(char **)(arg0 + 0x10) + 0x14) = rate;
    *(s32 *)(*(char **)(arg0 + 0x10) + 0xC) |= 4;
    if ((*(u8 *)(arg0 + 0x19) & 0xC0) == 0) {
        if ((*(u8 *)(arg0 + 0x18) & 0xC0) == 0x80) {
            *(s8 *)(arg0 + 0x1A) = -*(s8 *)(arg0 + 0x1A);
        }
    } else if ((*(u8 *)(arg0 + 0x19) & 0xC0) == 0x80 && (*(u8 *)(arg0 + 0x18) & 0xC0) == 0) {
        *(s8 *)(arg0 + 0x1A) = -*(s8 *)(arg0 + 0x1A);
    }
    *(u8 *)(arg0 + 0x19) = *(u8 *)(arg0 + 0x18);
    *(s16 *)(*(char **)(arg0 + 0x10) + 0x10) *= *(s8 *)(arg0 + 0x1A);
    *(s16 *)(*(char **)(arg0 + 0x10) + 0x12) *= *(s8 *)(arg0 + 0x1A);
    if (*(u8 *)(arg0 + 0x18) & 0x80) {
        *(s16 *)(*(char **)(arg0 + 0x10) + 0x10) = -*(s16 *)(*(char **)(arg0 + 0x10) + 0x10);
    }
    return 0;
}
