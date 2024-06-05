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
	{ 0xed5f63e2, "dma_unmap_sg_attrs" },
	{ 0x1a194a4f, "dma_free_attrs" },
	{ 0x50e6d0f5, "pci_disable_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xb55ef4e9, "pci_unregister_driver" },
	{ 0xb88db70c, "kmalloc_caches" },
	{ 0x4454730e, "kmalloc_trace" },
	{ 0xc5d61c97, "pci_enable_device" },
	{ 0x2bd1e17f, "dma_alloc_attrs" },
	{ 0x2cf0c910, "sg_init_table" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa8b39343, "dma_map_sg_attrs" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5981fc21, "_dev_err" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcee81a5f, "__pci_register_driver" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x2fa5cadd, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d*sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "39D5C5D901507974B39D5E8");
