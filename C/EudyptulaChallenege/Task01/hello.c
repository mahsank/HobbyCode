/* A simple [Hello, World] module */
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("e24d7413dd77");
MODULE_DESCRIPTION("A simple hello world module.");
MODULE_VERSION("0.1");

static int __init hello_init(void) {
	printk(KERN_DEBUG "Hello, World!\n");
        return 0;
}

static void __exit hello_exit(void) {
	printk(KERN_DEBUG "Removing [Hello, World] module gracefully!\n");
}

module_init(hello_init);
module_exit(hello_exit);
