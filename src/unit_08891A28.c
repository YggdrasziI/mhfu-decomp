/* unit_08891A28: 0x08891A28-0x08891B14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x50];
} Elem50;

typedef struct {
    u8 pad0[0x134];
    u8 unk134[6];          /* 0x134 */
    u8 unk13A[6];          /* 0x13A */
    s32 unk140[6];         /* 0x140 */
    u8 pad158[0x15D - 0x158];
    u8 unk15D;             /* 0x15D */
    u8 pad15E[0x22B18 - 0x15E];
    Elem50 unk22B18[6];    /* 0x22B18 */
} Obj;

extern void func_08892FB0(Obj *);
extern void func_0889377C(Obj *, s32);
extern int func_08894988(Obj *);
extern void func_08892A88(Obj *, Elem50 *, s32, s32);
extern void func_088930A0(Obj *);

void func_08891A28(Obj *arg0, s8 arg1) {
    s32 idx;
    s32 ptr;
    s32 i;
    s32 count;

    idx = arg1;
    if (idx >= 0 && idx < 6) {
        count = arg0->unk134[idx];
        if (count != 0) {
            arg0->unk15D = arg1;
            func_08892FB0(arg0);
            ptr = arg0->unk140[idx];
            for (i = 0; i < (u8)count; i++) {
                func_0889377C(arg0, ptr);
                ptr += 0xC;
            }
        }
        count = arg0->unk13A[idx];
        if (count != 0) {
            func_08892A88(arg0, &arg0->unk22B18[idx], count, func_08894988(arg0));
            func_088930A0(arg0);
        }
    }
}
