/* unit_088269C0: 0x088269C0-0x08826EEC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual call.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct VA0_0 {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C();
    virtual u8 vfunc_A0();
} VA0_0;

extern "C" {

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern VA0_0 **D_09A4F060;
extern s32 D_08A62C7C;
extern u8 D_0899D19D[];
extern char *func_088DCEBC(s32, u8);
extern u8 func_09A6FA00(char *, u16);
extern u8 func_09A6E5A8(char *);
extern u8 func_09A6EE30(char *);
extern u8 func_09A6EE40(char *, u16);
extern u8 func_09A6F308(char *);
extern u8 func_09A70210(char *);
extern u8 func_09A70220(char *, u16);
extern s16 func_09A6EDE0(char *);
extern u8 func_09A6F278(char *, s32);
extern u8 func_09A6F2E0(char *);
extern u8 func_088DA168(char *);
extern u8 func_09A6F138(char *);
extern u8 func_09A6F098(char *, s32);
extern u8 func_09A6F310(char *, s32);
extern u8 func_08852A44(char *);
extern u16 func_09A6F390(char *, s16 *, char *);
extern u8 func_09A6FC88(char *);
extern u8 func_08869504(s32);
extern u8 func_09A6FDC8(char *);
extern s32 func_08865C88(char *, s32);

u8 func_088269C0(char *arg0, u16 arg1) {
    char *p;
    u8 r;
    s16 kind;
    char buf[0x1E];
    char *q;

    p = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    r = func_09A6FA00(p, arg1);
    if (func_09A6E5A8(p) == 1) {
        return r;
    }
    if ((s32)(*(u8 *)(p + 0x1E0) != 0) == 1) {
        return 0;
    }
    if (r == 1) {
        return 0;
    }
    if (func_09A6EE30(p) == 1) {
        if (func_09A6EE40(p, arg1) == 1) {
            return 0;
        }
    }
    if (*(u8 *)(p + 0x29C) == 1) {
        if (arg1 == 0x5A) {
            return func_09A6F308(p);
        }
        return 0;
    }
    if (func_09A70210(p) == 1) {
        if (func_09A70220(p, arg1) == 1) {
            return 0;
        }
    }
    switch (arg1) {
    case 0x4E:
    case 0x367:
        if (func_09A6EDE0(p) >= 0) {
            break;
        }
        return 0;
    case 0x4F:
    case 0x364:
        return func_09A6F278(p, 1);
    case 0x50:
        return func_09A6F2E0(p);
    case 0x97:
    case 0x362:
    case 0x98:
        return func_088DA168(p);
    case 0x99:
    case 0x363:
    case 0xE5:
        if (*(u8 *)(p + 0x5F3) == 1) {
            return 0;
        }
        break;
    case 0x54:
    case 0x55:
    case 0x58:
    case 0x59:
        return func_09A6F138(p);
    case 0x56:
    case 0x57:
    case 0x368:
    case 0x5C:
        return func_09A6F098(p, 1);
    case 0x5B:
        return func_09A6F310(p, 1);
    case 0x5A:
        if (*(u8 *)(p + 0x29C) != 1) {
            return 0;
        }
        if (func_09A6F308(p) == 1) {
            break;
        }
        return 0;
    case 0x2B:
    case 0x2C:
    case 0x2E:
    case 0x2D:
        return func_08852A44(D_089CC438);
    case 0x90:
    case 0x91:
    case 0x92:
    case 0x4C9:
        if (func_09A6F390(p, &kind, buf) == 0xFFFF) {
            return 0;
        }
        if (kind == 3) {
            break;
        }
        return 0;
    case 0x94:
    case 0x95:
    case 0x96:
    case 0x4CA:
        if (func_09A6F390(p, &kind, buf) == 0xFFFF) {
            return 0;
        }
        if (kind == 4) {
            break;
        }
        return 0;
    case 0x369:
        return func_09A6FC88(p);
    case 0x48:
        return func_08869504(D_08A62C7C);
    case 0x9A:
        return (*D_09A4F060)->vfunc_A0();
    case 0x4EC:
        return func_09A6FDC8(p);
    default:
        if (D_0899D19D[arg1 * 24] == 4) {
            if (func_08865C88(p, 0x80000) == 0) {
                q = *(char **)(p + 0x554);
                if (q == 0) {
                    return 0;
                }
                if (*(u16 *)(q + 2) == 0x17) {
                    break;
                }
                return 0;
            }
        }
        break;
    }
    return 1;
}

}
