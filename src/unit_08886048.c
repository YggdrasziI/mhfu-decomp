/* unit_08886048: 0x08886048-0x088860A0 (ULES01213)
 *
 * Bounds (hypothesis): a run of field getters and setters on one structure; the
 * functions around are larger and unrelated. Field names are not known.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x8];
    u16 unk8;
    char padA[0x2];
    u16 unkC;
    char padE[0x2];
    int unk10;
    char pad14[0x4];
    u8 unk18;
    char pad19[0x3];
    u16 unk1C[1];
} Obj;

u16 func_08886048(Obj *o) { return o->unkC; }
u16 func_08886050(Obj *o, u16 i) { return o->unk1C[i]; }
int func_08886064(Obj *o) { return o->unk10; }
u16 func_0888606C(Obj *o) { return o->unk8; }
void func_08886074(Obj *o, u16 v) { o->unk8 = v; }
int func_0888607C(Obj *o, u16 v) { return o->unkC == v; }
u8 func_08886090(Obj *o) { return o->unk18; }
void func_08886098(Obj *o, u8 v) { o->unk18 = v; }
