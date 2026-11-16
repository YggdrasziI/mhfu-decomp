/* unit_088DED1C: 0x088DED1C-0x088DEE1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two functions still in assembly.
 * Its jump table (0x089324BC-0x089324E8) is linked from this unit.
 *
 * The states 200-210, the message code 20 with the state as its parameter and
 * the three tables of functions have the shape of jpeg_consume_input() of the
 * IJG JPEG library (hypothesis: no string of the binary names it here).
 */

typedef int s32;

typedef struct Obj Obj;

typedef struct {
    void (*unk0)(Obj *);
    s32 unk4[4];
    s32 unk14;
    s32 unk18;
} Err;

typedef struct {
    s32 unk0[2];
    void (*unk8)(Obj *);
} Src;

typedef struct {
    s32 (*unk0)(Obj *);
    void (*unk4)(Obj *);
} Ctl;

struct Obj {
    Err *unk0;
    s32 unk4[4];
    s32 unk14;
    Src *unk18;
    char unk1C[0x174];
    Ctl *unk190;
};

extern void func_088DEA1C(Obj *);

s32 func_088DED1C(Obj *arg0) {
    s32 ret = 0;

    switch (arg0->unk14) {
    case 200:
        arg0->unk190->unk4(arg0);
        arg0->unk18->unk8(arg0);
        arg0->unk14 = 201;
    case 201:
        ret = arg0->unk190->unk0(arg0);
        if (ret == 1) {
            func_088DEA1C(arg0);
            arg0->unk14 = 202;
        }
        break;
    case 202:
        ret = 1;
        break;
    case 203:
    case 204:
    case 205:
    case 206:
    case 207:
    case 208:
    case 210:
        ret = arg0->unk190->unk0(arg0);
        break;
    default:
        arg0->unk0->unk14 = 20;
        arg0->unk0->unk18 = arg0->unk14;
        arg0->unk0->unk0(arg0);
    }
    return ret;
}
