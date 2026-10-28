// SPDX-License-Identifier: GPL-2.0-only
#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>
#include "hello1.h"

MODULE_AUTHOR("Vlad");
MODULE_DESCRIPTION("Hello dependent module with parameter");
MODULE_LICENSE("GPL");

static uint count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of times to print Hello, world!");

static int __init hello2_init(void)
{
        int ret;

        pr_info("Module hello2 loaded with count=%u\n", count);
        ret = print_hello(count);
        if (ret)
                return ret;

        return 0;
}

static void __exit hello2_exit(void)
{
        pr_info("Module hello2 unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
