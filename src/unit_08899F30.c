/* unit_08899F30: 0x08899F30-0x08899FBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    u8 b[2];
} U2;

typedef struct {
    B6 a;
    U2 b;
} Rec;

extern s32 func_0889CE10(char *, Rec *);
extern void func_088B3DE4(s32, void (*)(void *), char *);
extern void func_0889A828(void *);

void func_08899F30(char *arg0, Rec *arg1) {
    *(s32 *) (arg0 + 0x12C0) |= 0x200;
    func_088B3DE4(func_0889CE10(arg0, arg1), func_0889A828, arg0);
    ((Rec *) (arg0 + 0x12C8))->a = arg1->a;
    ((Rec *) (arg0 + 0x12C8))->b = arg1->b;
}
