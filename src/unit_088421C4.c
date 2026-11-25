/* unit_088421C4: 0x088421C4-0x088423E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088421C4 (ULES01213)
 *
 * Optimized for speed (the search loop is entered without a jump to its test).
 * `(x != 0) ^ 1` keeps the sltu/xori/bnezl test of the search loop.
 * The colour is a 4-byte union with a float member: copied with lwc1/swc1.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

typedef union {
    f32 f;
    struct {
        u8 r, g, b, a;
    } c;
} Color;

typedef struct {
    char pad[0x548];
    s16 unk_548[4];
    u8 unk_550[4];
} Obj;

typedef struct {
    char pad[0x1E6];
    u16 unk_1E6;
} Ctx;

extern u16 D_0893AC08[];
extern s8 D_0893B5AC[];
extern Color D_0893AA5C[];

extern u32 func_088DAEA8(Ctx *);
extern s32 func_0882A9DC(Obj *, u16, u16, s32);
extern void func_0882B624(Obj *, u16, u16, s32, s32, s32, s32, s32);

void func_088421C4(Obj *arg0, Ctx *arg1, u16 arg2, u16 arg3) {
    u32 mask;
    s32 i;
    s32 n;
    s32 k;
    u16 t;
    Color c;

    mask = func_088DAEA8(arg1);
    if (mask != 0) {
        n = arg0->unk_548[arg1->unk_1E6];
        if (n < 0) {
            for (i = 0; i < 19; i++) {
                if (((mask & (1 << i)) != 0) ^ 1) {
                    continue;
                }
                arg0->unk_550[arg1->unk_1E6] = i;
                arg0->unk_548[arg1->unk_1E6] = 20;
                break;
            }
        } else {
            if ((mask & (1 << arg0->unk_550[arg1->unk_1E6])) != 0 && n > 0) {
                arg0->unk_548[arg1->unk_1E6] = n - 1;
            } else {
                n = 19;
                do {
                    arg0->unk_550[arg1->unk_1E6]++;
                    if (arg0->unk_550[arg1->unk_1E6] >= 19) {
                        arg0->unk_550[arg1->unk_1E6] = 0;
                    }
                    if ((mask & (1 << arg0->unk_550[arg1->unk_1E6])) != 0) {
                        arg0->unk_548[arg1->unk_1E6] = 20;
                        break;
                    }
                    n--;
                } while (n > 0);
            }
        }
        k = arg0->unk_550[arg1->unk_1E6];
        t = D_0893AC08[k];
        if (t != 0x1E5) {
            func_0882A9DC(arg0, arg2 + 0x78, arg3, t);
        } else {
            k -= 14;
            c = D_0893AA5C[D_0893B5AC[k]];
            func_0882B624(arg0, arg2 + 0x78, arg3, c.c.r, c.c.g, c.c.b, t, 0);
        }
    } else {
        arg0->unk_548[arg1->unk_1E6] = -1;
    }
}
