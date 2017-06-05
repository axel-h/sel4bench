/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
   * @TAG(DATA61_BSD)
   */
#ifndef __BENCHMARK_SUPPORT_H
#define __BENCHMARK_SUPPORT_H

#include <sel4utils/slab.h>
#include <simple/arch/simple.h>

void benchmark_arch_get_simple(arch_simple_t *simple);
void benchmark_arch_get_timers(env_t *env);

#endif /* __BENCHMARK_SUPPORT_H */
