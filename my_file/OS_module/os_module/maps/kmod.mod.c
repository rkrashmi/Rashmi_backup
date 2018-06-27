#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x45025b96, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x49ea3a35, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x9b6cf309, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d262ffd, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x1a5adb30, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x1aad8fcf, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x6ef49f64, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0xbf2b863f, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x598f94f2, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xf2cf653c, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x2543dc80, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "420CABBBB3A4063CBD13A19");
