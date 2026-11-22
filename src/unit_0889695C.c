/* unit_0889695C: 0x0889695C-0x08896A50 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s16 id;
    u16 level;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} Entry;

extern char *D_089CC438;
extern u8 func_0884FB38(char *, s32);
extern int func_0884FAC4(char *, s32);

s32 func_0889695C(signed char *arg0, Entry *p) {
    for (; p->id >= 0; p++) {
        if (p->level >= arg0[0x1111]) {
            if (p->level == arg0[0x1111] && func_0884FB38(D_089CC438, p->id) != 1) {
                func_0884FAC4(D_089CC438, p->id);
                arg0[0x1113] = p->unk4;
                if (p->unk5 > 0) {
                    func_0884FAC4(D_089CC438, p->unk5 + 100);
                }
                if (p->unk6 > 0) {
                    func_0884FAC4(D_089CC438, p->unk6 + 100);
                }
                if (p->unk7 > 0) {
                    func_0884FAC4(D_089CC438, p->unk7 + 100);
                }
                return 1;
            }
            break;
        }
    }
    return 0;
}
