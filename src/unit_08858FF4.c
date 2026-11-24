/* unit_08858FF4: 0x08858FF4-0x088590B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08858FF4: display and GE initialisation. */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    s32 signal_func;
    s32 signal_arg;
    void *finish_func;
    s32 finish_arg;
} GeCallbackData;

extern int sceDisplaySetMode(s32, s32, s32);
extern int sceGeEdramSetAddrTranslation(s32);
extern s32 sceGeListEnQueue(char *, s32, s32, s32);
extern int sceGeListSync(s32, s32);
extern int sceGeSetCallback(GeCallbackData *);
extern int func_088592E4(char *);
extern void func_08859224(char *);
extern void func_08859768(void);
extern char D_0899CD94;
extern u8 D_08A62C45;

void func_08858FF4(char *arg0) {
    GeCallbackData cb;

    sceDisplaySetMode(0, 0x1E0, 0x110);
    sceGeEdramSetAddrTranslation(0x400);
    *(s32 *)(arg0 + 4) = 0;
    func_088592E4(arg0);
    sceGeListSync(sceGeListEnQueue(&D_0899CD94, 0, -1, 0), 0);
    cb.finish_func = func_08859768;
    cb.signal_func = 0;
    cb.signal_arg = 0;
    cb.finish_arg = 0;
    *(s32 *)(arg0 + 0x8019C) = sceGeSetCallback(&cb);
    func_08859224(arg0);
    func_088592E4(arg0);
    D_08A62C45 = 1;
    *(u8 *)(arg0 + 0x801A0) = 0;
}
