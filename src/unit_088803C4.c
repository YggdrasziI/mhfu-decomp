/* unit_088803C4: 0x088803C4-0x088803FC (ULES01213)
 *
 * Bounds (hypothesis): small setters between unrelated code. Field and global
 * names are not known.
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x15C];
    char unk15C[0xC];
    int unk168;
    char pad16C[0x8];
    u16 unk174;
    u16 unk176;
    u16 unk178;
    u16 unk17A;
} Obj;

extern int D_089B24D8;
extern int D_09A0DA8C;
extern void func_0889EA8C(void *p);

void func_088803C4(Obj *o, u16 a, u16 b, u16 c) {
    o->unk174 = a;
    o->unk176 = b;
    o->unk178 = c;
    o->unk17A = c;
}

void func_088803D8(Obj *o, int v) {
    o->unk168 = v;
    func_0889EA8C(o->unk15C);
}

void func_088803E4(void *unused, int v) { D_089B24D8 = v; }
void func_088803F0(void *unused, int v) { D_09A0DA8C = v; }
