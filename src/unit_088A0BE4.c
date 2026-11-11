/* unit_088A0BE4: 0x088A0BE4-0x088A0C10 (ULES01213)
 *
 * Bounds (hypothesis): three forwarders and a flag setter between unrelated code.
 * Parameters of the forwarders other than the first are not known.
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x8];
    u8 unk8;
} Msg;

extern int D_09A0D13C;
extern void func_088A0AFC();
extern void func_088A1200();

void func_088A0BE4(char *p) { func_088A0AFC(p + 0x100); }
void func_088A0BEC(void) { func_088A1200(); }
void func_088A0BF4(void) { func_088A1200(); }
void func_088A0BFC(Msg *m) { D_09A0D13C = m->unk8 & 1; }
