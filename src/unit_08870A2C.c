/* unit_08870A2C: 0x08870A2C-0x08870A80 (ULES01213)
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
    s16 zero;
    s16 val;
    u16 flags;
    s32 pad;
} Msg;

extern s32 D_09A1DAEC;

extern void func_088AB514(s32, s32, void *);

void func_08870A2C(s32 arg0, char *arg1, char *arg2) {
    Msg m;

    m.type = 7;
    m.zero = 0;
    m.val = *(s16 *)(arg1 + 0x2C);
    m.flags = *(u16 *)(arg2 + 0x29A) | (u16)(*(s8 *)(arg1 + 4) << 8);
    func_088AB514(D_09A1DAEC, 6, &m);
}
