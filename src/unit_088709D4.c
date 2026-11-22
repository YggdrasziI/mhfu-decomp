/* unit_088709D4: 0x088709D4-0x08870A2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 12-byte message block built on the stack (only the first 8 bytes are set). */
typedef struct {
    u8 type;
    s16 zero;
    u16 hi;
    u16 lo;
    s32 unk8;
} Msg;

extern char *D_089CC438;
extern s32 D_09A1DAEC;

extern void func_088AB514(s32, s32, char *);

void func_088709D4(char *arg0) {
    Msg m;

    if ((u8) D_089CC438[0x422] != 0) {
        return;
    }
    m.type = 5;
    m.zero = 0;
    {
        s32 v = *(s32 *) (arg0 + 0x10);
        m.lo = v;
        m.hi = (u32) v >> 16;
    }
    func_088AB514(D_09A1DAEC, 6, (char *) &m);
}
