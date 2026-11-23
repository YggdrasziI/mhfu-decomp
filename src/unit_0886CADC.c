/* unit_0886CADC: 0x0886CADC-0x0886CC24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    f32 pos[3];
    char pad0C[0x12 - 0xC];
    u16 unk12;
    char pad14[0x1C - 0x14];
    s16 timer;
} Ent;

extern char *D_09A4F060;
extern s8 D_08A62C9C[];
extern void func_0886CE10(char *, s32);
extern void func_09C6F4B8(f32 *, s32, f32);

void func_0886CADC(char *arg0) {
    s32 i;
    Ent *e;
    f32 v[4];

    for (i = 0; i < *(s8 *)(arg0 + 0x21); i++) {
        e = (Ent *)(D_09A4F060 + D_08A62C9C[i] * 32 + 4);
        if (*(u16 *)((char *)e + 0x10) == 0xFFFF) {
            continue;
        }
        if (e->timer == 0) {
            continue;
        }
        if (e->unk12 <= 0 || --e->timer <= 0) {
            func_0886CE10(arg0, D_08A62C9C[i]);
        } else if ((e->timer & 0x3F) == 0) {
            v[0] = e->pos[0];
            v[1] = 20.0f + e->pos[1];
            v[2] = e->pos[2];
            func_09C6F4B8(v, 0x15, e->timer < 900 ? 0.2f + 0.3f * (e->timer / 900.0f) : 0.5f);
        }
    }
}
