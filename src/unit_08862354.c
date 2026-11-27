/* unit_08862354: 0x08862354-0x088623DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;

extern s32 D_089CBFFC;
extern void func_0884CDE4(s32, char *);

void func_08862354(float *arg0, float *arg1) {
    float s[16];
    float out[16];
    float *ps = s;
    float *po;
    float z = arg1[2];
    float y = arg1[1];
    float x = arg1[0];
    asm {
        vmidt.q E000
        sv.q C000, 0x0(ps)
        sv.q C010, 0x10(ps)
        sv.q C020, 0x20(ps)
        sv.q C030, 0x30(ps)
    }
    s[0] = x;
    s[5] = y;
    s[10] = z;
    po = out;
    asm {
        lv.q C100, 0x0(ps)
        lv.q C110, 0x10(ps)
        lv.q C120, 0x20(ps)
        lv.q C130, 0x30(ps)
        lv.q C200, 0x0(arg0)
        lv.q C210, 0x10(arg0)
        lv.q C220, 0x20(arg0)
        lv.q C230, 0x30(arg0)
        vmmul.q E000, E100, E200
        sv.q C000, 0x0(po)
        sv.q C010, 0x10(po)
        sv.q C020, 0x20(po)
        sv.q C030, 0x30(po)
    }
    func_0884CDE4(D_089CBFFC, (char *)out);
}
