/* unit_088B09D0: 0x088B09D0-0x088B0A58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B09A4 and unit_088B0A58.
 *
 * When func_088B04B4 accepts arg0, runs request 0xC for it (func_088AE718,
 * reply dropped) and sends event 0 with arg2 / arg3; otherwise sends event
 * 0x8000. Returns 0.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[0x14];
} Id;

extern s32 func_088B04B4(char *);
extern void func_088AE718(Id *, char *, s32);
extern void func_088B6A08(s32, s32, s32);

s32 func_088B09D0(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Id id;

    if (!func_088B04B4(arg0)) {
        func_088B6A08(0x8000, arg2, arg3);
        return 0;
    }
    func_088AE718(&id, arg0, arg1);
    func_088B6A08(0, arg2, arg3);
    return 0;
}
