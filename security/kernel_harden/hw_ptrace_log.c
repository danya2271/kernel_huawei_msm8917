/*
 * Huawei Kernel Harden, ptrace log upload
 *
 * Copyright (c) 2016 Huawei.
 *
 * Authors:
 * yinyouzhan <yinyouzhan@huawei.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/capability.h>
#include <linux/export.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/pagemap.h>
#include <linux/ptrace.h>
#include <linux/security.h>
#include <linux/signal.h>
#include <linux/uio.h>
#include <linux/audit.h>
#include <linux/pid_namespace.h>
#include <huawei_platform/log/imonitor.h>

#define PTRACE_POKE_STATE_IMONITOR_ID     (940000005)
static int ptrace_do_upload_log(long type, const char * child_cmdline, const char * tracer_cmdline)
{
	return 0;
}
int record_ptrace_info_before_return_EIO(long request, struct task_struct *child)
{
	return 0;
}