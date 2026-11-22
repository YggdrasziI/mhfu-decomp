/* unit_0889E47C: 0x0889E47C-0x0889E508 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
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
} Id;

typedef struct {
    s8 active;
    char pad1[3];
    s32 value;
    char pad8[0x18 - 8];
    Six p;
    UPair u;
    s32 state;
} Rec;

extern int func_0889E440(char *);

void func_0889E47C(Rec *arg0, Id *arg1, s32 arg2) {
    func_0889E440((char *)arg0);
    arg0->active = 1;
    arg0->value = arg2;
    arg0->p = arg1->p;
    arg0->u = arg1->u;
    arg0->state = 1;
}
