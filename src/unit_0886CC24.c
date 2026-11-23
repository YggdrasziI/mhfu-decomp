/* unit_0886CC24: 0x0886CC24-0x0886CDF8 (ULES01213)
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

typedef struct {
    float x, y, z, w;
    u16 type;
    u16 count;
    u16 kind;
    u16 pad16;
    u16 v18;
    u8 v1A;
    u8 pad1B;
    s16 v1C;
    u16 pad1E;
} Ent;

extern char *D_09A4F060;
extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_08A631A0;
extern void func_0886D024(void *);
extern char *func_088DCEBC(s32, u8);
extern s32 func_088D6A1C(char *, s32);
extern s32 func_088D6A54(char *, s32);
extern u16 func_088900C4(char *, s32);
extern void func_0886D248(void *, s8);

s32 func_0886CC24(void *arg0, Ent *arg1, float *arg2) {
    Ent *e;
    s32 i;
    char *p;
    s32 flag;

    e = (Ent *)(D_09A4F060 + 4);
    func_0886D024(arg0);
    for (i = 0; i < 20; i++, e++) {
        if (e->type == 0xFFFF) {
            if (arg2 == 0) {
                e->x = arg1->x;
                e->y = arg1->y;
                e->z = arg1->z;
            } else {
                e->x = arg2[0];
                e->y = arg2[1];
                e->z = arg2[2];
            }
            e->w = arg1->w;
            e->type = arg1->type;
            e->count = arg1->count;
            e->kind = arg1->kind;
            e->v18 = arg1->v18;
            e->v1A = arg1->v1A;
            e->v1C = arg1->v1C;
            if (e->kind == 2) {
                p = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
                if (func_088D6A1C(p, 0xB0) != 0) {
                    e->count++;
                }
                flag = 0;
                if (func_088D6A54(p, 1) != 0) {
                    if ((func_088900C4(D_08A631A0, 0) & 1) == 0) {
                        flag = 1;
                    }
                }
                if (func_088D6A54(p, 2) != 0) {
                    if ((func_088900C4(D_08A631A0, 0) & 3) == 0) {
                        flag = 1;
                    }
                }
                if (flag) {
                    e->count++;
                }
            }
            func_0886D248(arg0, i);
            return i;
        }
    }
    return -1;
}
