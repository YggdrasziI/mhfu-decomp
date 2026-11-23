/* unit_0886C8AC: 0x0886C8AC-0x0886C914 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct {
    u8 type;
    u8 pad;
    s16 zero;
    s16 item;
    s16 count;
    s16 pad2[2];
} Msg;

extern char *D_09A1DAEC;
extern char *D_089CBBEC;
extern s16 func_0886C768(char *, s32, s32);
extern void func_088AB514(char *, s32, Msg *);
extern u8 func_08830728(char *, s8, s16, s16);

void func_0886C8AC(char *arg0, s32 arg1) {
    Msg msg;
    s16 id;

    msg.type = 9;
    msg.item = arg1;
    id = arg1;
    id = (s16)id;
    msg.zero = 0;
    msg.count = func_0886C768(arg0, arg1, 1);
    func_088AB514(D_09A1DAEC, 6, &msg);
    func_08830728(D_089CBBEC, 1, 8, id);
}
