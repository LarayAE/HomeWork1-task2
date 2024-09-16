#include <linux/module.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alex L.");

static int __init hello_init(void)
{
    int r_num = 0;
    get_random_bytes(&r_num, sizeof(r_num));

    printk(KERN_ALERT "'task2' module started\n");
    printk(KERN_ALERT "'task2' random: %d\n", r_num);
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_ALERT "'task2' module exited\n");
    return;
}

module_init(hello_init);
module_exit(hello_exit);

