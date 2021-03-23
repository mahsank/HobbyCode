// SPDX-License-Identifier: GPL-2.0
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("e24d7413dd77");
MODULE_DESCRIPTION("A simple hello world module.");
MODULE_VERSION("0.1");

static int __init hello_init(void)
{
	pr_debug("Hello, World!\n");
	return 0;
}

static void __exit hello_exit(void)
{
	pr_debug("Removing [Hello, World] module gracefully!\n");
}

module_init(hello_init);
module_exit(hello_exit);
