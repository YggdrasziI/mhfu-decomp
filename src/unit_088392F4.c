/* unit_088392F4: 0x088392F4-0x08839688 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_09CFB898;
extern char *D_08A631A8;
extern s32 D_09B23A98;
extern char *D_089CC438;
extern s32 D_09CFBBC8;
extern char *D_089CBBE4;
extern u16 D_09B05300[];
extern s32 D_09B22D70;

extern s32 func_09C1C108(s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_09ADC408(s32, s32);
extern void func_08814674(char *, float *, float *);
extern char *func_09A7B790(s32, u16);
extern s32 func_08890E48(char *, char *);
extern void func_0889198C(char *, s32, s32, s32, s32, char *, s32, s32);

static inline void mtx_identity(float *dst) {
    asm {
        vmidt.q E000
        sv.q C000, 0(dst)
        sv.q C010, 0x10(dst)
        sv.q C020, 0x20(dst)
        sv.q C030, 0x30(dst)
    }
}

static inline void vec_set(float *dst, float x, float y, float z, float w) {
    float *px = &x;
    float *py = &y;
    float *pz = &z;
    float *pw = &w;
    asm {
        lv.s S000, 0(px)
        lv.s S001, 0(py)
        lv.s S002, 0(pz)
        lv.s S003, 0(pw)
        sv.q C000, 0(dst)
    }
}

void func_088392F4(char *arg0, char *arg1) {
    float mtx[16] __attribute__((aligned(16)));
    float in[4] __attribute__((aligned(16)));
    float out[4] __attribute__((aligned(16)));
    char *obj;
    char *rec;
    char *str;
    s32 col;
    s32 i;
    s16 w;

    if (func_09C1C108(D_09CFB898) != 0) {
        return;
    }
    func_08890DE8(D_08A631A8, 0xC, 0xC);
    i = 0;
    do {
        obj = func_09ADC408(D_09B23A98, i);
        if (obj == 0) {
            goto next;
        }
        if ((s32)((*(s32 *)(obj + 4) & 1) != 0) != 1) {
            goto next;
        }
        if (*(u8 *)(obj + 0x480) == 0x1C) {
            rec = D_089CC438 + *(u16 *)(obj + 0x1E6) * 0x70 + 0x696FC;
        } else if (*(u8 *)(obj + 0x480) == 0x20) {
            if (*(u8 *)(arg0 + 0x1190) != 0) {
                rec = (char *)D_09CFBBC8 + *(u16 *)(obj + 0x1E6) * 0x70;
            } else {
                rec = D_089CC438 + *(u16 *)(obj + 0x1E6) * 0x70 + 0x69BEC;
            }
        } else {
            goto next;
        }
        mtx_identity(mtx);
        vec_set(in, *(float *)(obj + 0x200), 110.0f + *(float *)(obj + 0x204), *(float *)(obj + 0x208), 0.0f);
        func_08814674(D_089CBBE4, out, in);
        if (out[2] < 0.0f) {
            goto next;
        }
        if ((u32)out[2] > 0xFFFF) {
            goto next;
        }
        if (*(u8 *)(obj + 0x480) == 0x1C) {
            s8 v = *(s8 *)(rec + 3);
            if (v >= 9) col = 2;
            else if (v >= 7) col = 7;
            else if (v >= 4) col = 6;
            else col = 5;
        } else {
            u8 v = *(u8 *)(rec + 0x16);
            if (v >= 15) col = 2;
            else if (v >= 10) col = 7;
            else if (v >= 5) col = 6;
            else col = 5;
        }
        str = func_09A7B790(D_09B22D70, D_09B05300[*(u8 *)(rec + 1)]);
        w = func_08890E48(D_08A631A8, str) * 3;
        func_0889198C(D_08A631A8, (s16)((u16)(u32)out[0] - w), (s16)(u32)out[1], 1, (s8)col, str, 1, 1);
    next:
        i++;
    } while (i < 20);
}
