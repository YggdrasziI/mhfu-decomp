/* unit_08899E80: 0x08899E80-0x08899F30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

typedef struct {
    s8 v[6];
} Six;

typedef struct {
    u8 a;
    u8 b;
} UPair;

typedef struct {
    Six p;
    UPair u;
    char pad[100 - 8];
} Entry;

typedef struct {
    char pad0[0x12C0];
    s32 flags;
    char pad1[4];
    Six p;
    UPair u;
    char pad2[0x12DC - 0x12D0];
    Entry e[1];
} Obj;

extern void func_088B3DE4(Entry *, void *, Obj *);
extern void func_0889A828(void *);

Six *func_08899E80(Obj *arg0, u8 arg1) {
    arg0->flags |= 0x200;
    func_088B3DE4(&arg0->e[arg1], func_0889A828, arg0);
    arg0->p = arg0->e[arg1].p;
    arg0->u = arg0->e[arg1].u;
    return &arg0->p;
}
