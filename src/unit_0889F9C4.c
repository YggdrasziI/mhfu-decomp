/* unit_0889F9C4: 0x0889F9C4-0x0889FB94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit code and a function still in
 * assembly. Its jump table (0x08931EE8-0x08931F20) is linked from this unit.
 * The handlers are declared with one message type here; their units name
 * the parameter differently.
 */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    s32 unk0;
    char unk4[0x3C];
} Msg;

extern char D_089B2374;
extern char D_089B237C;
extern char D_089B2384;
extern s32 D_09A0B564;
extern s32 D_09A0B568;
extern int func_0880D9EC(char *, ...);
extern s32 func_0889F1CC(s32, Msg *);
extern void func_0889FB94(void);
extern void func_088A0958(void);
extern void func_088A0BF4(void);
extern void func_088A0BFC(Msg *);
extern void func_088A0C10(Msg *);
extern void func_088A0C74(Msg *);
extern void func_088A0D70(Msg *);
extern void func_088A0DB0(Msg *);
extern void func_088A0DB8(Msg *);
extern void func_088A10E0(Msg *);
extern void func_088A10E8(Msg *);
extern void func_088A10F0(Msg *);
extern void func_088A10F8(Msg *);
extern void func_088A11F0(Msg *);
extern int sceKernelCpuResumeIntr(s32);
extern s32 sceKernelCpuSuspendIntr(void);

s32 func_0889F9C4(void) {
    Msg msg;
    s32 ret;
    s32 temp_a0;
    s32 temp_v1;
    u32 i;

    i = 0;
    func_088A0958();
    func_0889FB94();
    do {
        temp_a0 = D_09A0B564;
        D_09A0B564 = temp_a0 + 1;
        if (temp_a0 == 0) {
            D_09A0B568 = sceKernelCpuSuspendIntr();
        }
        ret = func_0889F1CC(0, &msg);
        if (D_09A0B564 != 0) {
            temp_v1 = D_09A0B564 - 1;
            D_09A0B564 = temp_v1;
            if (temp_v1 == 0) {
                sceKernelCpuResumeIntr(D_09A0B568);
            }
        }
        if (ret < 0) {
            break;
        }
        switch (msg.unk0) {
        case 0x10000009:
            func_088A0BFC(&msg);
            break;
        case 0x1000000A:
            func_088A0C10(&msg);
            break;
        case 0x1000000B:
            func_088A0C74(&msg);
            break;
        case 0x1000000C:
            func_088A0D70(&msg);
            break;
        case 0x10000007:
            func_088A0DB0(&msg);
            break;
        case 0x10000000:
            func_088A0DB8(&msg);
            break;
        case 0x10000001:
            func_088A10E0(&msg);
            break;
        case 0x10000002:
            func_088A10E8(&msg);
            break;
        case 0x10000003:
            func_088A10F0(&msg);
            break;
        case 0x10000004:
            func_088A10F8(&msg);
            break;
        case 0x1000000D:
            func_088A0BF4();
            break;
        case 0x10000006:
            func_088A11F0(&msg);
            break;
        case 0x10000008:
            break;
        default:
            func_0880D9EC(&D_089B2374);
            func_0880D9EC(&D_089B237C);
            func_0880D9EC(&D_089B2384, msg.unk0);
            break;
        }
        i++;
    } while (i < 0x40);
    return 0;
}
