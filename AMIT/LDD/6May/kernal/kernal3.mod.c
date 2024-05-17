#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x12d79137, "kernel_kobj" },
	{ 0xdffb829d, "kobject_create_and_add" },
	{ 0xcafc467a, "sysfs_create_file_ns" },
	{ 0x1c0dd58c, "kobject_put" },
	{ 0x72512c15, "sysfs_remove_file_ns" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6ab589bc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FAB8FFC25E5F9DB8C9E7486");
