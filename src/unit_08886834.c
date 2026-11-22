/* unit_08886834: 0x08886834-0x08886850 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function; reads the first word of a
 * 0x18-byte record and tail-calls func_088A232C.
 */

typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4[5];
} Rec18;

extern void func_088A232C(s32, s32);

void func_08886834(Rec18 *arg0, s32 arg1, s32 arg2) {
    func_088A232C(arg0[arg1].unk0, arg2);
}
