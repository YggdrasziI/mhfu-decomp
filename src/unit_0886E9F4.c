/* unit_0886E9F4: 0x0886E9F4-0x0886F65C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 *
 * Command-list interpreter (role is a hypothesis).
 *
 * Optimized for speed: divisions by a constant are multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 op;
    s16 arg;
    s16 arg2;
    s16 arg3;
} Cmd;

typedef struct {
    s32 time;
    s32 unk4;
} TimeEntry;

typedef struct {
    u8 kind;
    s16 a;
    s16 b;
    s16 c;
    s32 unk8;
} Msg;

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_089CBBE4;
extern char *D_09A1DAEC;
extern char *D_09C121B0;
extern TimeEntry D_089A77C4[];
extern u16 D_089AC5A0[];
extern u16 D_089AC5A8;
extern u16 D_089AC5AC;
extern u16 D_089AC5AE;
extern u16 D_089AC5B0;

extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08830850(char *, char *);
extern void func_0886DFAC(char *, s32);
extern void func_088709D4(char *);
extern s32 func_0886E6A8(char *);
extern void func_0886E000(char *, s32, s32, s32);
extern s32 func_0886E828(char *, s32);
extern void func_088307BC(char *, char *);
extern s16 func_0886E060(char *, s32);
extern s32 func_08870194(char *);
extern s32 func_0887276C(char *, s32);
extern void func_0886F65C(char *, char *);
extern void func_088AB514(char *, s32, Msg *);
extern s32 func_08865CB8(char *, s32, s32);
extern u8 func_08830728(char *, s8, s16, s16);
extern s32 func_0886A35C(char *, s32);
extern void func_0886BBE4(char *);
extern s32 func_0887019C(char *, Cmd *);
extern s32 func_09AC88F0(s32);
extern void func_0886E0D8(char *, u16, s32);
extern s16 func_0886E008(char *, s32);
extern s32 func_0886F78C(char *);
extern s32 func_08872B40(char *);
extern void func_08813594(char *, s32);

static inline s32 get_entry(char *base, s32 i) {
    if (i < 0 || i >= 20) {
        return 0;
    }
    return *(s32 *)(i * 4 + base + 0x1220);
}

s16 func_0886E9F4(char *arg0, char *arg1, s16 pc) {
    char buf[0x80];
    Msg msg;
    Cmd *cmd;
    s32 t;
    s32 n;
    s32 i;
    s32 e;
    Cmd *q;
    char *s;
    u8 *f;

    if (*(u8 *)(D_089CC438 + 0x2E) == 2) {
        t = *(s32 *)(arg0 + 0x10);
        if (t >= 0) {
            n = *(s8 *)(arg0 + 0x83);
            if (n > 0) {
                s32 v = D_089A77C4[n].time;
                if (v >= t) {
                    s = func_0885151C(D_089CC438, D_089AC5A8);
                    func_0880E8F0(buf, s, v / 1800);
                    buf[0x7F] = 0;
                    func_08830850(D_089CBBEC, buf);
                    *(s8 *)(arg0 + 0x83) -= 1;
                }
            }
            func_0886DFAC(arg0, 1);
            t = *(s32 *)(arg0 + 0x10);
            if (t <= 0) {
                q = *(Cmd **)(arg0 + 0x54);
                pc = 0;
                *(s32 *)(arg0 + 0x10) = 0;
                func_088709D4(arg0);
                *(s32 *)(arg0 + 0x10) = -1;
                for (;;) {
                    if (q->op == 0x1A && *(s8 *)(arg0 + 8) == q->arg) {
                        pc++;
                        break;
                    }
                    q++;
                    pc++;
                }
            } else if (t % 9000 == 0) {
                func_088709D4(arg0);
            }
        }
    }

    while (1) {
        if (*(s8 *)(arg0 + 9) != 0) {
            if (func_0886E6A8(arg0) != 0) {
                q = *(Cmd **)(arg0 + 0x54);
                pc = 0;
                for (;;) {
                    if (q->op == 0x1A && *(s8 *)(arg0 + 9) == q->arg) {
                        pc++;
                        break;
                    }
                    q++;
                    pc++;
                }
                *(s8 *)(arg0 + 9) = 0;
            }
        }
        if ((n = *(s8 *)(arg0 + 0x117)) != 0) {
            if (*(s8 *)(arg0 + 0x11C) != 0) {
                q = *(Cmd **)(arg0 + 0x54);
                pc = 0;
                for (;;) {
                    if (q->op == 0x1A && n == q->arg) {
                        pc++;
                        break;
                    }
                    q++;
                    pc++;
                }
                *(s8 *)(arg0 + 0x117) = 0;
            }
        }
        cmd = *(Cmd **)(arg0 + 0x54) + pc;
        switch (cmd->op) {
        case 1:
            *(s8 *)(arg0 + 0x67C) = cmd->arg;
            pc++;
            continue;
        case 2:
            func_0886E000(arg0, cmd->arg, cmd->arg2, cmd->arg3);
            pc++;
            continue;
        case 3:
            if (func_0886E828(arg0, 1) == 0) {
                break;
            }
            pc++;
            continue;
        case 9:
            *(s32 *)(arg0 + 0xC) = cmd->arg;
            pc++;
            break;
        case 0xA:
            if (--*(s32 *)(arg0 + 0xC) <= 0) {
                pc++;
            }
            break;
        case 0xB:
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5A0[cmd->arg]));
            pc++;
            break;
        case 5:
            pc++;
            continue;
        case 6:
            if (func_0886E828(arg0, 0) != 0) {
                pc++;
                continue;
            }
            pc++;
            cmd++;
            for (;;) {
                if (cmd->op == 7) {
                    pc++;
                    break;
                }
                cmd++;
                pc++;
            }
            continue;
        case 0x24:
            if (func_0886E060(arg0, *(u8 *)&cmd->arg) > cmd->arg2) {
                break;
            }
            pc++;
            continue;
        case 0xC:
            if (func_08870194(arg0) == 0) {
                pc = *(s16 *)(arg0 + 0x1E);
                break;
            }
            if (*(u16 *)(arg1 + 0x29A) != cmd->arg) {
                break;
            }
            pc++;
            continue;
        case 4:
            *(s32 *)(arg0 + 0x10) += (u16)cmd->arg;
            pc++;
            break;
        case -1:
            s = *(char **)(arg0 + 0x720);
            if (s != 0 && (u8)func_0887276C(arg0, *(u8 *)(s + 0x1E8)) != 0xFF) {
                *(s16 *)(arg0 + 0x114) = *(s16 *)(s + 0x2E4);
                *(u8 *)(arg0 + *(u8 *)(s + 0x1E8) + 0x5C2) = *(u16 *)(s + 0x774);
                func_0886F65C(arg0, s);
            }
            *(u8 *)(D_089CC438 + 0xC) = 0x81;
            *(s8 *)(arg0 + 6) = 3;
            *(u8 *)(D_089CC438 + 0x2E) = 3;
            pc++;
            *(s32 *)(arg0 + 0x110) |= 1 << (*(u8 *)(D_089CC438 + 0x28) + 8);
            msg.kind = 2;
            msg.a = 0;
            msg.b = 0;
            msg.c = 0;
            func_088AB514(D_09A1DAEC, 6, &msg);
            continue;
        case 0x2D:
            if ((*(s32 *)(arg0 + 0x110) & 0xF00) != 0xF00) {
                u8 *h = (u8 *)D_089CC438;
                if ((u8)(h[h[0x28] * 0x8C + 0x30] != 0) != 0) {
                    break;
                }
            }
            pc++;
            break;
        case 0x1E:
            pc = -1;
            *(s8 *)(arg0 + 0) += 1;
            *(s8 *)(arg0 + 1) = 0;
            break;
        case 0x18:
            if ((u8)func_08865CB8(arg1, 4, 0) == 0) {
                break;
            }
            pc++;
            continue;
        case -2:
            *(u8 *)(D_089CC438 + 0x2E) = 5;
            pc++;
            *(s8 *)(arg0 + 6) = 5;
            msg.kind = 4;
            msg.a = 0;
            msg.b = 0;
            msg.c = 0;
            func_088AB514(D_09A1DAEC, 6, &msg);
            continue;
        case 0x1F:
            *(u8 *)(D_089CC438 + 0x2E) = 6;
            *(s8 *)(arg0 + 6) = 6;
            pc = -1;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5AC));
            if ((s32)((*(u32 *)(D_089CC438 + 0x6AF14) & 4) != 0) == 1) {
                break;
            }
            func_08830728(D_089CBBEC, 0, 0xF, 0);
            break;
        case 0x1B:
            *(s8 *)(arg0 + 8) = cmd->arg;
            s = func_0885151C(D_089CC438, D_089AC5AE);
            func_0880E8F0(buf, s, func_0886A35C(arg0, 1) / 1800);
            buf[0x7F] = 0;
            func_08830850(D_089CBBEC, buf);
            pc++;
            break;
        case 0x20:
            *(u8 *)(arg0 + 0x20) = (u16)cmd->arg;
            func_0886BBE4(arg0);
            pc++;
            continue;
        case 0x21:
            if (func_0887019C(arg0, cmd) == 0) {
                break;
            }
            pc++;
            continue;
        case 0x23:
            *(s8 *)(arg0 + 9) = cmd->arg;
            pc++;
            break;
        case 0x2C:
            *(s8 *)(arg0 + 0x117) = cmd->arg;
            pc++;
            break;
        case 0x25:
            *(u8 *)(D_089CC438 + 0x2E) = 5;
            pc++;
            *(s8 *)(arg0 + 6) = 5;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B0));
            msg.kind = 0xA;
            msg.a = 0;
            msg.b = 0;
            msg.c = 0;
            func_088AB514(D_09A1DAEC, 6, &msg);
            continue;
        case 0x26:
            s = *(char **)(arg0 + 0x720);
            if (s != 0 && (u8)func_0887276C(arg0, *(u8 *)(s + 0x1E8)) != 0xFF) {
                *(s16 *)(arg0 + 0x114) = *(s16 *)(s + 0x2E4);
                *(u8 *)(arg0 + *(u8 *)(s + 0x1E8) + 0x5C2) = *(u16 *)(s + 0x774);
                func_0886F65C(arg0, s);
            }
            *(s8 *)(arg0 + 6) = 3;
            *(u8 *)(D_089CC438 + 0x2E) = 3;
            pc++;
            *(s32 *)(arg0 + 0x110) |= 1 << (*(u8 *)(D_089CC438 + 0x28) + 8);
            msg.kind = 0xB;
            msg.a = 0;
            msg.b = 0;
            msg.c = 0;
            func_088AB514(D_09A1DAEC, 6, &msg);
            continue;
        case 0x28:
            s = *(char **)(arg0 + 0x720);
            if (*(s16 *)(s + 0x2E4) <= *(s16 *)(arg0 + 0x114) - cmd->arg) {
                *(s16 *)(arg0 + 0x114) = *(s16 *)(s + 0x2E4);
                pc++;
                continue;
            }
            pc++;
            cmd++;
            for (;;) {
                if (cmd->op == 0x29) {
                    pc++;
                    break;
                }
                cmd++;
                pc++;
            }
            continue;
        case 0x2A:
            for (i = 0; i < 20; i++) {
                e = get_entry(D_09C121B0, i);
                if (e != 0) {
                    break;
                }
            }
            if ((u8)func_09AC88F0(e) == 1) {
                func_0886E0D8(arg0, 0, 0x200);
                pc++;
                continue;
            }
            pc++;
            cmd++;
            for (;;) {
                if (cmd->op == 0x2B) {
                    pc++;
                    break;
                }
                cmd++;
                pc++;
            }
            continue;
        case 0x1C:
            n = cmd->arg;
            q = *(Cmd **)(arg0 + 0x54);
            pc = 0;
            for (;;) {
                if (q->op == 0x1A && n == q->arg) {
                    pc++;
                    break;
                }
                q++;
                pc++;
            }
            continue;
        case 0x27:
            break;
        case 0x1A:
            pc++;
            continue;
        case 0x2F:
            *(s8 *)(arg0 + 8) = cmd->arg;
            pc++;
            break;
        case 0x30:
            if (func_0886E008(arg0, (u16)cmd->arg) <= cmd->arg2) {
                n = cmd->arg3;
                q = *(Cmd **)(arg0 + 0x54);
                pc = 0;
                for (;;) {
                    if (q->op == 0x1A && n == q->arg) {
                        pc++;
                        break;
                    }
                    q++;
                    pc++;
                }
                continue;
            }
            pc++;
            continue;
        case 0x31:
            pc++;
            continue;
        case 0x32:
            pc++;
            continue;
        case 0x33:
            break;
        case 0x34:
            func_0886E0D8(arg0, 0, 0);
            pc++;
            continue;
        case 0x35:
            if (func_0886F78C(arg0) >= cmd->arg) {
                pc++;
                continue;
            }
            pc++;
            cmd++;
            for (;;) {
                if (cmd->op == 0x36) {
                    pc++;
                    break;
                }
                cmd++;
                pc++;
            }
            continue;
        case 0x37:
            if (*(s8 *)(arg0 + 0x12D) == cmd->arg) {
                pc++;
                continue;
            }
            pc++;
            cmd++;
            for (;;) {
                if (cmd->op == 0x38) {
                    pc++;
                    break;
                }
                cmd++;
                pc++;
            }
            continue;
        case 0x39:
            if (func_0886E828(arg0, 1) != 0 || func_08872B40(arg0) == 0) {
                pc++;
                continue;
            }
            break;
        }
        break;
    }

    f = (u8 *)(D_089CC438 + 0xC);
    if (*f == 0x80) {
        *f = 0;
        func_08813594(D_089CBBE4, 0);
    }
    return pc;
}
