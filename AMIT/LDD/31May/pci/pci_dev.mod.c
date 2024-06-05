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
	{ 0x122c3a7e, "_printk" },
	{ 0xb55ef4e9, "pci_unregister_driver" },
	{ 0xc5d61c97, "pci_enable_device" },
	{ 0x38f3e73f, "pci_request_regions" },
	{ 0x90f7aeb2, "pci_iomap" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x7b695bdf, "pci_iounmap" },
	{ 0xea6f0800, "pci_release_regions" },
	{ 0x50e6d0f5, "pci_disable_device" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcee81a5f, "__pci_register_driver" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x2fa5cadd, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00001234d00005678sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "DA9B670E23A7A3D82E93362");
