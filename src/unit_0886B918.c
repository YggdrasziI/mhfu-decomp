/* unit_0886B918: 0x0886B918-0x0886BA50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 a;
    u8 b;
} Ent;

typedef struct {
    u8 type;
    u8 pad;
    s16 x;
    s16 y;
    s16 z;
    s32 w;
} Msg;

extern Ent *D_089A800C[];
extern char *D_08A631A0;
extern char *D_089CC438;
extern u16 D_089AC5B2;
extern char *D_089CBBEC;
extern s32 D_08A62D8C;
extern s32 D_09A1DAEC;

extern u16 func_088900C4(char *, s32);
extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_088AB514(s32, s32, Msg *);

void func_0886B918(char *arg0) {
    Ent *e;
    Ent *tbl;
    s8 idx;
    Msg msg;

    tbl = D_089A800C[*(s8 *)(arg0 + 0x131)];
    switch (*(s8 *)(arg0 + 0x12D)) {
    case 1:
        idx = *(s8 *)(arg0 + 0x130);
        e = &tbl[idx];
        if (e->a * 1800 < *(s32 *)(arg0 + 0x10)) {
            break;
        }
        *(s8 *)(arg0 + 0x130) = idx + 1;
        if ((func_088900C4(D_08A631A0, 0) & 0x7F) < e->b) {
            *(s8 *)(arg0 + 0x12D) = 0;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B2));
            func_08883988(D_08A62D8C, 1, 0x77, 0, 0, 0, 0, 0, 0);
            msg.type = 0xE;
            msg.x = 0;
            msg.y = 0;
            msg.z = 0;
            func_088AB514(D_09A1DAEC, 6, &msg);
        }
        break;
    case 0:
        break;
    }
}
