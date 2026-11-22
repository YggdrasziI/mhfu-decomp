/* unit_08872444: 0x08872444-0x0887265C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* Optimized for speed: the inner loop is guarded and tested at the bottom.
 * The flag bytes are read into a u8 local so that the `and` takes the byte
 * first; the id is an s32 local narrowed with (u8) in the 0x80 branch only. */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 id;
    u8 bit;
    u16 vals[6];
} Rec;

extern Rec D_09CDE6C0[];
extern s32 D_09CDD850[];
extern s8 D_089A7F64[];
extern s8 D_089A7F74[];
extern s8 D_089A7F78[];
extern s8 D_089A7F7C[];
extern char *D_089CC438;
extern char *D_08A631A0;
extern s32 D_09A4F0C4;

extern char *func_088DCEBC(s32, u8);
extern s32 func_088D6A1C(char *, s32);
extern s32 func_088900C4(char *, s32);
extern u16 func_0887265C(s32, char *);

void func_08872444(char *arg0) {
    s32 i = 16;
    Rec *rec;
    s32 val;
    s8 *chances;
    char *obj;
    s32 mask;
    u8 f;
    s32 id;
    s32 c;
    u16 v;

    for (rec = D_09CDE6C0; (id = rec->id) != 0xFF; rec++) {
        if (rec->bit == 0x80) {
            if (*(u16 *)(arg0 + 0x350 + (u8)id * 2) == 0) {
                continue;
            }
            if (*(s32 *)(arg0 + 0x28) & 0x400000) {
                continue;
            }
        } else {
            mask = 1 << rec->bit;
            f = *(u8 *)(arg0 + id + 0x5C2);
            if (!(f & mask)) {
                continue;
            }
            f = *(u8 *)(arg0 + id + 0x61C);
            if (f & mask) {
                continue;
            }
            *(u8 *)(arg0 + id + 0x61C) = f | (u8)mask;
        }
        v = rec->vals[*(s8 *)(*(char **)(arg0 + 0x4C) + 0x44)];
        if (v == 0xFFFF) {
            continue;
        }
        val = D_09CDD850[v];
        if (rec->bit != 0x80) {
            chances = D_089A7F64;
        } else {
            obj = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
            if (func_088D6A1C(obj, 0xCE)) {
                chances = D_089A7F7C;
            } else if (func_088D6A1C(obj, 0xCD)) {
                chances = D_089A7F78;
            } else {
                chances = D_089A7F74;
            }
        }
        for (; i < 32; i++) {
            c = *chances;
            if ((s32)((u16)func_088900C4(D_08A631A0, 0) & 0x1F) >= c) {
                break;
            }
            *(u16 *)(D_089CC438 + i * 4 + 0x390) = func_0887265C(val, D_089CC438 + i * 4 + 0x392);
            chances++;
        }
    }
}
