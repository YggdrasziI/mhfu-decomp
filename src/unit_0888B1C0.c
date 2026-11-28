/* unit_0888B1C0: 0x0888B1C0-0x0888B600 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0888B1C0: command list interpreter; one VFPU asm block
 * (notes/COMPILER.md, "VFPU in asm blocks"). */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef float f32;

#define B(p, o) (*(s8 *)((char *)(p) + (o)))
#define UB(p, o) (*(u8 *)((char *)(p) + (o)))
#define H(p, o) (*(s16 *)((char *)(p) + (o)))
#define W(p, o) (*(s32 *)((char *)(p) + (o)))
#define F(p, o) (*(f32 *)((char *)(p) + (o)))
#define P(p, o) (*(char **)((char *)(p) + (o)))

extern void func_0888E788(char *, char *, char *);
extern void func_0888E8E8(char *, char *, char *);
extern void func_0888EA44(char *, s8);
extern void func_0888EAF8(char *, char *);

typedef struct {
    char pad0[0x94];
    s16 rem;
    s16 count;
} Obj;

static inline void copy_q(char *src, char *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

s32 func_0888B1C0(char *arg0) {
    char *cmd;
    char *wcmd;
    char *st;
    s32 result;
    char *cur;
    s32 running;

    cur = P(arg0, 0xE0);
    st = arg0 + 0xA0;
    running = 1;
    UB(arg0, 0x139) = 0;
    do {
        wcmd = cur;
        cmd = cur;
        cur += B(cmd, 1) * 4;
        switch (B(cmd, 0)) {
        case 0:
            B(st, 0x48) = B(cmd, 2);
            break;
        case 1:
            B(st, 0x49) = B(cmd, 2);
            B(st, 0x4B) = B(cmd, 3);
            break;
        case 2:
            func_0888E788(arg0, st, wcmd);
            break;
        case 3:
            func_0888E788(arg0, st + 0x10, wcmd);
            break;
        case 4:
            B(st, 0x4A) = B(cmd, 2);
            B(st, 0x4C) = B(cmd, 3);
            break;
        case 5:
            func_0888E8E8(arg0, st + 0x20, wcmd);
            break;
        case 6:
            func_0888E8E8(arg0, st + 0x30, wcmd);
            break;
        case 7:
            B(st, 0x4D) = B(cmd, 2);
            break;
        case 8:
            H(st, 0x5C) = H(cmd, 2);
            break;
        case 9:
            H(st, 0x60) = H(cmd, 2);
            break;
        case 10:
            H(st, 0x5E) = H(cmd, 2);
            break;
        case 11:
            H(st, 0x62) = H(cmd, 2);
            break;
        case 12:
            F(st, 0x54) = 0.0625f * (f32)W(wcmd, 4);
            break;
        case 13:
            F(st, 0x58) = 0.0625f * (f32)W(wcmd, 4);
            break;
        case 14:
            H(st, 0x64) = H(cmd, 2);
            break;
        case 15:
            H(st, 0x66) = H(cmd, 2);
            break;
        case 16:
            H(st, 0x68) = H(cmd, 2);
            break;
        case 17:
            H(st, 0x6A) = H(cmd, 2);
            break;
        case 18:
            H(arg0, 0x94) = H(arg0, 0x96) = H(cmd, 2);
            break;
        case 19:
            H(st, 0x6C) = H(cmd, 2);
            break;
        case 20:
            H(st, 0x6E) = H(cmd, 2);
            break;
        case 21:
            H(st, 0x70) = H(cmd, 2);
            break;
        case 22:
            H(st, 0x72) = H(cmd, 2);
            break;
        case 23:
            H(st, 0x74) = H(cmd, 2);
            break;
        case 24:
            H(st, 0x76) = H(cmd, 2);
            break;
        case 25:
            H(st, 0x78) = H(cmd, 2);
            break;
        case 26:
            H(st, 0x7A) = H(cmd, 2);
            break;
        case 27:
            H(st, 0x7C) = H(cmd, 2);
            break;
        case 28:
            H(st, 0x7E) = H(cmd, 2);
            break;
        case 29:
            H(st, 0x80) = H(cmd, 2);
            break;
        case 30:
            H(st, 0x82) = H(cmd, 2);
            break;
        case 31:
            H(st, 0x84) = H(cmd, 2);
            break;
        case 32:
            H(st, 0x86) = H(cmd, 2);
            break;
        case 33:
            H(st, 0x88) = H(cmd, 2);
            break;
        case 34:
            H(st, 0x8A) = H(cmd, 2);
            break;
        case 35:
            B(st + B(cmd, 2), 0x8C) = B(cmd, 3);
            break;
        case 36:
            func_0888EA44(arg0, B(cmd, 2));
            break;
        case 37:
            UB(st, 0x98) = (H(cmd, 2) >> 14) & 3;
            F(st, 0x94) = 0.0009765625f * (f32)(H(cmd, 2) & 0x3FFF);
            break;
        case 38:
            H(arg0, 0x94) = H(arg0, 0x96) = H(cmd, 2);
            P(st, 0x44) = cur;
            break;
        case 39:
            if (B(cmd, 2) != 0) {
                func_0888EAF8(arg0, wcmd);
            }
            H(arg0, 0x94) = H(arg0, 0x94) - 1;
            if (((Obj *)arg0)->count <= 0 || ((Obj *)arg0)->rem >= 0) {
                cur = P(st, 0x44);
                running = 0;
                result = 0;
            } else {
                copy_q(arg0, st);
                copy_q(arg0 + 0x10, st + 0x20);
                H(st, 0x5C) = H(st, 0x60);
                H(st, 0x5E) = H(st, 0x62);
                H(st, 0x64) = H(st, 0x66);
                H(st, 0x68) = H(st, 0x6A);
                H(st, 0x6E) = 0;
                H(st, 0x76) = 0;
                H(st, 0x7E) = 0;
                H(st, 0x86) = 0;
                H(st, 0x70) = H(st, 0x72);
                H(st, 0x78) = H(st, 0x7A);
                H(st, 0x80) = H(st, 0x82);
                H(st, 0x88) = H(st, 0x8A);
                UB(st, 0x98) = 0;
                F(st, 0x94) = 1.0f;
                H(arg0, 0x96) = H(arg0, 0x94) = -1;
            }
            break;
        case 40:
            func_0888EAF8(arg0, wcmd);
            break;
        case 43:
            UB(st, 0x9B) = 1;
            break;
        case 45:
            P(st, 0x90) = cur;
            break;
        case 44:
            if (P(st, 0x90) != 0) {
                cur = P(st, 0x90);
            }
            break;
        default:
        case 41:
            return 1;
        case 42:
            running = 0;
            result = -1;
            break;
        }
        if (UB(st, 0x99) != 0) {
            return 1;
        }
        P(st, 0x40) = cur;
    } while (running);
    return result;
}
