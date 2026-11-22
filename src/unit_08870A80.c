/* unit_08870A80: 0x08870A80-0x08870AC4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 type;
    s16 a;
    s16 b;
    u16 c;
    s32 pad;
} Msg;

extern s32 D_09A1DAEC;
extern void func_088AB514(s32, s32, Msg *);

void func_08870A80(s32 arg0, char *arg1, char *arg2) {
    Msg m;

    m.type = 8;
    m.a = 0;
    m.b = *(s16 *)(arg1 + 0x2C);
    m.c = *(u16 *)(arg2 + 0x29A);
    func_088AB514(D_09A1DAEC, 6, &m);
}
