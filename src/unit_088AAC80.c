/* unit_088AAC80: 0x088AAC80-0x088AAD58 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088AA9B4 and func_088AAD58
 * (NonMatching, in assembly).
 *
 * Receives on a socket of func_088AA370 / func_088AA83C (inet, or PTP in
 * ad hoc mode). Errors go through func_088AA14C; a closed connection is
 * reported as an error, "would block" as 0 bytes.
 */

/* The original keeps the blocks that delay-slot filling leaves dead and
 * branches each `return` straight to the epilogue: conditional rebuilding
 * off (notes/MATCHING.md). */
#pragma opt_rebuildconditionals off

typedef short s16;
typedef int s32;

extern s32 sceNetInetRecv(s32, void *, s32, s32);
extern s32 sceNetInetGetPspError(void);
extern s32 sceNetAdhocPtpRecv(s32, void *, s32 *, s32, s32);
extern s32 func_088AA14C(s32);
extern s32 D_09A1D728;

s32 func_088AAC80(s32 sock, void *buf, s16 len) {
    s32 n;
    s32 ret;
    s32 err;

    if (D_09A1D728 != 1) {
        ret = sceNetInetRecv(sock, buf, len, 0);
        if (ret < 0) {
            err = sceNetInetGetPspError();
            if (err == 0x8001000B) {
                return 0;
            }
            return func_088AA14C(err);
        }
        if (ret == 0) {
            return func_088AA14C(0x80010068);
        }
        return ret;
    }
    n = len;
    ret = sceNetAdhocPtpRecv(sock, buf, &n, 0, 1);
    if (ret == 0x80410709) {
        return 0;
    }
    ret = func_088AA14C(ret);
    if (ret < 0) {
        return ret;
    }
    return n;
}
