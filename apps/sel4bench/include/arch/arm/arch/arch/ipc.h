/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(NICTA_GPL)
 */
#ifndef __ARCH_IPC_H
#define __ARCH_IPC_H

#include <armv/ipc.h>

#define READ_COUNTER_BEFORE READ_COUNTER
#define READ_COUNTER_AFTER  READ_COUNTER

#define DO_CALL(ep, tag, swi) do { \
    register seL4_Word dest asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1") = tag; \
    register seL4_Word scno asm("r7") = seL4_SysCall; \
    asm volatile(NOPS swi NOPS \
        : "+r"(dest), "+r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysCall), "r"(scno) \
    ); \
} while(0)

#define DO_CALL_10(ep, tag, swi) do { \
    register seL4_Word dest asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1") = tag; \
    register seL4_Word scno asm("r7") = seL4_SysCall; \
    asm volatile(NOPS swi NOPS \
        : "+r"(dest), "+r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysCall), "r"(scno) \
        : "r2", "r3", "r4", "r5" \
    ); \
} while(0)

#define DO_SEND(ep, tag, swi) do { \
    register seL4_Word dest asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1") = tag; \
    register seL4_Word scno asm("r7") = seL4_SysSend; \
    asm volatile(NOPS swi NOPS \
        : "+r"(dest), "+r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysSend), "r"(scno) \
    ); \
} while(0)

#define DO_REPLY_WAIT_10(ep, tag, swi) do { \
    register seL4_Word src asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1") = tag; \
    register seL4_Word scno asm("r7") = seL4_SysReplyWait; \
    asm volatile(NOPS swi NOPS \
        : "+r"(src), "+r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysReplyWait), "r"(scno) \
        : "r2", "r3", "r4", "r5" \
    ); \
} while(0)

#define DO_REPLY_WAIT(ep, tag, swi) do { \
    register seL4_Word src asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1") = tag; \
    register seL4_Word scno asm("r7") = seL4_SysReplyWait; \
    asm volatile(NOPS swi NOPS \
        : "+r"(src), "+r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysReplyWait), "r"(scno) \
    ); \
} while(0)

#define DO_WAIT(ep, swi) do { \
    register seL4_Word src asm("r0") = (seL4_Word)ep; \
    register seL4_MessageInfo_t info asm("r1"); \
    register seL4_Word scno asm("r7") = seL4_SysWait; \
    asm volatile(NOPS swi NOPS \
        : "+r"(src), "=r"(info) \
        : [swi_num] "i" __SWINUM(seL4_SysWait), "r"(scno) \
    ); \
} while(0)

#define DO_REAL_CALL(ep, tag) DO_CALL(ep, tag, "swi %[swi_num]")
#define DO_NOP_CALL(ep, tag) DO_CALL(ep, tag, "nop")
#define DO_REAL_REPLY_WAIT(ep, tag) DO_REPLY_WAIT(ep, tag, "swi %[swi_num]")
#define DO_NOP_REPLY_WAIT(ep, tag) DO_REPLY_WAIT(ep, tag, "nop")
#define DO_REAL_CALL_10(ep, tag) DO_CALL_10(ep, tag, "swi %[swi_num]")
#define DO_NOP_CALL_10(ep, tag) DO_CALL_10(ep, tag, "nop")
#define DO_REAL_REPLY_WAIT_10(ep, tag) DO_REPLY_WAIT_10(ep, tag, "swi %[swi_num]")
#define DO_NOP_REPLY_WAIT_10(ep, tag) DO_REPLY_WAIT_10(ep, tag, "nop")
#define DO_REAL_SEND(ep, tag) DO_SEND(ep, tag, "swi %[swi_num]")
#define DO_NOP_SEND(ep, tag) DO_SEND(ep, tag, "nop")
#define DO_REAL_WAIT(ep) DO_WAIT(ep, "swi %[swi_num]")
#define DO_NOP_WAIT(ep) DO_WAIT(ep, "nop")

#endif /* __ARCH_IPC_H */