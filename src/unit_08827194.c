/* unit_08827194: 0x08827194-0x0882747C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Rec {
    u16 unk0;
    u8 unk2;
    u8 unk3;
    s8 v[6];
    s8 sum;
    u8 res[7];
} Rec;

extern char *D_08A62C54;
extern s32 func_0882747C(char *, char *, Rec *, s32);
extern s8 func_0885CF9C(char *, char *, u8);
extern s8 func_0885D1D4(char *, char *, u8);
extern u8 func_088D6AC8(char *, s32);

s32 func_08827194(char *arg0, char *arg1, Rec *r, s32 arg3) {
    Rec *e;
    s32 n;
    u32 i;

    if (r->unk3 == 1) {
        return func_0882747C(arg0, arg1, r, arg3);
    }
    r->v[0] = func_0885CF9C(D_08A62C54, arg1 + 0x4E8, r->unk3);
    r->v[1] = func_0885CF9C(D_08A62C54, arg1 + 0x500, r->unk3);
    r->v[2] = func_0885D1D4(D_08A62C54, arg1, r->unk3);
    r->v[3] = func_0885CF9C(D_08A62C54, arg1 + 0x518, r->unk3);
    r->v[4] = func_0885CF9C(D_08A62C54, arg1 + 0x524, r->unk3);
    r->v[5] = func_0885CF9C(D_08A62C54, arg1 + 0x4F4, r->unk3);
    if ((r->v[0] | r->v[1] | r->v[2] | r->v[3] | r->v[4] | r->v[5]) == 0) {
        return 0;
    }
    r->unk2 = 0x80;
    r->sum = r->v[0] + r->v[1] + r->v[2] + r->v[3] + r->v[4] + r->v[5];
    r->unk0 = 0;
    if (func_088D6AC8(arg1, r->unk3) != 0) {
        r->unk2 |= 1;
        r->unk0 += 0x8000;
        r->res[0] = r->res[1] = r->res[2] = r->res[3] = r->res[4] = r->res[5] = r->res[6] = 3;
    } else {
        r->res[0] = r->res[1] = r->res[2] = r->res[3] = r->res[4] = r->res[5] = r->res[6] = 0;
    }
    if (r->sum >= 0) {
        r->unk0 += (u16)((r->sum << 7) + 0x4000);
    } else {
        r->unk0 += (u16)(-r->sum << 7);
    }
    r->unk0 += r->unk3;
    if (arg3 != 0) {
        e = (Rec *)(arg0 + 0xA50);
        n = 0x36;
        do {
            if (e->unk2 == 0) {
                break;
            }
            if (r->unk3 == e->unk3) {
                for (i = 0; i < 6; i++) {
                    if (r->v[i] > e->v[i]) {
                        r->res[i] = 4;
                    } else if (e->v[i] > r->v[i]) {
                        r->res[i] = 2;
                    }
                }
                return 1;
            }
            e++;
        } while (--n != 0);
        for (i = 0; i < 6; i++) {
            if (r->v[i] > 0) {
                r->res[i] = 4;
            } else if (r->v[i] < 0) {
                r->res[i] = 2;
            }
        }
    }
    return 1;
}
