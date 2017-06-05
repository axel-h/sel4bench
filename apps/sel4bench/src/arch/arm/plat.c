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
#include "../../env.h"
#include <sel4platsupport/device.h>
#include <sel4platsupport/plat/timer.h>

int arch_init_timer_irq_cap(env_t *env, cspacepath_t *path)
{
    return sel4platsupport_copy_irq_cap(&env->vka, &env->simple, DEFAULT_TIMER_INTERRUPT, path);
}
